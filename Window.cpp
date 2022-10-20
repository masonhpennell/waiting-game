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

void Window::tickTime(){
    if(m_servingCustomer == NULL){
        m_idleTime++;
    }else{
        m_servedTimeRemaining--;
    }
}