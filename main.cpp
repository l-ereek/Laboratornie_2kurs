#include "Header.h"

int main() {
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Вариант 19 (поезда)" << endl;

    int n = ProvInt("Введите количество поездов (N): ");
    
    TRAIN* RASP = createArray(n);
   
    table(RASP, n);

    sortTrainByNumber(RASP, n);

    cout << "\nДанные упорядочены по номеру поезда:" << endl;
    printArray(RASP, n);

    int searchNum = ProvInt("Введите номер поезда для поиска: ");
    findTrainByNumber(RASP, n, searchNum);

    delete[] RASP;
    return 0;
}