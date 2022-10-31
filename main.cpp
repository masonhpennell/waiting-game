#include <iostream>
#include <string>
#include "FileProcessor.h"
#include "ServiceCenter.h"
using namespace std;

int main(int argc, char** argv){
    FileProcessor* fp = new FileProcessor();
    ServiceCenter* center = fp->readFile(argv[1]);
    while (!center->finished()){
        center->tickTime();
    }
    center->results();
    return 0;
}