#include <iostream>
#include <string>
#include "FileProcessor.h"
using namespace std;

int main(int argc, char** argv){
    FileProcessor* fp = new FileProcessor();
    fp->readFile(argv[1]);
    return 0;
}