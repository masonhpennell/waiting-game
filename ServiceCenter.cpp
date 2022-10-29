#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(int* windows){
    m_time = 0;
    registrar = new Office(windows[0]);
    cashier = new Office(windows[1]);
    financialAid = new Office(windows[2]);
}

ServiceCenter::~ServiceCenter(){
}

void ServiceCenter::addCustomer(Customer* c){
    customers->add(c);
}