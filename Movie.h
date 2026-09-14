#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Movie {
private:
    string title;
    int year;
    string genre;
    string director;
    string mainActors;
    double rating;

public:
    Movie();
    Movie(string t, int y, string g, string d, string a, double r);
    Movie(const Movie& other);
    ~Movie();

    string getTitle() const;
    int getYear() const;
    string getGenre() const;
    string getDirector() const;
    string getMainActors() const;
    double getRating() const;

    void setTitle(const string& t);
    void setYear(int y);
    void setGenre(const string& g);
    void setDirector(const string& d);
    void setMainActors(const string& a);
    void setRating(double r);

    void printInfo() const;
};

void chistka();
void existant();
int ProvInt(const string& vivod, int minCh = 0, int maxCh = 2030);
double ProvDouble(const string& vivod, double minCh = 0.0, double maxCh = 10.0);
string ProvString(const string& vivod);

void inputMovies(vector<Movie>& library);
void printAllMovies(const vector<Movie>& library);
void filterMoviesByYear(const vector<Movie>& library);
void findDirectorsByGenre(const vector<Movie>& library);

#endif