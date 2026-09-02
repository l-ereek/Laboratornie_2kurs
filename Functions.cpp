#include "Header.h"

int getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Ошибка! Введите корректное положительное целое число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        cout << "Ошибка! Строка не должна быть пустой.\n";
    }
}

TRAIN* createArray(int size) {
    return new TRAIN[size];
}

void fillArrayInteractive(TRAIN* trainArray, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "\n--- Ввод данных для поезда №" << i + 1 << " ---\n";
        trainArray[i].NAZN = getValidString("Введите пункт назначения: ");
        trainArray[i].NUMR = getValidInt("Введите номер поезда: ");
        trainArray[i].TIME = getValidString("Введите время отправления (ЧЧ:ММ): ");
    }
}

void fillArrayRandom(TRAIN* trainArray, int size) {
    string cities[] = { "Москва", "Санкт-Петербург", "Ростов-на-Дону", "Краснодар", "Сочи", "Казань" };
    int citiesCount = 6;

    for (int i = 0; i < size; ++i) {
        trainArray[i].NAZN = cities[rand() % citiesCount];
        trainArray[i].NUMR = rand() % 900 + 100; // Номер от 100 до 999

        int hours = rand() % 24;
        int minutes = rand() % 60;
        char timeBuf[6];
        snprintf(timeBuf, sizeof(timeBuf), "%02d:%02d", hours, minutes);
        trainArray[i].TIME = timeBuf;
    }
    cout << "\n[Массив успешно заполнен случайными данными]\n";
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