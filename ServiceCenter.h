#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include "Office.h"

using namespace std;

class ServiceCenter{
    public:
        ServiceCenter(int rWindows, int cWindows, int fWindows);
        virtual ~ServiceCenter();
    private:
        int m_time;
        Office* registrar;
        Office* cashier;
        Office* financialAid;
};

#endif