#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ListQueue.h"
using namespace std;

class Customer{
    public:
        Customer();
        virtual ~Customer();
        void addTask(int time, char office);
        ListQueue<int>* m_todoQueueTime;
        ListQueue<char>* m_todoQueueOffice;
        int m_enterTime;

};


#endif