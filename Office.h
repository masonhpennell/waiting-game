/*
Mason Pennell, Timothy Pieschala
2370867 (Tim's ID)
pennell@chapman.edu, pieschala@chapman.edu
CPSC 350-01
Programming Assignment 4: The Waiting Game

This office contains a number of windows, each able to serve a customer
The customer is served for however long they need the window for. When they're finished, they move to the next office
If a window is still in service, we wait.
When students arrive at the same time and visit the same office first, the first student listed is the first to get into line.
If 2 students finish at different offices at the same time and head to the same office next,
they enter the line based on alphabetical order of the office they are coming from
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
        ListQueue<Customer*>* tickTime(int time);
        string results();
        bool isEmpty();
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
};

#endif