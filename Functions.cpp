#include "Header.h"

void chistka()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

int getValidInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (cin >> value && value > 0)
        {
            chistka();
            cout << "Ошибка! Введите корректное положительное целое число.\n";
        }
        else
            return value;
    }
}

string getValidString(const string& prompt) {
    string value;
    while (true) {
        cout << prompt;
        getline(cin, value);
        if (!value.empty()) {
            return value;
        }
        chistka();
        cout << "Ошибка! Строка не должна быть пустой.\n";
    }
}

TRAIN* createArray(int size) {
    return new TRAIN[size];
}

void rasp(TRAIN* trainArray, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "\n--- Ввод данных для поезда №" << i + 1 << " ---\n";
        trainArray[i].NAZN = getValidString("Введите пункт назначения: ");
        trainArray[i].NUMR = getValidInt("Введите номер поезда: ");
        while (true)
        {
            int hour = getValidInt("Введите время отправления (час): ");
            if (trainArray[i].TIME > 24 || trainArray[i].TIME < 0)
            {
                cout << "Ошибка. Час не может превышать 23 или быть отрицательным.";
                chistka();
            }
            else
            {
                trainArray[i].TIME = hour;
                break;
            }
        }
    }
}


void printArray(const TRAIN* trainArray, int size) {
    cout << "\n================ РАСПИСАНИЕ ПОЕЗДОВ ================\n";
    cout << "Номер\t| Назначение\t\t| Время отправления\n";
    cout << "----------------------------------------------------\n";
    for (int i = 0; i < size; ++i) {
        cout << trainArray[i].NUMR << "\t| "
            << trainArray[i].NAZN << (trainArray[i].NAZN.length() < 8 ? "\t\t| " : "\t| ")
            << trainArray[i].TIME << "\n";
    }
    cout << "====================================================\n";
}

void sortTrainsByNumber(TRAIN* trainArray, int size) {
    sort(trainArray, trainArray + size, [](const TRAIN& a, const TRAIN& b) {
        return a.NUMR < b.NUMR;
        });
}

void findTrainByNumber(const TRAIN* trainArray, int size, int searchNum) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (trainArray[i].NUMR == searchNum) {
            cout << "\n[Информация о поезде найдена]:\n";
            cout << "Номер поезда: " << trainArray[i].NUMR << "\n";
            cout << "Пункт назначения: " << trainArray[i].NAZN << "\n";
            cout << "Время отправления: " << trainArray[i].TIME << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nПоезд с номером " << searchNum << " не найден в расписании.\n";
    }
}