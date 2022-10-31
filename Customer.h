/*
Mason Pennell, Timothy Pieschala
2370867 (Tim's ID)
pennell@chapman.edu, pieschala@chapman.edu
CPSC 350-01
Programming Assignment 4: The Waiting Game

A customer has two different queues with times and offices to enter,
as well as a time the student enters the first office.
After each office, each queue has one value removed.
*/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ListQueue.h"
using namespace std;

class Customer{
    public:
        Customer(int enterTime);
        virtual ~Customer();
        void addTask(int time, char office);
        void finishTask();
        int getTime();
        int getOffice();
        int getEnterTime();
    private:
        ListQueue<int>* m_todoQueueTime;
        ListQueue<char>* m_todoQueueOffice;
        int m_enterTime;
};

#endif