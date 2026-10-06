#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Personnel {
private:
    char* name;      
    int workshopNum; 
    int category;      

    static int objectCount; 

    Personnel();
    Personnel(const char* n, int w, int c);
    Personnel(const Personnel& other);
    ~Personnel();

public:
    const char* getName() const;
    int getWorkshopNum() const;
    int getCategory() const;

    void setName(const char* n);
    void setWorkshopNum(int w);
    void setCategory(int c);

    void printInfo() const;

    static int getObjectCount();

    static Personnel* createObject(const char* n, int w, int c);
    static void destroyObject(Personnel* obj);

    friend Personnel* createPersonnelFriend(const char* n, int w, int c);
    friend void destroyPersonnelFriend(Personnel* obj);
    friend void showPrivateData(const Personnel& p);
};

void chistka();
int ProvInt(const string& vivod, int minCh = 0, int maxCh = 10000);
string ProvString(const string& vivod);

void addEmployee(vector<Personnel*>& staff);
void removeEmployee(vector<Personnel*>& staff);
void printAllEmployees(const vector<Personnel*>& staff);

#endif