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
    int clockTick;
    int numStudents;
    int tickLine = 3;
    int studentLine = 4;
    char pos;
    string line;
    while (getline(inFile, line)) {
        if(!line.empty()){
            if (line.length() < 3){
                if (i < 3){
                    m_windows[i] = stod(line);
                }
                else if (i == tickLine){
                    clockTick = stod(line);
                }
                else if (i == studentLine){
                    numStudents = stod(line);
                    tickLine += numStudents + 1;
                    studentLine += numStudents + 1;
                }
                i++;
                cout << line << endl;
            }
            else{
                Customer* c = new Customer(clockTick);
                int times[3];
                char offices[3];
                int j = 0;
                while ((pos = line.find(" ")) != string::npos) {
                    if (j < 3){
                        times[j] = stod(line.substr(0, pos));
                        cout << times[j] << endl;
                        line.erase(0, pos + 1);
                    }
                    else{
                        string s = line.substr(0, pos);
                        offices[j-3] = s.at(0);
                        cout << offices[j-3] << endl;
                        line.erase(0, pos + 1);
                    }
                    j++;
                }
                for (int a = 0; a < 3; a++)
                    c->addTask(times[a], offices[a]);
                if (sc = NULL)
                    sc = new ServiceCenter(m_windows);
                sc->addCustomer(c);
            }
        }
    }
    inFile.close();
}