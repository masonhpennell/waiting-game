#include "ServiceCenter.h"

//constructor
ServiceCenter::ServiceCenter(int* windows){
    m_time = 0;
    customers = new ListQueue<Customer*>;
    registrar = new Office(windows[0]);
    cashier = new Office(windows[1]);
    financialAid = new Office(windows[2]);
}

//destructor
ServiceCenter::~ServiceCenter(){
}

//adds a new customer to hold on to until the time comes
void ServiceCenter::addCustomer(Customer* c){
    customers->add(c);
}

//moves the time forward by one for each office
void ServiceCenter::tickTime(){
    m_time++;
    // continues checking the customers queue until it empties or the next student's enter time doesn't match the current time
    while(!customers->isEmpty() && customers->peek()->getEnterTime() == m_time){
        Customer* cust = customers->remove();
        if(cust->getOffice() == NULL){
            delete cust;
        }
        if(cust->getOffice() == 'c'){
            cashier->addCustomer(cust, m_time);
        }else if(cust->getOffice() == 'f'){
            financialAid->addCustomer(cust, m_time);
        }else if(cust->getOffice() == 'r'){
            registrar->addCustomer(cust, m_time);
        }
    }
    /*
    Each office generates a queue of students that finished their job
    Afterwards, they are moved to the next office according to their queues
    */
    ListQueue<Customer*>* cashQueue = cashier->tickTime(m_time);

    while(!cashQueue->isEmpty()){
        Customer* cust = cashQueue->remove();
        if(cust->getOffice() == NULL){
            delete cust;
        }
        if(cust->getOffice() == 'f'){
            financialAid->addCustomer(cust, m_time);
        }else if(cust->getOffice() == 'r'){
            registrar->addCustomer(cust, m_time);
        }
    }
    delete cashQueue;

    ListQueue<Customer*>* finQueue = financialAid->tickTime(m_time);

    while(!finQueue->isEmpty()){
        Customer* cust = finQueue->remove();
        if(cust->getOffice() == NULL){
            delete cust;
        }
        if(cust->getOffice() == 'c'){
            cashier->addCustomer(cust, m_time);
        }else if(cust->getOffice() == 'r'){
            registrar->addCustomer(cust, m_time);
        }
    }
    delete finQueue;

    ListQueue<Customer*>* regQueue = registrar->tickTime(m_time);

    while(!regQueue->isEmpty()){
        Customer* cust = regQueue->remove();
        if(cust->getOffice() == NULL){
            delete cust;
        }
        if(cust->getOffice() == 'c'){
            cashier->addCustomer(cust, m_time);
        }else if(cust->getOffice() == 'f'){
            financialAid->addCustomer(cust, m_time);
        }
    }
    delete regQueue;
}

//returns true if all students have been serviced
bool ServiceCenter::finished(){
    return (registrar->isEmpty() && cashier->isEmpty() && financialAid->isEmpty());

    //check if all offices and windows are empty
}

//prints the results
void ServiceCenter::results(){
    cout << "CASHIER RESULTS" << endl << cashier->results();
    cout << "REGISTRAR RESULTS" << endl << registrar->results();
    cout << "FINANCIAL AID RESULTS" << endl << financialAid->results();
}