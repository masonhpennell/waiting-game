/*
Mason Pennell, Timothy Pieschala
2370867 (Tim's ID)
pennell@chapman.edu, pieschala@chapman.edu
CPSC 350-01
Programming Assignment 4: The Waiting Game

insert office description
*/
#ifndef OFFICE_H
#define OFFICE_H

#include "Customer.h"
#include "Window.h"
#include "ListQueue.h"
#include <string>
using namespace std;

class Office{
    public:
        Office(int windows);
        virtual ~Office();
        void addCustomer(Customer* cust, int time);
        ListQueue<Customer*> tickTime(int time);
        string results();
    private:
        int m_numWindows;
        ListQueue<Customer*>* m_customerQueue;
        int m_tenWaited;
        int m_fiveIdle;
        int m_averageWait;
        int m_longestWait;
        int m_averageIdle;
        int m_longestIdle;
        Window** m_windowArr;
    //Finish

};

#endif