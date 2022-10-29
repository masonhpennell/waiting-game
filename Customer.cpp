#include "Customer.h"

Customer::Customer(int enterTime){
    m_todoQueueTime = new ListQueue<int>();
    m_todoQueueOffice = new ListQueue<char>();
    m_enterTime = enterTime;
}

Customer::~Customer(){
    delete m_todoQueueOffice;
    delete m_todoQueueTime;
}

void Customer::addTask(int time, char office){
    m_todoQueueTime->add(time);
    m_todoQueueOffice->add(office);
}

void Customer::finishTask(){
    m_todoQueueOffice->remove();
    m_todoQueueTime->remove();
}

int Customer::getTime(){
    return m_todoQueueTime->peek();
}

int Customer::getOffice(){
    return m_todoQueueOffice->peek();
}

int Customer::getEnterTime(){
    return m_enterTime;
}