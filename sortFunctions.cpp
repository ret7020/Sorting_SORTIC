#include "sortic.h"

bool isSorted(vector<int> arr){
    long long length = arr.size();
    if(length <= 1)
        return true;
    for(long long i = 0; i < length - 1; ++i){
        if(arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

int minNumIndex(vector<int> arr){
    int length = arr.size();
    if(length == 0 || length == 1)
        return 0;
    int index = 0;
    for(long long i = 1; i < length - 1; ++i){
        if(arr[i] < arr[index])
            index = i;
    }
    if(arr[length - 1] < arr[index])
        index = length - 1;
    return index;
}

void sorter(vector<int> &a, vector<int> &b, ofstream &outputToFile, int &numberOfIterations){
    int buffer;
    if(!isSorted(a)){
        while(a.size() != 0){
            buffer = minNumIndex(a);
            for(long long i = 0; i < buffer; i++){
                rra(a);
                printStep(a, b, "rra", outputToFile);
                numberOfIterations++;
            }
            pb(b, a);
            printStep(a, b, "pb", outputToFile);
            numberOfIterations++;
        }
        buffer = b.size();
        for(long long i = 0; i < buffer; i++){
            pa(a, b);
            printStep(a, b, "pb", outputToFile);
            numberOfIterations++;
        }
        cout << endl;
        printArray(a, outputToFile);
    }
    else
        printArray(a, outputToFile);
    cout << "Number of iterations: " << numberOfIterations << "\n";
    outputToFile << "Number of iterations: " << numberOfIterations;
    outputToFile.close();
}
