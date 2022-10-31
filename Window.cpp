#include "Window.h"

//constructor
Window::Window(){
    m_servingCustomer = NULL;
    m_idleTime = 0;
    m_servedTimeRemaining = 0;
}

//destructor
Window::~Window(){
    if(m_servingCustomer != NULL){
        delete m_servingCustomer;
    }
}

void Window::addCustomer(Customer* c){
    m_servingCustomer = c;
    m_servedTimeRemaining = c->getTime();
    m_idleTime = 0;
}

int Window::getIdleTime(){
    return m_idleTime;
}

void Window::resetCustomer(){
    m_servingCustomer == NULL;
}

int Window::getServedTime(){
    return m_servedTimeRemaining;
}

bool Window::isIdle(){
    return m_servingCustomer == NULL;
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
            temp->finishTask();
            return temp;
        }
        return NULL;
    }
}