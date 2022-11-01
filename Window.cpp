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

Customer* Window::getCustomer(){
    return m_servingCustomer;
}

// adds customer c to the window and resets the idle time
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

// returns true if no customer is at the window
bool Window::isIdle(){
    return m_servingCustomer == NULL;
}

// ticks the time by 1
Customer* Window::tickTime(){
    // if no customer is at the window, nothing happens
    if(m_servingCustomer == NULL){
        m_idleTime++;
        return NULL;
    }else{
        m_servedTimeRemaining--;
        // the satisfied customer is returned and their task is removed from their queue
        if(m_servedTimeRemaining == 0){
            Customer* temp = m_servingCustomer;
            m_servingCustomer = NULL;
            temp->finishTask();
            return temp;
        }
        return NULL;
    }
}