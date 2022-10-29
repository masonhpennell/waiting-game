#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <iostream>
#include <fstream>
#include "Customer.h"
#include "ServiceCenter.h"
using namespace std;

class FileProcessor{
    public:
        FileProcessor();
        virtual ~FileProcessor();
        void readFile(string input);
    private:
        int* m_windows;
        ServiceCenter* sc;
};
#endif
