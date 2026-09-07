//#include "Header.h"
//
//void chistka()
//{
//    cin.clear();
//    cin.ignore(1000, '\n');
//}
//
//int ProvInt(const string& vivod)
//{
//    int ch;
//    while (true)
//    {
//        cout << vivod;
//        if (cin >> ch && ch > 0)
//        {
//            cin.ignore(1000, '\n');
//            return ch;
//        }
//        chistka();
//        cout << "Ошибка! Введите корректное число." << endl;
//    }
//}
//
//string ProvString(const string& vivod)
//{
//    string n;
//    while (true)
//    {
//        cout << vivod;
//        getline(cin, n);
//        if (!n.empty() && none_of(n.begin(), n.end(), ::isdigit))
//            return n;
//        cout << "Ошибка! Вводимые данные не должны содержать цифры и не могут быть пустыми" << endl;
//    }
//}
//string ProvTime(const string& vivod)
//{
//    string t;
//    while (true)
//    {
//        cout << vivod;
//        getline(cin, t);
//        if (t.length() == 5 && t[2] == ':')
//        {
//            if (isdigit(t[0]) && isdigit(t[1]) && isdigit(t[3]) && isdigit(t[4]))
//            {
//                int h1 = t[0] - '0';
//                int h2 = t[1] - '0';
//                int m1 = t[3] - '0';
//                int m2 = t[4] - '0';
//                int hours = h1 * 10 + h2;
//                int minutes = m1 * 10 + m2;
//                if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59)
//                    return t;
//            }
//        }
//        cout << "Ошибка! Некорректный формат времени. Введите в формате ЧЧ:ММ (от 00:00 до 23:59)" << endl;
//    }
//}
//
//TRAIN* createArray(int size)
//{
//    return new TRAIN[size];
//}
//
//void table(TRAIN* trainArray, int size)
//{
//    for (int i = 0; i < size; ++i)
//    {
//        cout << "Ввод данных для поезда №" << i + 1 << endl;
//        trainArray[i].NAZN = ProvString("Введите пункт назначения: ");
//        trainArray[i].NUMR = ProvInt("Введите номер поезда: ");
//        trainArray[i].TIME = ProvTime("Введите время отправления (ЧЧ:ММ): ");
//    }
//}
//
//void printArray(const TRAIN* trainArray, int size)
//{
//    cout << "РАСПИСАНИЕ ПОЕЗДОВ" << endl;
//    for (int i = 0; i < size; ++i)
//    {
//        cout << "\nНомер: " << trainArray[i].NUMR << endl;
//        cout << "Назначение: " << trainArray[i].NAZN << endl;
//        cout << "Время отправления: " << trainArray[i].TIME << endl << endl;
//    }
//}
//
//void sortTrainByNumber(TRAIN* trainArray, int size)
//{
//    for (int i = 0; i < size -1; ++i)
//        for (int j = 0; j < size-i - 1; ++j)
//            if (trainArray[j].NUMR > trainArray[j + 1].NUMR)
//                swap(trainArray[j], trainArray[j + 1]);
//}
//
//void findTrainByNumber(const TRAIN* trainArray, int size, int searchNum)
//{
//    bool found = false;
//    for (int i = 0; i < size; ++i)
//    {
//        if (trainArray[i].NUMR == searchNum)
//        {
//            cout << "Информация о поезде найдена: " << endl;
//            cout << "Номер поезда: " << trainArray[i].NUMR << endl;
//            cout << "Пункт назначения: " << trainArray[i].NAZN << endl;
//            cout << "Время отправления в: " << trainArray[i].TIME << endl;
//            found = true;
//            break;
//        }
//    }
//    if (!found)
//        cout << "Поезд с номером " << searchNum << " не найден в расписании.";
//}