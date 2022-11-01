/*
Mason Pennell, Timothy Pieschala
2370867 (Tim's ID)
pennell@chapman.edu, pieschala@chapman.edu
CPSC 350-01
Programming Assignment 4: The Waiting Game

The Service Center holds on to the customers who are waiting for their time.
Every time the clock ticks, the students are moved to their offices.
The program is constantly checking if all offices are finished.
*/
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