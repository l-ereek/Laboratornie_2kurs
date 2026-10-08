#define _CRT_SECURE_NO_WARNINGS
#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Personnel {
private:
    char* name;
    int num;
    int rank;

    static int cnt;

    Personnel(const char* N, int n, int rnk);
    ~Personnel();

public:
    static Personnel* addEmployee(const char* N, int n, int rnk);
    static void removeEmployee(Personnel*& emp);
    static int getObjectCount();

    friend void printPersonnelDetails(const Personnel& emp);
    friend Personnel* createPersonnelExternal(const char* N, int n, int rnk);
    friend void destroyPersonnelExternal(Personnel*& emp);
};

Personnel* createPersonnelExternal(const char* N, int n, int rnk);
void destroyPersonnelExternal(Personnel*& emp);

void chistka();
int ProvInt(const string& vivod, int minCh, int maxCh);
double ProvDouble(const string& vivod, double minCh, double maxCh);
string ProvString(const string& vivod);

#endif