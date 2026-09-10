#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Movie{
private:
    string title;           
    int releaseYear;            
    string genre;       
    string director;     
    string mainActors;   
    double rating;            

public:
    Movie()
        : title("Неизвестно"), releaseYear(0), genre("Неизвестно"),
        director("Неизвестно"), mainActors("Неизвестно"), rating(0.0) {}


    Movie(string t, int y, string g, string d, string a, double r)
        : title(t), releaseYear(y), genre(g), director(d), mainActors(a), rating(r) {}

    Movie(const Movie& other)
        : title(other.title), releaseYear(other.releaseYear), genre(other.genre),
        director(other.director), mainActors(other.mainActors), rating(other.rating) {
    }

    ~Movie() {}

    string getTitle() const { return title; }
    int getReleaseYear() const { return releaseYear; }
    string getGenre() const { return genre; }
    string getDirector() const { return director; }
    string getMainActors() const { return mainActors; }
    double getRating() const { return rating; }

    void setTitle(const string& t) { title = t; }
    void setReleaseYear(int y) { releaseYear = y; }
    void setGenre(const string& g) { genre = g; }
    void setDirector(const string& d) { director = d; }
    void setMainActors(const string& a) { mainActors = a; }
    void setRating(double r) { rating = r; }


    void printInfo() const
    {
        cout << "----------------------------------------" << endl;
        cout << "Название:          " << title << endl;
        cout << "Год выпуска:       " << releaseYear << endl;
        cout << "Жанр:              " << genre << endl;
        cout << "Режиссер:          " << director << endl;
        cout << "Актеры:            " << mainActors << endl;
        cout << "Рейтинг зрителей:  " << rating << "/10" << endl;
    }
};

void chistka() {
    cin.clear();
    cin.ignore(1000, '\n');
}


void existant() {
    cout << "\nФильмотека пуста" << endl;
    return;
}


int ProvInt(const string& vivod, int minCh = 0, int maxCh = 2030)
{
    int ch;
    while (true)
    {
        cout << vivod;
        if (cin >> ch && ch >= minCh && ch <= maxCh)
        {
            chistka();
            return ch;
        }
        cout << "Ошибка ввода! Введите целое число в диапазоне от " << minCh << " до " << maxCh << endl;
        chistka();
    }
}


double ProvDouble(const string& vivod, double minCh = 0.0, double maxCh = 10.0)
{
    double ch;
    while (true)
    {
        cout << vivod;
        if (cin >> ch && ch >= minCh && ch <= maxCh)
        {
            chistka();
            return ch;
        }
        cout << "Ошибка ввода! Введите число от " << minCh << " до " << maxCh << endl;
        chistka();
    }
}


string ProvString(const string& vivod)
{
    string str;
    while (true)
    {
        cout << vivod;
        getline(cin, str);
        if (!str.empty())
            return str;
        cout << "Поле не может быть пустым. Повторите ввод" << endl;
    }
}


void inputMovies(vector<Movie>& library)
{
    int count = ProvInt("Сколько фильмов вы хотите добавить? ", 1, 100);
    for (int i = 0; i < count; ++i)
    {
        cout << "\n--- Ввод данных фильма №" << (i + 1) << endl;
        string title = ProvString("Введите название фильма: ");
        int year = ProvInt("Введите год выпуска (1888-2030): ", 1888, 2030);
        string genre = ProvString("Введите жанр: ");
        string director = ProvString("Введите режиссера: ");
        string actors = ProvString("Введите основных актеров: ");
        double rating = ProvDouble("Введите рейтинг у зрителей (0.0 - 10.0): ", 0.0, 10.0);
        library.push_back(Movie(title, year, genre, director, actors, rating));
    }
}

void printAllMovies(const vector<Movie>& library)
{
    if (library.empty())
        existant();
    cout << "\n    СПИСОК ВСЕХ ФИЛЬМОВ     " << endl;
    for (const auto& movie : library)
        movie.printInfo();
}

void filterMoviesByYear(const vector<Movie>& library)
{
    if (library.empty())
        existant();
    int targetYear = ProvInt("\nВведите минимальный год выпуска для поиска: ", 1888, 2030);
    cout << "\n      ФИЛЬМЫ, ВЫПУЩЕННЫЕ В " << targetYear << " ГОДУ И ПОЗЖЕ      " << endl;

    bool found = false;
    for (const auto& movie : library)
        if (movie.getReleaseYear() >= targetYear)
        {
            movie.printInfo();
            found = true;
        }
    if (!found)
        cout << "Фильмы не найдены"<< endl;
}


void findDirectorsByGenre(const vector<Movie>& library)
{
    if (library.empty())
        existant();
    string targetGenre = ProvString("\nВведите жанр для поиска режиссеров: ");
    string targetGenreLower = targetGenre;
    transform(targetGenreLower.begin(), targetGenreLower.end(), targetGenreLower.begin(), ::tolower);

    cout << "\n        РЕЖИССЕРЫ, СНИМАВШИЕ В ЖАНРЕ " << targetGenre << endl;
    bool found = false;
    vector<string> foundDirectors;

    for (const auto& movie : library)
    {
        string currentGenre = movie.getGenre();
        transform(currentGenre.begin(), currentGenre.end(), currentGenre.begin(), ::tolower);
        if (currentGenre == targetGenreLower)
            if (find(foundDirectors.begin(), foundDirectors.end(), movie.getDirector()) == foundDirectors.end())
            {
                foundDirectors.push_back(movie.getDirector());
                cout << "- " << movie.getDirector() << endl;
                found = true;
            }
    }
    if (!found)
        cout << "Режиссеры, снимавшие в данном жанре, не найдены" << endl;
}

int main(){
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

        switch (choice)
        {
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