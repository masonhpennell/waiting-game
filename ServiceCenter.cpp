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

//moves the time by one for each office
void ServiceCenter::tickTime(){
    m_time++;
    registrar->tickTime(m_time);
    cashier->tickTime(m_time);
    financialAid->tickTime(m_time);
}

//retursn true if all students have been serviced
bool ServiceCenter::finished(){
    //check if all offices and windows are empty
}

//prints the results
void ServiceCenter::results(){
    cout << "CASHIER RESULTS" << endl << cashier->results();
    cout << "REGISTRAR RESULTS" << endl << registrar->results();
    cout << "FINANCIAL AID RESULTS" << endl << financialAid->results();
}