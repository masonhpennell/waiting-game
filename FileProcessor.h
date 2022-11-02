/*
Mason Pennell, Timothy Pieschala
2370867 2391088
pennell@chapman.edu, pieschala@chapman.edu
CPSC 350-01
Programming Assignment 4: The Waiting Game

This program reads the input file and creates a Service Center to hold all customers.
*/
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <fstream>
#include "Customer.h"
#include "ServiceCenter.h"
using namespace std;

class FileProcessor{
    public:
        FileProcessor();
        virtual ~FileProcessor();
        ServiceCenter* readFile(string input);
    private:
        int* m_windows;
        ServiceCenter* sc;
};
#endif
