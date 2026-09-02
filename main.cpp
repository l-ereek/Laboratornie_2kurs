#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "=== Программа учета движения поездов (Вариант 19) ===\n";

    int n = getValidInt("Введите количество поездов (N): ");
    TRAIN* RASP = createArray(n);

    cout << "\nВыберите способ заполнения данных:\n";
    cout << "1 — Вручную с клавиатуры\n";
    cout << "2 — Генератором случайных чисел\n";
    int fillChoice = getValidInt("Ваш выбор (1 или 2): ");

    while (fillChoice != 1 && fillChoice != 2) {
        cout << "Неверный выбор. ";
        fillChoice = getValidInt("Введите 1 или 2: ");
    }

    if (fillChoice == 1) {
        fillArrayInteractive(RASP, n);
    }
    else {
        fillArrayRandom(RASP, n);
    }

    // Сортировка по возрастанию номера поезда по заданию
    sortTrainsByNumber(RASP, n);

    // Вывод отсортированного списка
    cout << "\nДанные упорядочены по номеру поезда:";
    printArray(RASP, n);

    // Поиск поезда
    int searchNum = getValidInt("\nВведите номер поезда для поиска: ");
    findTrainByNumber(RASP, n, searchNum);

    delete[] RASP;
    return 0;
}