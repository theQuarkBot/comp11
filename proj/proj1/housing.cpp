// housing.cpp
// Purpose:             Demonstrate knowledge of structs, functions, ifstream,
//                      and 2D arrays.
// Made by:             Neil Powers
// Last Modified:       03/25/2021
// Known Bugs:          None

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

void user_ask_houses(House all_houses[ROWS][COLS]);
int prompt_user_int(string prompt);
House read_one_house(ifstream &input_file);
void print_house(House h);
int col_from_lot(string lot);
int row_from_lot(string lot);
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]);
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]);
void command_loop(House all_houses[ROWS][COLS]);
bool is_available(int house_id, House all_houses[ROWS][COLS]);
House find_house(int house_id, House all_houses[ROWS][COLS]);
int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS]);
int num_neighbors(int house_id, House all_houses[ROWS][COLS]);

void print_availability(bool available, int id);
void print_matching_houses(House houses[ROWS * COLS], int num_houses);
void print_num_neighbors(int neighbors);

int max(int a, int b);
int min(int a, int b);

#include "housing_hooks.hpp"

int main(int argc, char *argv[])
{
        // Exits program if no input file is detected.
        if (argc != 2)
        {
                cerr << "housing.cpp: Input file missing in command line"
                     << endl;
                return 1;
        }

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

        // Infinite loop; prompt user for row and col and print house at that
        // location. Break with negative input.
        // user_ask_houses(all_houses);

        command_loop(all_houses);

        return 0;
}

//===============================================================
//                      Function Impletmentations
//===============================================================

// read_one_house
// Purpose:     read one line of the input_file; return corresponding House
// Parameters:  an input file stream
// Returns:     a single house (could be no_house_here)
House read_one_house(ifstream& input_file)
{
        House out;

        out.no_house_here = false;

        input_file >> out.id
                   >> out.lot_code
                   >> out.price
                   >> out.bedrooms
                   >> out.color
                   >> out.availability;

        return out;
}

// print_house
// Purpose:     print information about a single house with a new line
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

        cout << "Id: "         << h.id
             << " Lot: "       << h.lot_code
             << " Color: "     << h.color
             << " Price: "     << h.price
             << " Bedrooms: "  << h.bedrooms
             << " Available: " << availability
             << endl;
}

// col_from_lot
// Purpose:     compute the column from a lot number in a house
//              in the all_houses array
// Parameters:  a lot string
// Returns:     an integer for the column
// Example:     "D4" => 4
//              "E1" => 5
//              “A5" => 1
int col_from_lot(string lot)
{
        int col = lot[0] - 65;

        return col;
}

// row_from_lot
// Purpose:     compute the row from a lot number in a house
//              in the all_houses array
// Parameters:  a lot string
// Returns:     an integer for the row
// Example:     "D4" => 3
//              "E1" => 0
//              “A5" => 4
int row_from_lot(string lot)
{
        int row = 0;
 
        // loop through each character of the string
        // if the character is a number (0-9) add that number to the end of the
        // result by multiplying the previous result by ten
        // e.g. "12" => out = 0 * 10 + 1 = 1 => out = 1 * 10 + 2 = 12
        for (int i = 0; i < (int)lot.length(); i++) {
                if (lot[i] >= 48 and lot[i] <= 57) {
                        row = row * 10 + (lot[i] - 48);
                }
        }

        return row - 1;
}

// fill_with_no_houses
// Purpose:     set every no_house_here in an array of houses to true.
// Parameters:  the number of rows and cols; a 2D array of houses
// Effects:     sets no_house_here to true
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]) {
        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                        all_houses[i][j].no_house_here = true;
                        all_houses[i][j].availability = "booked";
                }
        }
}

// read_all_house_data
// Purpose:     given a file with a count n at the top
//              read the count and then n lines of house data
//              into appropriate positions in the array
//              return true if file was successfully read
//              false if file could not be opened
// Parameters:  a string filename, which will be the ifstream, and a 2D
//              array of houses.
// Returns:     a boolean; true if there was an error.
// Effects:     reads all houses from a ifstream into a 2D array of houses.
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]) {
        ifstream input_file;

        input_file.open(filename);

        // make sure input_file is open
        if (not input_file.is_open())
        {
                return false;
        }

        // get the number of houses to be read from the first line of ifstream
        int num_houses;
        input_file >> num_houses;

        // read all houses into the 2D array
        for (int i = 0; i < num_houses; i++) {
                House h = read_one_house(input_file);
                int lot_row = row_from_lot(h.lot_code);
                int lot_col = col_from_lot(h.lot_code);

                all_houses[lot_row][lot_col] = h;
        }

        input_file.close();

        return true;
}


void command_loop(House all_houses[ROWS][COLS])
{
        while (true) {
                string input;
                cout << "query-> ";
                cin >> input;

                if (input == "q") return;
                else if (input == "a") {
                        int h_id;
                        
                        cin >> h_id;

                        print_availability(is_available(h_id, all_houses), h_id);
                }
                else if (input == "m") {
                        float price;
                        string color;
                        int bedrooms;

                        cin >> price >> color >> bedrooms;

                        House houses[ROWS * COLS];

                        int num_matching = matching_houses(price, color, bedrooms, all_houses, houses);

                        print_matching_houses(houses, num_matching);
                } 
                else if (input == "n") {
                        int h_id;

                        cin >> h_id;

                        int neighbors = num_neighbors(h_id, all_houses);

                        print_num_neighbors(neighbors);
                } 
                // else if (input == "r") {
                        // int h_id;
// 
                        // cin >> h_id;
// 
                        // int rent_result = rent_house(h_id, all_houses);
// 
                        // (void)rent_result;
                // }
        }
}

bool is_available(int house_id, House all_houses[ROWS][COLS])
{
        return (find_house(house_id, all_houses).availability == "available");
}

// find_house
// Purpose:     Finds a house with a given id from a 2D array of houses
// Parameters:  An id (int) and a 2D array of houses
// Returns:     The first house with a matching id
House find_house(int house_id, House all_houses[ROWS][COLS])
{
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        if (all_houses[i][j].id == house_id) {
                                return all_houses[i][j];
                        }
                }
        }

        House h;
        h.no_house_here = true;
        h.availability = "booked";

        return h;
}

int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS])
{
        int num_matching = 0;

        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        if (all_houses[i][j].price <= max_price
                            and all_houses[i][j].color == desired_color
                            and all_houses[i][j].bedrooms >= desired_bedrooms) {
                                results[num_matching++] = all_houses[i][j];
                        }
                }
        }

        return num_matching;
}

int num_neighbors(int house_id, House all_houses[ROWS][COLS])
{
        House h = find_house(house_id, all_houses);

        if (h.no_house_here) return 0;

        int r = row_from_lot(h.lot_code);
        int c = col_from_lot(h.lot_code);

        int neighbors = 0;

        for (int i = max(0, r - 1); i <= min(r + 1, ROWS); i++) {
                for (int j = max(0, c - 1); j <= min(c + 1, COLS); j++) {
                        if ((i != r and j != c)
                            and all_houses[i][j].availability == "booked") {
                                neighbors++;
                        }
                }
        }

        return neighbors;
}

int max(int a, int b)
{
        if (a > b) return a;
        return b;
}

int min(int a, int b)
{
        if (a < b) return a;
        return b;
}

void print_availability(bool available, int id)
{
        if (available) {
                cout << "House " << id << " is available" << endl;
        } else {
                cout << "Sorry, House " << id << "is not available" << endl;
        }
}

void print_matching_houses(House houses[ROWS * COLS], int num_houses)
{
        cout << "Matching Houses:" << endl;

        for (int i = 0; i < num_houses; i++) {
                print_house(houses[i]);
        }
}

void print_num_neighbors(int neighbors)
{
        if (neighbors == 0) {
                cout << "You have no neighbors, practice your drums!" << endl;
        } else {
                cout << "You have " << neighbors << " neighbors!" << endl;
        }
}
