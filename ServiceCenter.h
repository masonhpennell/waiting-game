#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include <string>
#include <iostream>
#include "Office.h"
#include "Customer.h"
#include "ListQueue.h"

using namespace std;

class ServiceCenter{
    public:
        ServiceCenter(int* windows);
        virtual ~ServiceCenter();
        void addCustomer(Customer* c);
        void tickTime();
        bool finished();
        void results();
    private:
        ListQueue<Customer*>* customers;
        int m_time;
        Office* registrar;
        Office* cashier;
        Office* financialAid;
};

#endif