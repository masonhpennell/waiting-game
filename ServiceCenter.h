#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include "Office.h"
#include "Customer.h"
#include "ListQueue.h"

using namespace std;

class ServiceCenter{
    public:
        ServiceCenter(int* windows);
        virtual ~ServiceCenter();
        void addCustomer(Customer* c);
    private:
        ListQueue<Customer*>* customers;
        int m_time;
        Office* registrar;
        Office* cashier;
        Office* financialAid;
};

#endif