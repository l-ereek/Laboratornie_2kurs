#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "=== Программа учета движения поездов (Вариант 19) ===\n";

    int n = getValidInt("Введите количество поездов (N): ");
    TRAIN* RASP = createArray(n);
    rasp(RASP, n);
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