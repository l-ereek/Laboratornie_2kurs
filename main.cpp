#include "Movie.h"

int main() {
    setlocale(LC_ALL, "RU");
    system("chcp 1251");

    vector<Movie> library;

    library.push_back(Movie("Начало", 2010, "Фантастика", "Кристофер Нолан", "Леонардо Ди Каприо", 8.8));
    library.push_back(Movie("Побег из Шоушенка", 1994, "Драма", "Фрэнк Дарабонт", "Тим Роббинс, Морган Фриман", 9.3));
    library.push_back(Movie("Интерстеллар", 2014, "Фантастика", "Кристофер Нолан", "Мэттью Макконахи", 8.6));
    library.push_back(Movie("Криминальное чтиво", 1994, "Криминал", "Квентин Тарантино", "Джон Траволта", 8.9));

    int choice;
    do {
        cout << "\n               МЕНЮ               " << endl;
        cout << "1. Добавить фильмы в фильмотеку" << endl;
        cout << "2. Показать все фильмы" << endl;
        cout << "3. Найти фильмы с годом выпуска не менее заданного" << endl;
        cout << "4. Найти режиссеров по жанру" << endl;
        cout << "0. Выход\n";
        choice = ProvInt("Выберите действие: ", 0, 4);

        switch (choice) {
        case 1:
            inputMovies(library);
            break;
        case 2:
            printAllMovies(library);
            break;
        case 3:
            filterMoviesByYear(library);
            break;
        case 4:
            findDirectorsByGenre(library);
            break;
        case 0:
            cout << "Завершение работы программы." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}