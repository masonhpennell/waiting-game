/*
Mason Pennell, Timothy Pieschala
2370867 2391088
pennell@chapman.edu, pieschala@chapman.edu
CPSC 350-01
Programming Assignment 4: The Waiting Game

A window serves a customer and returns it when he/she is finished.
It also keeps track of how long it's gone without serving a customer or how long it has left with a customer.
*/
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
        void addCustomer(Customer* c);
        bool isIdle();
        void resetCustomer();
    private:
        Customer* m_servingCustomer;
        int m_idleTime;
        int m_servedTimeRemaining;
};

#endif