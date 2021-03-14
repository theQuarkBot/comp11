/*
    moviedb.cpp
    Purpose: Interact with arrays of structs by manipulating
            and searching a movie database
    Written by: Keisha Mukasa
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NUM_MOVIES = 450;
const int NUM_ACTORS = 5;

struct Movie
{
    string title;
    int year;
    double gross;
    string director;
    string actors[NUM_ACTORS];
};

void read_movie_data(Movie movies[NUM_MOVIES]);
void print_movie(Movie movie);
string getInput(string prompt);
void findMovie(Movie movie_list[NUM_MOVIES], string movie_title);
void printMoviesInYear(Movie movie_list[NUM_MOVIES], int year);
void printBoxOfficeGross(Movie movie_list[NUM_MOVIES]);

int main()
{
    // This line of code declares a list of 450 movies obje
    Movie movie_list[NUM_MOVIES];
    // This function call is populating the movie list with all
    // the movies in the file. Do not worry about its implementation.
    read_movie_data(movie_list);

    /* Your code goes here */

    // findMovie(movie_list, getInput("Enter a movie: "));
    // printMoviesInYear(movie_list, 2007);
    printBoxOfficeGross(movie_list);

    return 0;
}

string getInput(string prompt)
{
    string out;
    cout << prompt;
    getline(cin, out);

    return out;
}

void findMovie(Movie movie_list[NUM_MOVIES], string movie_title)
{
    for (int i = 0; i < NUM_MOVIES; i++) {
        if (movie_list[i].title == movie_title) {
            print_movie(movie_list[i]);

            return;
        }
    }

    cout << movie_title << " was not found in the movie database." << endl;
}

void print_movie(Movie movie)
{
    cout << "Title: " << movie.title << endl;
    cout << "Year: " << movie.year << endl;
    cout << "Gross: " << movie.gross << endl;
    cout << "Director: "<< movie.director << endl;

    for (int i = 0; i < NUM_ACTORS; i++) {
        cout << "Actor: " << movie.actors[i] << endl;
    }
}

void printMoviesInYear(Movie movie_list[NUM_MOVIES], int year)
{
    for (int i = 0; i < NUM_MOVIES; i++) {
        if (movie_list[i].year == year) {
            cout << movie_list[i].title << endl;
        }
    }
}

// int findHighestGross(Movie movie_list[NUM_MOVIES])
// {
//     int max = movie_list[0].gross;
//     int max_pos = 0;

//     for (int i = 0; i < NUM_MOVIES; i++) {
//         if (movie_list[i].gross > max) {
//             max = movie_list[i].gross;
//             max_pos = i;
//         }
//     }

//     return max_pos;
// }



void printBoxOfficeGross(Movie movie_list[NUM_MOVIES])
{
    int max_pos = 0;
    int min_pos = 0;
    int max = movie_list[0].gross;
    int min = movie_list[0].gross;
    int avg = 0;

    // calculate min and max; add all gross.
    for (int i = 0; i < NUM_MOVIES; i++) {
        int cur = movie_list[i].gross;

        if (cur > max) {
            max = cur;
            max_pos = i;
        } else if (cur < min) {
            min = cur;
            min_pos = i;
        }

        avg += cur;
    }

    avg /= NUM_MOVIES;

    cout << "Highest grossing movie: " << movie_list[max_pos].title
         << "\nLowest grossing movie: " << movie_list[min_pos].title
         << "\nAverage gross of movies: " << avg << endl;
}


/************************************************************
 *                     NOTE                               
 * The function below are part of the starter code that enable
 * you to read in from a file. You do not need to understand
 * the code below to complete the lab and we encourage you to
 * ignore this code. This implementation will be covered in the
 * future but is not currently required for lab or hw.
*************************************************************/

/*  
*   READ_MOVIE_DATA
*   Parameters: Empty movie array
*   Purpose: Read lists of movies data from a file and store in array
*   Returns: Does not return anything
*/
void read_movie_data(Movie movies[NUM_MOVIES])
{
    // ifstream object declaration in order to open and read
    // from a file
    ifstream infile;
    string filename = "moviedata.txt";

    // open file
    infile.open(filename);

    // check if file successfully opened if it isn't the program is
    // exited immediately
    if (infile.fail())
    {
        cerr << "ERROR: Error opening file, please check file name: "
             << filename << endl;
        exit(EXIT_FAILURE);
    }

    // read through file
    for (int i = 0; i < NUM_MOVIES; i++)
    {
        getline(infile, movies[i].title);
        infile >> movies[i].year;
        infile >> movies[i].gross;
        infile.ignore();
        getline(infile, movies[i].director);

        // reads in each actors name
        for (int j = 0; j < NUM_ACTORS; j++)
        {
            getline(infile, movies[i].actors[j]);
        }
    }
}
