//#include <iostream>
//#include <cmath>
//#include <limits>
//#include <string>
//
//using namespace std;
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
//        if (cin >> ch)
//            return ch;
//        chistka();
//        cout << "Ошибка ввода! Введите целое число." << endl;
//    }
//}
//
//double ProvDouble(const string& vivod)
//{
//    double ch;
//    while (true)
//    {
//        cout << vivod;
//        if (cin >> ch)
//            return ch;
//        chistka();
//        cout << "Ошибка ввода! Введите вещественное число." << endl;
//    }
//}
//
//
//double RootK(double X, int K, int N)
//{
//    if (N == 0)
//        return 1.0;
//    double prevY = RootK(X, K, N - 1);
//    return prevY - (prevY - (X / pow(prevY, K - 1)) / K);
//}
//
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    system("chcp 1251");
//    double X;
//    do
//    {
//        X = ProvDouble("Введите X (> 0): ");
//        if (X <= 0)
//           cout << "Число X должно быть больше 0!" << endl;
//    }
//    while (X <= 0);
//
//    int K;
//    do
//    {
//        K = ProvInt("Введите степень корня K (> 1): ");
//        if (K <= 1)
//            cout << "Степень K должна быть больше 1!" << endl;
//    } 
//    while (K <= 1);
//
//    cout << "Введите 6 различных значений N (> 0):" << endl;
//
//    for (int i = 0; i < 6; ++i)
//    {
//        int N;
//        do
//        {
//            N = ProvInt("N " + to_string(i + 1) + ": ");
//            if (N <= 0)
//                cout << "Значение N должно быть больше 0!" << endl;
//        }
//        while (N <= 0);
//        double ans = RootK(X, K, N);
//        cout << "При N = " << N << " корень степени " << K << " из " << X << " ≈ " << ans << endl;
//    }
//    return 0;
//}