#include "sortic.h"


void readFromFile(ifstream &inputFromFile, vector<int> &a){
    string stringOfNumbers = "";
    string bufferStringForReading;
    for(inputFromFile >> bufferStringForReading; !inputFromFile.eof(); inputFromFile >> bufferStringForReading)
        stringOfNumbers += bufferStringForReading + " ";
    bufferStringForReading = "";
    for(long long i = 0; i < itc_len(stringOfNumbers); ++i){
        if(!(stringOfNumbers[i] >= '0' && stringOfNumbers[i] <= '9')){
            if(itc_len(bufferStringForReading) != 0)
                a.push_back(itc_toInt(bufferStringForReading));
            bufferStringForReading = "";
        }
        else
            bufferStringForReading += stringOfNumbers[i];
    }
    inputFromFile.close();
}


