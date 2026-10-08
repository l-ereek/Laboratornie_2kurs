#include <iostream>
#include <string>
#include "Personnel.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int sArr = ProvInt("Введите максимальное количество сотрудников для динамического массива(1-100): ", 1, 100);

    Personnel** dArr = new Personnel * [sArr];
    for (int i = 0; i < sArr; ++i)
        dArr[i] = nullptr;

    int factCnt = 0;
    int choice = -1;

    while (choice != 0) {
        cout << "\n                 ТЕКУЩИЙ СТАТУС                 " << endl;
        cout << "Активных объектов в системе: " << Personnel::getObjectCount() << endl;
        cout << "Занято слотов в массиве: " << factCnt << " из " << sArr << endl;
        cout << "                      МЕНЮ                      " << endl;
        cout << "1. Добавить сотрудника (через статический метод)" << endl;
        cout << "2. Добавить сотрудника (через дружественную функцию)" << endl;
        cout << "3. Вывести список всех сотрудников" << endl;
        cout << "4. Удалить сотрудника по индексу" << endl;
        cout << "0. Выйти из программы" << endl;

        choice = ProvInt("Выберите действие: ", 0, 4);

        switch (choice) {
        case 1:
        case 2: {
            if (factCnt >= sArr) {
                cout << "\n Ошибка: Массив заполнен! Сначала удалите кого-то из сотрудников." << endl;
                break;
            }

            char N[100];
            cout << "\nВведите ФИО сотрудника: ";
            cin.getline(N, 100);

            int n = ProvInt("Введите номер цеха (0-1000): ", 0, 1000);
            int rnk = ProvInt("Введите разряд (1-6): ", 1, 6);

            if (choice == 1) {
                dArr[factCnt] = Personnel::addEmployee(N, n, rnk);
                cout << " Сотрудник успешно добавлен через статический метод!" << endl;
            }
            else {
                dArr[factCnt] = createPersonnelExternal(N, n, rnk);
                cout << " Сотрудник успешно добавлен через дружественную функцию!" << endl;
            }

            factCnt++;
            break;
        }

        case 3: {
            cout << "\n    Список сотрудников    " << endl;
            if (factCnt == 0) {
                cout << "Список пуст." << endl;
            }
            else {
                for (int i = 0; i < factCnt; ++i) {
                    if (dArr[i] != nullptr) {
                        cout << "[" << i + 1 << "] ";
                        printPersonnelDetails(*dArr[i]);
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

            cout << "\n    Список для удаления    " << endl;
            for (int i = 0; i < factCnt; ++i) {
                if (dArr[i] != nullptr) {
                    cout << "[" << i + 1 << "] ";
                    printPersonnelDetails(*dArr[i]);
                }
            }

            int indexToDelete = ProvInt("Введите номер сотрудника для удаления (от 1 до " + to_string(factCnt) + "): ", 1, factCnt);
            indexToDelete--;
            if (indexToDelete >= 0 && indexToDelete < factCnt) {
                Personnel::removeEmployee(dArr[indexToDelete]);
                for (int i = indexToDelete; i < factCnt - 1; ++i)
                    dArr[i] = dArr[i + 1];
                dArr[factCnt - 1] = nullptr;
                factCnt--;
                cout << " Сотрудник успешно удален!" << endl;
            }
            else
                cout << " Некорректный номер!" << endl;
            break;
        }
        case 0:
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < factCnt; ++i)
        destroyPersonnelExternal(dArr[i]);
    delete[] dArr;

    cout << "Память полностью очищена." << endl;
    cout << "Итоговое количество объектов в системе: " << Personnel::getObjectCount() << endl;

    return 0;
}