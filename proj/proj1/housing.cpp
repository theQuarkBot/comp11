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
// ---bool no_house_here;
// ---int id;
// ---string lot_code;
// ---float price;
// ---int bedrooms;
// ---string color;
// ---string availability;
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

// - -  - - - - - - - - - - - - -  - - - - - - - - - - -
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - -

// read one line of the input_file; return corresponding House
House read_one_house(ifstream &input_file);

void print_house(House h);


// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// given a lot code, compute the column and row (respectively)
// in the all_houses array
int col_from_lot(string lot);

int row_from_lot(string lot);

//  set the no_house_here marker for every position
//  in the array
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]);

//  given a file with a count n at the top
//  read the count and then n lines of house data
//  into appropriate positions in the array
//
//   return true if file was successfully read
//          false if file could not be opened
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]);


// used for comp11 testing; do not remove.
#include "housing_hooks.hpp"

// ============================================================

int main(int argc, char *argv[])
{
        // Exits program if no input file is detected.
        check_args(argc);

        string filename = argv[1];
        ifstream input_file;

        input_file.open(filename);

        if (not input_file.is_open())
        {
                cerr << "housing.cpp: could not open file: "
                     << filename << endl;
                return 1; // if error
        }

        House all_houses[ROWS][COLS];

        fill_with_no_houses(ROWS, COLS, all_houses); 

        (void)argc;
        (void)argv;

        print_house(all_houses[0][0]);

        //   =======================================================
        //           YOUR MAIN FUNCTION CODE HERE
        //   =======================================================

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

        cout << "ID: "            << h.id
             << " Lot: "          << h.lot_code
             << " Color: "        << h.color
             << " Price: "        << h.price
             << " Bedrooms: "     << h.bedrooms
             << " Availability: " << availability
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
        int column = lot[1] - 64;
        cout << "Lot: " << lot << " Column: " << column << endl;

        return column;
}

int
row_from_lot(string lot)
{       
        (void)lot;

        return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}

//  set the no_house_here marker for every position
//  in the array
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]) {
        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                        all_houses[i][j].no_house_here == false;
                }
        }
}

//  given a file with a count n at the top
//  read the count and then n lines of house data
//  into appropriate positions in the array
//
//   return true if file was successfully read
//          false if file could not be opened
bool
read_all_house_data(string filename, House all_houses[ROWS][COLS]) {
        // IF YOU HAVE FUNCTION ARGUMENTS THAT AREN'T USED YET
        // THE G++ COMPILER COMPLAINS. THE FOLLOWING LINES ARE
        // HARMLESS AND THEY SUPPRESS THE COMPLAINT. YOU CAN REMOVE
        // THE (VOID) LINES AND THIS COMMENT ONCE YOU START USING
        // THE ARGUMENTS
        (void)filename;
        (void)all_houses;

        // YOUR CODE HERE
        return false;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}
