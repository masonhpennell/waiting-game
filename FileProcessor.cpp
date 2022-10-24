#include "FileProcessor.h"

// Constructor
FileProcessor::FileProcessor(){
    m_windows = new int[3];
}

// Destructor
FileProcessor::~FileProcessor(){
    
}

void FileProcessor::readFile(string input){
    ifstream inFile(input);
    int i = 0;
    string line;
    while (getline(inFile, line)){
        if (line.length() == 1){
            m_windows[i] = stod(line);
            i++;
        }
        else
            break;
    }
}