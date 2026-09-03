#include "Header.h"

void chistka() {
    cin.clear();
    cin.ignore(1000, '\n');
}

int ProvInt(const string& prompt) {
    int ch;
    while (true) {
        cout << prompt;
        if (cin >> ch && ch >= 0) {
            cin.ignore(1000, '\n');
            return ch;
        }
        cout << "Ошибка! Введите корректное число .\n";
        chistka();
    }
}

string ProvString(const string& vivod)
{
    string n;
    while (true)
    {
        cout << vivod;
        getline(cin, n);
        if (!n.empty() && none_of(n.begin(), n.end(), ::isdigit))
            return n;
        cout << "Ошибка! Вводимые данные не должны содержать цифры и не могут быть пустыми.\n";
    }
}

TRAIN* createArray(int size)
{
    return new TRAIN[size];
}

void table(TRAIN* trainArray, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Ввод данных для поезда №" << i + 1 << endl;
        trainArray[i].NAZN = ProvString("Введите пункт назначения: ");
        trainArray[i].NUMR = ProvInt("Введите номер поезда: ");

        while (true)
        {
            int hours = ProvInt("Введите время отправления (час 1-24): ");
            if (hours >= 1 && hours <= 24)
            {
                trainArray[i].TIME = hours;
                break; 
            }
            cout << "Ошибка! Час отправления должен быть от 1 до 24.\n";
        }
    }
}

void printArray(const TRAIN* trainArray, int size) {
    cout << "РАСПИСАНИЕ ПОЕЗДОВ" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "\nНомер: " << trainArray[i].NUMR << endl;
        cout << "Назначение: " << trainArray[i].NAZN << endl;
        cout << "Время отправления: " << trainArray[i].TIME << endl << endl;
    }
}

void sortTrainByNumber(TRAIN* trainArray, int size)
{
    
}

void findTrainByNumber(const TRAIN* trainArray, int size, int searchNum) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (trainArray[i].NUMR == searchNum) {
            cout << "Информация о поезде найдена: " << endl;
            cout << "Номер поезда: " << trainArray[i].NUMR << endl;
            cout << "Пункт назначения: " << trainArray[i].NAZN << endl;
            cout << "Время отправления в: " << trainArray[i].TIME << "ч" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Поезд с номером " << searchNum << " не найден в расписании.";
    }
}