/*
Mason Pennell, Timothy Pieschala
2370867 (Tim's ID)
pennell@chapman.edu, pieschala@chapman.edu
CPSC 350-01
Programming Assignment 4: The Waiting Game

insert office description
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
    private:
        Customer* m_servingCustomer;
        int m_idleTime;
        int m_servedTimeRemaining;
};

#endif