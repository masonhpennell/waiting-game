#include "Office.h"

//constructor
Office::Office(int windows){
    Window** m_windowArr = new Window*[windows];
    m_numWindows = windows;
    for(int i = 0; i < m_numWindows; i++){
        m_windowArr[i] = new Window();
    }

    ListQueue<Customer*>* m_customerQueue = new ListQueue<Customer*>;
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

ListQueue<Customer*>* Office::tickTime(int time){

    ListQueue<Customer*>* tempQueue = new ListQueue<Customer*>(); //Using ListQueue as a way to return multiple items (if more than one customer finishes at windows at a time) like a ghetto ArrayList or something
    for(int i = 0; i < m_numWindows; i++){
        Customer* temp = m_windowArr[i]->tickTime();
        if(temp != NULL){
            tempQueue->add(temp);
            if(time - temp->getEnterTime() == 10){
                m_tenWaited++;
            }

            if(time - temp->getEnterTime() > m_longestWait){
                m_longestWait = time - temp->getEnterTime();
            }
            m_windowArr[i]->resetCustomer();
        }else if(m_windowArr[i]->isIdle()){
            if(m_windowArr[i]->getIdleTime() == 5){
                m_fiveIdle++;
            }

            if(m_windowArr[i]->getIdleTime() > m_longestIdle){
                m_longestIdle = m_windowArr[i]->getIdleTime();
            }
        }

    }
    return tempQueue;
}

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

string Office::results(){
    string s = "";
    s += "Average student wait time: " + to_string(m_averageWait) + "\n";
    s += "Longest student wait time: " + to_string(m_longestWait) + "\n";
    s += "Students that waited over 10 minutes: " + to_string(m_tenWaited) + "\n";
    s += "Average window idle time: " + to_string(m_averageIdle) + "\n";
    s += "Longest window idle time: " + to_string(m_longestIdle) + "\n";
    s += "Windows that were idle for over 5 minutes: " + to_string(m_fiveIdle) + "\n";
}