#ifndef WINDOW_H
#define WINDOW_H

#include "Customer.h"
using namespace std;

class Window{
    public:
        Window();
        virtual ~Window();
        Customer* tickTime();
        int getIdleTime();
        int getServedTime();
    private:
        Customer* m_servingCustomer;
        int m_idleTime;
        int m_servedTimeRemaining;
};



#endif