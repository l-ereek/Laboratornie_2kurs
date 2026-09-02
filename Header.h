#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

struct TRAIN {
    string NAZN; 
    int NUMR;    
    int TIME;
};

int getValidInt(const string& prompt);
string getValidString(const string& prompt);

TRAIN* createArray(int size);
void rasp(TRAIN* trainArray, int size);
void printArray(const TRAIN* trainArray, int size);

void sortTrainsByNumber(TRAIN* trainArray, int size);
void findTrainByNumber(const TRAIN* trainArray, int size, int searchNum);

#endif