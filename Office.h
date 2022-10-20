#ifndef OFFICE_H
#define OFFICE_H

#include "Customer.h"
#include "Window.h"

using namespace std;

class Office{
    public:
        Office(int windows);
        virtual ~Office();

        Window** m_windowArr;
        int m_numWindows;
    //Finish

};

#endif OFFICE_H