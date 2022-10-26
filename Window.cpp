#include "Window.h"

Window::Window(){
    m_servingCustomer = NULL;
    m_idleTime = 0;
    m_servedTimeRemaining = 0;
}

Window::~Window(){
    if(m_servingCustomer != NULL){
        delete m_servingCustomer;
    }
}

int Window::getIdleTime(){
    return m_idleTime;
}

int Window::getServedTime(){
    return m_servedTimeRemaining;
}

Customer* Window::tickTime(){
    if(m_servingCustomer == NULL){
        m_idleTime++;
        return NULL;
    }else{
        m_servedTimeRemaining--;
        if(m_servedTimeRemaining == 0){
            Customer* temp = m_servingCustomer;
            m_servingCustomer = NULL;
            return temp;
        }
        return NULL;
    }
}