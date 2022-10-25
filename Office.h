#ifndef OFFICE_H
#define OFFICE_H

#include "Customer.h"
#include "Window.h"
#include "ListQueue.h"

using namespace std;

class Office{
    public:
        Office(int windows);
        virtual ~Office();

        Window** m_windowArr;
        int m_numWindows;

        ListQueue<Customer*>* m_customerQueue;

        void addCustomer(Customer* cust, int time);

        ListQueue<Customer*> tickTime(int time);

        int m_tenWaited;
        int m_fiveIdle;
    //Finish

};

#endif OFFICE_H