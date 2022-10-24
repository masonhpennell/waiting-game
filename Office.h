#ifndef OFFICE_H
#define OFFICE_H

#include "Customer.h"
#include "Window.h"

using namespace std;

class Office{
    public:
        Office(int windows);
        virtual ~Office();
    private:
        int m_numWindows;
        int m_averageWait;
        int m_longestWait;
        int m_averageIdle;
        int m_longestIdle;
        Window** m_windowArr;
        //finish

};

#endif