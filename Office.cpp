#include "Office.h"

//constructor
Office::Office(int windows){
    m_windowArr = new Window*[windows];
    m_numWindows = windows;
    for(int i = 0; i < m_numWindows; i++){
        m_windowArr[i] = new Window();
    }
    m_numStudents = 0;
    m_customerQueue = new ListQueue<Customer*>;
    m_tenWaited = 0;
    m_fiveIdle = 0;
    m_averageWait = 0;
    m_longestWait = 0;
    m_averageIdle = 0;
    m_longestIdle = 0;
}

//destructor
Office::~Office(){
    for(int i = 0; i < m_numWindows; i++){
        delete m_windowArr[i];
    }
    delete[] m_windowArr;
}

void Office::addCustomer(Customer* cust, int time){
    cust->m_enterTime = time;
    m_customerQueue->add(cust);
    m_numStudents++;
}

//moves the time forward by one
ListQueue<Customer*>* Office::tickTime(int time){
    ListQueue<Customer*>* tempQueue = new ListQueue<Customer*>(); //Using ListQueue as a way to return multiple items (if more than one customer finishes at windows at a time) like a ghetto ArrayList or something
    for(int i = 0; i < m_numWindows; i++){
        // temp: the customer currently at window [i]
        if(m_windowArr[i]->isIdle()){
            if(!(m_customerQueue->isEmpty()))
                m_windowArr[i]->addCustomer(m_customerQueue->remove());
        }
        Customer* temp = m_windowArr[i]->tickTime();
        // if no customer is returned, the window is still busy so nothing happens
        // if a customer IS returned, the next person in line is added
        if(temp != NULL){
            tempQueue->add(temp);
            // increments m_tenWaited if the student waited more than 10 minutes to get a window
            if(time - temp->getTime() == 10){
                m_tenWaited++;
            }
            // changes m_longestWait to the longest time a student waited
            if(time - temp->getTime() > m_longestWait){
                m_longestWait = time - temp->getEnterTime();
            }
            if(!m_customerQueue->isEmpty()){
                m_averageWait += m_customerQueue->size();
            }
            //m_windowArr[i]->resetCustomer();
        }else if(m_windowArr[i]->isIdle()){
            m_averageIdle++;
            // increments m_fiveIdle if the window was idle for over 5 minutes
            if(m_windowArr[i]->getIdleTime() == 5 && m_fiveIdle < m_numWindows){
                m_fiveIdle++;
            }
            // the longest time a window had no customer
            if(m_windowArr[i]->getIdleTime() > m_longestIdle){
                m_longestIdle = m_windowArr[i]->getIdleTime();
            }
        }
    }
    return tempQueue;
}

//prints the results
void Office::results(){
    string s = "";
    s += "Average student wait time: " + to_string(m_averageWait/m_numStudents) + "\n";
    s += "Longest student wait time: " + to_string(m_longestWait) + "\n";
    s += "Students that waited over 10 minutes: " + to_string(m_tenWaited) + "\n";
    s += "Average window idle time: " + to_string(m_averageIdle/m_numWindows) + "\n";
    s += "Longest window idle time: " + to_string(m_longestIdle) + "\n";
    s += "Windows that were idle for over 5 minutes: " + to_string(m_fiveIdle) + "\n";
    cout << s << endl;
}