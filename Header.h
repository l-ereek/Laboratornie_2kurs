#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Структура по условию варианта 19 (Задание 2)
struct TRAIN {
    string NAZN; // Пункт назначения
    int NUMR;    // Номер поезда
    string TIME; // Время отправления
};

// Вспомогательные функции ввода
int getValidInt(const string& prompt);
string getValidString(const string& prompt);

// Обязательные функции по ТЗ
TRAIN* createArray(int size);
void fillArrayInteractive(TRAIN* trainArray, int size);
void fillArrayRandom(TRAIN* trainArray, int size);
void printArray(const TRAIN* trainArray, int size);

// Функции логики задания
void sortTrainsByNumber(TRAIN* trainArray, int size);
void findTrainByNumber(const TRAIN* trainArray, int size, int searchNum);

#endif