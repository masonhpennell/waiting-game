#include "Office.h"

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

Office::~Office(){
    for(int i = 0; i < m_numWindows; i++){
        delete m_windowArr[i];
    }
}

void Office::addCustomer(Customer* cust, int time){
    cust->getEnterTime() = time;
    m_customerQueue->add(cust);
}

ListQueue<Customer*> Office::tickTime(int time){

    ListQueue<Customer*> tempQueue = ListQueue<Customer*>(); //Using ListQueue as a way to return multiple items (if more than one customer finishes at windows at a time) like a ghetto ArrayList or something
    for(int i = 0; i < m_numWindows; i++){
        Customer* temp = m_windowArr[i]->tickTime();
        if(temp != NULL){
            tempQueue.add(temp);
            if(time - temp->getEnterTime() == 10){
                m_tenWaited++;
            }

            if(time - temp->getEnterTime() > m_longestWait){
                m_longestWait = time - temp->getEnterTime();
            }
        }else{
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