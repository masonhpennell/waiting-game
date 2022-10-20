#ifndef WINDOW_H
#define WINDOW_H

#include "Customer.h"
using namespace std;

class Window{
    public:
        Window();
        virtual ~Window();
        void tickTime();

        Customer* m_servingCustomer;
        int m_idleTime;
        int m_servedTimeRemaining;
};



#endif