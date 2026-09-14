#include "Movie.h"

Movie::Movie()
    : title("Неизвестно"), year(0), genre("Неизвестно"),
    director("Неизвестно"), mainActors("Неизвестно"), rating(0.0) {}

Movie::Movie(string t, int y, string g, string d, string a, double r)
    : title(t), year(y), genre(g), director(d), mainActors(a), rating(r) {}

Movie::Movie(const Movie& other)
    : title(other.title), year(other.year), genre(other.genre),
    director(other.director), mainActors(other.mainActors), rating(other.rating) {}

Movie::~Movie() {}

string Movie::getTitle() const { return title; }
int Movie::getYear() const { return year; }
string Movie::getGenre() const { return genre; }
string Movie::getDirector() const { return director; }
string Movie::getMainActors() const { return mainActors; }
double Movie::getRating() const { return rating; }

void Movie::setTitle(const string& t) { title = t; }
void Movie::setYear(int y) { year = y; }
void Movie::setGenre(const string& g) { genre = g; }
void Movie::setDirector(const string& d) { director = d; }
void Movie::setMainActors(const string& a) { mainActors = a; }
void Movie::setRating(double r) { rating = r; }

void Movie::printInfo() const {
    cout << "----------------------------------------" << endl;
    cout << "Название:          " << title << endl;
    cout << "Год выпуска:       " << year << endl;
    cout << "Жанр:              " << genre << endl;
    cout << "Режиссер:          " << director << endl;
    cout << "Актеры:            " << mainActors << endl;
    cout << "Рейтинг зрителей:  " << rating << "/10" << endl;
}

void chistka() {
    cin.clear();
    cin.ignore(1000, '\n');
}

void existant() {
    cout << "\nФильмотека пуста" << endl;
}

int ProvInt(const string& vivod, int minCh, int maxCh) {
    int ch;
    while (true) {
        cout << vivod;
        if (cin >> ch && ch >= minCh && ch <= maxCh) {
            chistka();
            return ch;
        }
        cout << "Ошибка ввода! Введите целое число в диапазоне от " << minCh << " до " << maxCh << endl;
        chistka();
    }
}

double ProvDouble(const string& vivod, double minCh, double maxCh) {
    double ch;
    while (true) {
        cout << vivod;
        if (cin >> ch && ch >= minCh && ch <= maxCh) {
            chistka();
            return ch;
        }
        cout << "Ошибка ввода! Введите число от " << minCh << " до " << maxCh << endl;
        chistka();
    }
}

string ProvString(const string& vivod) {
    string str;
    while (true) {
        cout << vivod;
        getline(cin, str);
        if (!str.empty())
            return str;
        cout << "Поле не может быть пустым. Повторите ввод" << endl;
    }
}

void inputMovies(vector<Movie>& library) {
    int count = ProvInt("Сколько фильмов вы хотите добавить? ", 1, 100);
    for (int i = 0; i < count; ++i) {
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

void printAllMovies(const vector<Movie>& library) {
    if (library.empty())
    {
        existant();
        return;
    }
    cout << "\n    СПИСОК ВСЕХ ФИЛЬМОВ     " << endl;
    for (const auto& movie : library)
        movie.printInfo();
}

void filterMoviesByYear(const vector<Movie>& library) {
    if (library.empty()) {
        existant();
        return;
    }
    int targetYear = ProvInt("\nВведите минимальный год выпуска для поиска: ", 1888, 2030);
    cout << "\n      ФИЛЬМЫ, ВЫПУЩЕННЫЕ В " << targetYear << " ГОДУ И ПОЗЖЕ      " << endl;

    bool found = false;
    for (const auto& movie : library)
    {
        if (movie.getYear() >= targetYear)
        {
            movie.printInfo();
            found = true;
        }
    }
    if (!found)
        cout << "Фильмы не найдены" << endl;
}

void findDirectorsByGenre(const vector<Movie>& library) {
    if (library.empty())
    {
        existant();
        return;
    }
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
        if (currentGenre == targetGenreLower) {
            if (find(foundDirectors.begin(), foundDirectors.end(), movie.getDirector()) == foundDirectors.end())
            {
                foundDirectors.push_back(movie.getDirector());
                cout << "- " << movie.getDirector() << endl;
                found = true;
            }
        }
    }
    if (!found)
        cout << "Режиссеры, снимавшие в данном жанре, не найдены" << endl;
}