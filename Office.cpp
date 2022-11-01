#include "Office.h"

//constructor
Office::Office(int windows){
    m_windowArr = new Window*[windows];
    m_numWindows = windows;
    for(int i = 0; i < m_numWindows; i++){
        m_windowArr[i] = new Window();
    }

    m_customerQueue = new ListQueue<Customer*>;
    int m_overtenWaited = 0;
    int m_fiveIdle = 0;
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
}

//moves the time forward by one
ListQueue<Customer*>* Office::tickTime(int time){
    cout << "office tick" << endl;
    ListQueue<Customer*>* tempQueue = new ListQueue<Customer*>(); //Using ListQueue as a way to return multiple items (if more than one customer finishes at windows at a time) like a ghetto ArrayList or something
    for(int i = 0; i < m_numWindows; i++){
        // temp: the customer currently at window [i]
        cout << "   window tick" << endl;
        cout << "   customer @ " << m_windowArr[i] << endl;
        if(m_windowArr[i]->isIdle()){
            if(!m_customerQueue->isEmpty()){
                m_windowArr[i]->addCustomer(m_customerQueue->remove());
                cout << "      moving customer to window in office" << endl;
            }
        }
        Customer* temp = m_windowArr[i]->tickTime();
        // if no customer is returned, the window is still busy so nothing happens
        // if a customer IS returned, the next person in line is added
        if(temp != NULL){
            tempQueue->add(temp);
            // increments m_tenWaited if the student waited more than 10 minutes to get a window
            if(time - temp->getEnterTime() == 10){
                m_tenWaited++;
            }
            // changes m_longestWait to the longest time a student waited
            if(time - temp->getEnterTime() > m_longestWait){
                m_longestWait = time - temp->getEnterTime();
            }
            //resets the customer 
            //m_windowArr[i]->resetCustomer();
        }else if(m_windowArr[i]->isIdle()){
            // increments m_fiveIdle if the window was idle for over 5 minutes
            if(m_windowArr[i]->getIdleTime() == 5){
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

//returns true if every window in the office is empty
bool Office::isEmpty(){
    bool empty = true;
    for(int i = 0; i < m_numWindows; i++){
        if(m_windowArr[i] != NULL){
            empty = false;

        }
    }
    if(!m_customerQueue->isEmpty()){
        empty = false;
    }
    return empty;
}

//prints the results
string Office::results(){
    string s = "";
    s += "Average student wait time: " + to_string(m_averageWait) + "\n";
    s += "Longest student wait time: " + to_string(m_longestWait) + "\n";
    s += "Students that waited over 10 minutes: " + to_string(m_tenWaited) + "\n";
    s += "Average window idle time: " + to_string(m_averageIdle) + "\n";
    s += "Longest window idle time: " + to_string(m_longestIdle) + "\n";
    s += "Windows that were idle for over 5 minutes: " + to_string(m_fiveIdle) + "\n";
}