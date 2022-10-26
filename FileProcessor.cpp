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
    int tick = 3;
    int student = 4;
    string line;
    while (getline(inFile, line)) {
        if(!line.empty()){
            if (line.length() < 3){
                if (i < 3){
                    m_windows[i] = stod(line);
                    i++;
                }
                else if (i == tick){
                    
                }
                else{
                    
                }
            }
            else{

            }
        }
    }
    inFile.close();

    // while (getline(inFile, line) ){
    //     if (i < 3){
    //         m_windows[i] = stod(line);
    //         i++;
    //         cout << line << endl;
    //     }
    //     else{
    //         //finish
    //     }
    // }
}

int main(){
    FileProcessor* fp = new FileProcessor();
    fp->readFile("input.txt");
}