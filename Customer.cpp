#include "Customer.h"

//customer
Customer::Customer(int enterTime){
    m_todoQueueTime = new ListQueue<int>();
    m_todoQueueOffice = new ListQueue<char>();
    m_enterTime = enterTime;
}

//destructor
Customer::~Customer(){
    delete m_todoQueueOffice;
    delete m_todoQueueTime;
}

//adds a new task to a customer with a time and office to go to
void Customer::addTask(int time, char office){
    m_todoQueueTime->add(time);
    m_todoQueueOffice->add(office);
}

//removes a task from the queue
void Customer::finishTask(){
    m_todoQueueOffice->remove();
    m_todoQueueTime->remove();
}

//returns the next time
int Customer::getTime(){
    return m_todoQueueTime->peek();
}

//returns the next office
int Customer::getOffice(){
    return m_todoQueueOffice->peek();
}

//returns the time the student enters
int Customer::getEnterTime(){
    return m_enterTime;
}