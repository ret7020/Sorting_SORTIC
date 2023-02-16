#ifndef SORTIC_H_INCLUDED
#define SORTIC_H_INCLUDED

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

using namespace std;

// Sorting functions
void sa(vector<int> &a);
void sb(vector<int> &b);
void ss(vector<int> &a, vector<int> &b);
void pa(vector<int> &a, vector <int> &b);
void pb(vector<int> &b, vector<int> &a);
void ra(vector<int> &a);
void rb(vector<int> &b);
void rr(vector<int> &a, vector<int> &b);
void rra(vector<int> &a);
void rrb(vector<int> &b);
void rrr(vector<int> &a, vector<int> &b);

// Trash
void readFromFile(ifstream &inputFromFile, vector<int> &a);
bool isSorted(vector<int> arr);
int minNumIndex(vector<int> arr);
void sorter(vector<int> &a, vector<int> &b, ofstream &outputToFile, int &numberOfIterations);
int itc_len(string str);
long long itc_toInt(string s);
void printArray(const vector<int> arr, ofstream &inputToFile);
void printStep(const vector<int> &a, const vector<int> &b, string functionName, ofstream &outputToFile);
void fileBasedArrayFill(vector<int> &a);
void multiLineArrayFill(ofstream &outputToFile, vector<int> &a);
void inlineBasedArrayFill(string inp, vector<int> &a);
void split(string str, string token, vector<int> &a); 
string colored(string text);
#endif // SORTIC_H_INCLUDED
