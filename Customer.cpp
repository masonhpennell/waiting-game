#include "Customer.h"

Customer::Customer(){
    m_todoQueueTime = new ListQueue<int>();
    m_todoQueueOffice = new ListQueue<char>();
}

Customer::~Customer(){
    delete m_todoQueueOffice;
    delete m_todoQueueTime;
}

void Customer::addTask(int time, char office){
    m_todoQueueTime->add(time);
    m_todoQueueOffice->add(office);
}