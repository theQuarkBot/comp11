// housing.cpp
// 


#include <iostream>
#include <fstream>

using namespace std;

// used for the dimensions of all houses.
const int ROWS = 50; 
const int COLS = 20;

// House
// Each House struct records the information about one house.
// If "no_house_here" is false, none of the other fields are declared.
// If it is true, ever variable is declared.
struct House {
        bool    no_house_here;  // true if there is NO house on this location
        int     id;             // id from the data file, converted to int
        string  lot_code;       // lot_code string from the data file
        float   price;          // price of the house as a float
        int     bedrooms;       // number of bedrooms in a house
        string  color;          // color of the house
        string  availability;   // availibility of the house
};

//===============================================================
//                      Function Prototypes
//===============================================================

void check_args(int argc);
void user_ask_houses(House all_houses[ROWS][COLS]);
int prompt_user_int(string prompt);

// - -  - - - - - - - - - - - - -  - - - - - - - - - - -
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - -

House read_one_house(ifstream &input_file);
void print_house(House h);

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

int col_from_lot(string lot);
int row_from_lot(string lot);
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]);
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]);

#include "housing_hooks.hpp"

    // ============================================================

    int main(int argc, char *argv[])
{
        // Exits program if no input file is detected.
        check_args(argc);

        House all_houses[ROWS][COLS];

        // fill the array with no houses (no_house_here = true)
        fill_with_no_houses(ROWS, COLS, all_houses); 

        // check that read_all_house_data could be read and stored to
        // all_houses. end program if not.
        if (not read_all_house_data(argv[1], all_houses)) {
                cerr << "housing.cpp: could not open file: "
                     << argv[1] << endl;
                return 1;
        }

        // Infinite loop; promt user for row and col and pront house at that
        // location. Break with negative input.
        user_ask_houses(all_houses);

        return 0;
}

// check_args
// Purpose:     verifies the necessary arguments are given to the program
// Parameters:  argc and argv
// Effects:     exits program if conditions are not met.
void check_args(int argc)
{
        if (argc != 2) {
                cerr << "housing.cpp: Input file missing in command line"
                     << endl;
                _Exit(1);
        }
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// read_one_house
// Purpose:     read one line of the input_file; return corresponding House
// Parameters:  an input file stream
// Returns:     a single house (could be no_house_here)
House read_one_house(ifstream& input_file)
{
        (void) input_file;

        // MAKE MORE COMPACT-----------------------------------------------------------------------------------------------

        bool no_house_here = false;
        int id;
        string lot_code;
        float price;
        int bedrooms;
        string color;
        string availability;

        input_file >> id >> lot_code >> price >> bedrooms >> color >> availability;

        House out = {
                no_house_here,
                id,
                lot_code,
                price,
                bedrooms,
                color,
                availability
        };

        return out;
}

// print_house
// Purpose:     print information about a single house
// Parameters:  a single house
// Effects:     prints with cout
void print_house(House h)
{

        if (h.no_house_here) {
                cout << "No house" << endl;
                return;
        }

        string availability = "No";

        if (h.availability == "available") availability = "Yes";

        cout << "Id: "            << h.id
             << " Lot: "          << h.lot_code
             << " Color: "        << h.color
             << " Price: "        << h.price
             << " Bedrooms: "     << h.bedrooms
             << " Available: " << availability
             << endl;
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// col_from_lot
// Purpose:     compute the column from a lot number in a house
// Parameters:  a lot string
// Returns:     an integer for the column
// Example:     "D4" => 4
//              "E1" => 5
//              “A5" => 1
// in the all_houses array
int col_from_lot(string lot)
{
        int column = lot[0] - 65;

        return column;
}

int row_from_lot(string lot)
{
        int row = 0;

        // loop through each character of the lot
        // if the character is a number (0-9) add that number to the end of the
        // result by multiplying the previous result by ten
        // e.g. "12" => out = 0 * 10 + 1 = 1 => out = 1 * 10 + 2 = 12
        for (int i = 0; i < (int)lot.length(); i++)
        {
                if (lot[i] >= 48 and lot[i] <= 57)
                {
                        row = row * 10 + (lot[i] - 49);
                }
        }

        return row;
}

//  set the no_house_here marker for every position
//  in the array
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]) {
        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                        all_houses[i][j].no_house_here = true;
                }
        }
}

// read_all_house_data
// given a file with a count n at the top
// read the count and then n lines of house data
// into appropriate positions in the array
//
// return true if file was successfully read
//        false if file could not be opened
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]) {
        (void)filename;
        (void)all_houses;

        ifstream input_file;

        input_file.open(filename);

        if (not input_file.is_open())
        {
                return false; // if error
        }

        int num_houses;

        input_file >> num_houses;

        for (int i = 0; i < num_houses; i++) {
                House h = read_one_house(input_file);
                int lot_row = row_from_lot(h.lot_code);
                int lot_col = col_from_lot(h.lot_code);

                cerr << "Lot: " << h.lot_code << " Column: " << lot_col << " Row: " << lot_row << endl;

                all_houses[lot_row][lot_col] = h;
        }

        input_file.close();

        // YOUR CODE HERE
        return true;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}

void user_ask_houses(House all_houses[ROWS][COLS])
{
        while (true) {
                int row, col;

                row = prompt_user_int("Enter row: ");
                if (row < 0) return;
                col = prompt_user_int("Enter col: ");
                if (col < 0) return;

                print_house(all_houses[row][col]);
        }
}

int prompt_user_int(string prompt)
{
        cout << prompt;
        int out;
        cin >> out;
        return out;
}