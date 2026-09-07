//#include <iostream>
//#include <limits>
//#include <string>
//#include <cstdlib>
//
//using namespace std;
//int ProvInt(const string& vivod)
//{
//    int ch;
//    while (true)
//    {
//        cout << vivod;
//        if (cin >> ch)
//            return ch;
//        cin.clear();
//        cin.ignore(1000, '\n');
//        cout << "Ошибка ввода! Введите целое число." << endl;
//    }
//}
//
//bool IsPrime(int N)
//{
//    if (N <= 1)
//        return false;
//    for (int i = 2; i * i <= N; ++i)
//        if (N % i == 0)
//            return false;
//    return true;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    system("chcp 1251");
//
//    const int size = 10;
//    int n[size];
//    int cnt = 0;
//
//    cout << "Введите 10 целых чисел, больших 1" << endl;
//
//    for (int i = 0; i < size; ++i)
//    {
//        do
//        {
//            n[i] = ProvInt("Число " + to_string( i + 1) + ": ");
//            if (n[i] <= 1)
//                cout << "Ошибка! Число должно быть строго больше 1" << endl;
//        }
//        while (n[i] <= 1);
//
//        if (IsPrime(n[i]))
//            cnt++;
//    }
//
//    cout << "Результат: количество простых чисел = " << cnt;
//    return 0;
//}