#include <iostream>
#include <limits>
#include <string>
#include "Personnel.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "RU");
    system("chcp 1251");

    int array = ProvInt("Введите максимальное количество сотрудников для динамического массива: ", 1, 10);

    if (array <= 0) {
        cout << "Размер массива должен быть больше 0. Завершение программы." << endl;
        return 0;
    }

    Personnel** employees = new Personnel * [array];
    for (int i = 0; i < array; ++i)
        employees[i] = nullptr;

    int factCnt = 0;
    int choice = -1;

    while (choice != 0) {
        cout << "\n================ ТЕКУЩИЙ СТАТУС ================" << endl;
        cout << "Активных объектов в системе (static objectCount): " << Personnel::getObjectCount() << endl;
        cout << "Занято слотов в массиве: " << factCnt << " из " << array << endl;
        cout << "===================== МЕНЮ =====================" << endl;
        cout << "1. Добавить сотрудника (через статический метод)" << endl;
        cout << "2. Добавить сотрудника (через дружественную функцию)" << endl;
        cout << "3. Вывести список всех сотрудников" << endl;
        cout << "4. Удалить сотрудника по индексу" << endl;
        cout << "0. Выйти из программы" << endl;
        cout << "================================================" << endl;

        choice = ProvInt("Выберите действие: ",0,4);

        switch (choice) {
        case 1:
        case 2: {
            if (factCnt >= array) {
                cout << "\n Ошибка: Массив заполнен! Сначала удалите кого-то из сотрудников." << endl;
                break;
            }

            char inputName[100];
            cout << "\nВведите ФИО сотрудника: ";
            cin.getline(inputName, 100);

            int inputWorkshop = ProvInt("Введите номер цеха (0-1000): ",0,1000);
            int inputRank = ProvInt("Введите разряд (1-6): ", 1,6);

            if (choice == 1) {
                employees[factCnt] = Personnel::addEmployee(inputName, inputWorkshop, inputRank);
                cout << " Сотрудник успешно добавлен через статический метод!" << endl;
            }
            else {
                employees[factCnt] = createPersonnelExternal(inputName, inputWorkshop, inputRank);
                cout << " Сотрудник успешно добавлен через дружественную функцию!" << endl;
            }

            factCnt++;
            break;
        }

        case 3: {
            cout << "\n=== Список сотрудников ===" << endl;
            if (factCnt == 0) {
                cout << "Список пуст." << endl;
            }
            else {
                for (int i = 0; i < factCnt; ++i) {
                    if (employees[i] != nullptr) {
                        cout << "[" << i + 1 << "] ";
                        printPersonnelDetails(*employees[i]);
                    }
                }
            }
            break;
        }

        case 4: {
            if (factCnt == 0) {
                cout << "\n Список пуст, некого удалять!" << endl;
                break;
            }

            cout << "\n=== Список для удаления ===" << endl;
            for (int i = 0; i < factCnt; ++i) {
                if (employees[i] != nullptr) {
                    cout << "[" << i + 1 << "] ";
                    printPersonnelDetails(*employees[i]);
                }
            }

            int indexToDelete = ProvInt("Введите номер сотрудника для удаления (от 1 до " + to_string(factCnt) + "): ", 1, factCnt);
            indexToDelete--;

            if (indexToDelete >= 0 && indexToDelete < factCnt) {
                Personnel::removeEmployee(employees[indexToDelete]);

                for (int i = indexToDelete; i < factCnt - 1; ++i) {
                    employees[i] = employees[i + 1];
                }
                employees[factCnt - 1] = nullptr;
                factCnt--;

                cout << " Сотрудник успешно удален!" << endl;
            }
            else {
                cout << " Некорректный номер!" << endl;
            }
            break;
        }

        case 0:
            cout << "\nЗавершение работы..." << endl;
            break;

        default:
            cout << " Неверный пункт меню. Повторите попытку." << endl;
            break;
        }
    }

    for (int i = 0; i < factCnt; ++i) {
        destroyPersonnelExternal(employees[i]);
    delete[] employees;

    cout << "Память полностью очищена." << endl;
    cout << "Итоговое количество объектов в системе: " << Personnel::getObjectCount() << endl;

    return 0;
}