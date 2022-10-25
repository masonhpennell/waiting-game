#include "Office.h"

Office::Office(int windows){
    Window m_windowArr[windows];
    m_numWindows = windows;
    for(int i = 0; i < m_numWindows; i++){
        m_windowArr[i] = Window();
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
    cust->m_enterTime = time;
    m_customerQueue->add(cust);
}

ListQueue<Customer*> Office::tickTime(int time){

    ListQueue<Customer*> temp = ListQueue<Customer*>(); //Using ListQueue as a way to return multiple items (if more than one customer finishes at windows at a time) like a ghetto ArrayList or something
    for(int i = 0; i < m_numWindows; i++){
        if(m_windowArr[i]->m_servingCustomer == NULL && !m_customerQueue->isEmpty()){
            m_windowArr[i]->m_servingCustomer = m_customerQueue->remove();
            if(time - m_windowArr[i]->m_servingCustomer->m_enterTime == 10){
                m_tenWaited++;
            }
        }else if(m_windowArr[i]->m_servingCustomer == NULL){
            m_windowArr[i]->m_idleTime++;
            if(m_windowArr[i]->m_idleTime == 5){
                m_fiveIdle++;
            }
        }else{
            m_windowArr[i]->m_servedTimeRemaining--;
            if(m_windowArr[i]->m_servedTimeRemaining == 0){
                temp.add(m_windowArr[i]->m_servingCustomer);
                m_windowArr[i] = NULL;
            }
        }

    }
    return temp;
}