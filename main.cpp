#include "Personnel.h"

void testStaticAndFriends() {
    cout << "\n==========================================" << endl;
    cout << "   ТЕСТИРОВАНИЕ СТАТИКИ И ДРУЖЕСТВЕННОСТИ   " << endl;
    cout << "==========================================" << endl;

    cout << "1. Объектов при входе в тесты: " << Personnel::getObjectCount() << endl;

    Personnel* staticArray[2];
    staticArray[0] = Personnel::createObject("Иванов И.И.", 1, 3);
    staticArray[1] = Personnel::createObject("Петров П.П.", 2, 4);
    cout << "2. После создания статического массива объектов: " << Personnel::getObjectCount() << endl;

    Personnel* dynObj = createPersonnelFriend("Сидоров С.С.", 3, 5);
    cout << "3. После динамического создания объекта (friend): " << Personnel::getObjectCount() << endl;

    showPrivateData(*dynObj);

    destroyPersonnelFriend(dynObj);
    cout << "4. После удаления динамического объекта: " << Personnel::getObjectCount() << endl;

    Personnel::destroyObject(staticArray[0]);
    Personnel::destroyObject(staticArray[1]);
    cout << "5. После очистки массива: " << Personnel::getObjectCount() << endl;
    cout << "==========================================\n" << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    system("chcp 1251");

    testStaticAndFriends();

    vector<Personnel*> staff;

    staff.push_back(Personnel::createObject("Алексеев А.А.", 1, 4));
    staff.push_back(Personnel::createObject("Борисов Б.Б.", 2, 5));

    int choice;
    do {
        cout << "\n               МЕНЮ               " << endl;
        cout << "1. Добавить сотрудника" << endl;
        cout << "2. Удалить сотрудника" << endl;
        cout << "3. Показать всех сотрудников" << endl;
        cout << "4. Показать счетчик созданных объектов" << endl;
        cout << "0. Выход\n";
        choice = ProvInt("Выберите действие: ", 0, 4);

        switch (choice) {
        case 1:
            addEmployee(staff);
            break;
        case 2:
            removeEmployee(staff);
            break;
        case 3:
            printAllEmployees(staff);
            break;
        case 4:
            cout << "\nТекущее количество живых объектов: " << Personnel::getObjectCount() << endl;
            break;
        case 0:
            cout << "Завершение работы программы." << endl;
            break;
        }
    } while (choice != 0);

    for (auto emp : staff) {
        Personnel::destroyObject(emp);
    }
    staff.clear();

    return 0;
}