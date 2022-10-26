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
        void addCustomer(Customer* cust, int time);
        ListQueue<Customer*> tickTime(int time);
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