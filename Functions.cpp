#include "Personnel.h"
#include <string>

using namespace std;

int Personnel::cnt = 0;

Personnel::Personnel() {
    name = new char[12];
    strcpy(name, "Неизвестный");
    num = 0;
    rank = 0;
    cnt++;
}

Personnel::Personnel(const char* N, int n, int rnk) {
    if (N && strlen(N) > 0) {
        name = new char[strlen(N) + 1];
        strcpy(name, N);
    }
    else {
        name = new char[12];
        strcpy(name, "Неизвестный");
    }
    num = n;
    rank = rnk;
    cnt++;
}

Personnel::~Personnel() {
    delete[] name;
    cnt--;
}

Personnel* Personnel::addEmployee(const char* N, int n, int rnk) {return new Personnel(N, n, rnk);
}

void Personnel::removeEmployee(Personnel*& emp) {
    if (emp) {
        delete emp;
        emp = nullptr;
    }
}

int Personnel::getObjectCount() { return cnt;}
void printPersonnelDetails(const Personnel& emp) {
    cout << "[Информация] Сотрудник: " << emp.name
        << " | Цех №: " << emp.num
        << " | Разряд: " << emp.rank << endl;
}

Personnel* createPersonnelExternal(const char* N, int n, int rnk) { return new Personnel(N, n, rnk);}

void destroyPersonnelExternal(Personnel*& emp) {
    if (emp) {
        delete emp;
        emp = nullptr;
    }
}

void chistka() {
    cin.clear();
    cin.ignore(1000, '\n');
}

int ProvInt(const string& vivod, int minCh, int maxCh) {
    int ch;
    while (true) {
        cout << vivod;
        if (cin >> ch && ch >= minCh && ch <= maxCh) {
            chistka();
            return ch;
        }
        cout << "Ошибка ввода! Введите целое число в диапазоне от " << minCh << " до " << maxCh << endl;
        chistka();
    }
}

double ProvDouble(const string& vivod, double minCh, double maxCh) {
    double ch;
    while (true) {
        cout << vivod;
        if (cin >> ch && ch >= minCh && ch <= maxCh) {
            chistka();
            return ch;
        }
        cout << "Ошибка ввода! Введите число от " << minCh << " до " << maxCh << endl;
        chistka();
    }
}

string ProvString(const string& vivod) {
    string str;
    while (true) {
        cout << vivod;
        getline(cin, str);
        if (!str.empty())
            return str;
        cout << "Поле не может быть пустым. Повторите ввод" << endl;
    }
}