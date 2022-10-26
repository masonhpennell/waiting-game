#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include "Office.h"
#include "Customer.h"

using namespace std;

class ServiceCenter{
    public:
        ServiceCenter(int rWindows, int cWindows, int fWindows);
        virtual ~ServiceCenter();
    private:
        Customer** customers;
        int m_time;
        Office* registrar;
        Office* cashier;
        Office* financialAid;
};

#endif