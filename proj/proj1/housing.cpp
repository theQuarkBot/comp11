// housing.cpp
// Purpose:             Demonstrate knowledge of structs, functions, ifstream,
//                      and 2D arrays.
// Made by:             Neil Powers
// Last Modified:       03/31/2021
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

House read_one_house(ifstream &input_file);
void print_house(House h);
int col_from_lot(string lot);
int row_from_lot(string lot);
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]);
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]);

// Command loop functions
void command_loop(House all_houses[ROWS][COLS]);
bool is_available(int house_id, House all_houses[ROWS][COLS]);
House find_house(int house_id, House all_houses[ROWS][COLS]);
int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS]);
int num_neighbors(int house_id, House all_houses[ROWS][COLS]);
int rent_house(int house_id, House all_houses[ROWS][COLS]);

// Command loop helper functions
void print_availability(House all_houses[ROWS][COLS]);
void print_matching_houses(House all_houses[ROWS][COLS]);
void print_num_neighbors(House all_houses[ROWS][COLS]);
void print_rent_results(House all_houses[ROWS][COLS]);

// Helper functions
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

        // run the command loop
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

// command_loop
// Purpose:     Loop through a series of commands, calling other functions
//              depending on the input. 
// Parameters:  A 2D array of all houses.
// Effects:     Calls other functions; loops indefinitely until input "q".
void command_loop(House all_houses[ROWS][COLS])
{
        while (true) {
                string input;
                cout << "query-> ";
                cin >> input;

                if (input == "q") return;
                else if (input == "a") {
                        print_availability(all_houses);
                }
                else if (input == "m") {
                        print_matching_houses(all_houses);
                } 
                else if (input == "n") {
                        print_num_neighbors(all_houses);
                } 
                else if (input == "r") {
                        print_rent_results(all_houses);
                }
                else {
                        cout << "Unknown command " << input << endl;
                }
        }
}

// is_available
// Purpose:     Determines if a house with a given id is available
// Parameters:  A house ID to search for and all_houses
// Returns:     True if the house is available; false if not (or doesn't exist)
// Effects:     Calls find_house
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
        // return the house if it exists
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        if (all_houses[i][j].id == house_id) {
                                return all_houses[i][j];
                        }
                }
        }

        // house with values indicating it doesn't exist
        House h;
        h.no_house_here = true;
        h.availability = "booked";
        h.id = -1; //invalid id

        return h;
}

// matching_houses
// Purpose:     Finds all houses in a 2D array with suitable PRICE, COLOR, and
//              NUMBER OF BEDROOMS, and adds them to an array of houses.
// Returns:     The number of houses matching the conditions
// Effects:     Edits inputted array.
int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS])
{
        int num_matching = 0;

        // count the number of houses matching the conditions and
        // add them to the results array
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        if (all_houses[i][j].price <= max_price
                            and all_houses[i][j].color == desired_color
                            and all_houses[i][j].bedrooms >= desired_bedrooms) {
                                results[num_matching] = all_houses[i][j];
                                num_matching++;
                        }
                }
        }

        return num_matching;
}

// num_neighbors
// Purpose:     Counts the number of neighbors surrounding a given house
//              Only counts if the house is booked
// Parameters:  A house if and a 2D array of houses
// Returns:     The number of neighborring houses
// Effects:     Calls max() and min() functions
int num_neighbors(int house_id, House all_houses[ROWS][COLS])
{
        // find the location of the house in the 2D array
        House h = find_house(house_id, all_houses);

        if (h.no_house_here) return 0;

        int r = row_from_lot(h.lot_code);
        int c = col_from_lot(h.lot_code);

        int neighbors = 0;

        // find neighbors to that house
        for (int i = max(0, r - 1); i <= min(r + 1, ROWS); i++) {
                for (int j = max(0, c - 1); j <= min(c + 1, COLS); j++) {
                        if ((i != r and j != c)
                            and all_houses[i][j].availability == "booked"
                            and all_houses[i][j].no_house_here == false) {
                                neighbors++;
                        }
                }
        }

        return neighbors;
}

// rent_house
// Purpose:     Rents a house with a given id if it exists and is available
// Parameters:  House id and 2D array of houses
// Returns:     0 if the house does not exist
//              1 if successfully booked
//              2 if already booked but exists
int rent_house(int house_id, House all_houses[ROWS][COLS])
{
        House h = find_house(house_id, all_houses);

        if (h.id < 0) return 0; // if the house does not exist

        int row = row_from_lot(h.lot_code);
        int col = col_from_lot(h.lot_code);


        if (all_houses[row][col].availability == "available") {
                all_houses[row][col].availability = "booked";
                return 1; // if exists and available
        }

        return 2; // if booked but exists
}

// max
// Purpose:     Determines the max of two integers
// Parameters:  Two integers
// Returns:     The greater of the two integers
int max(int a, int b)
{
        if (a > b) return a;
        return b;
}

// min
// Purpose:     Determines the min of two integers
// Parameters:  Two integers
// Returns:     The lesser of the two integers
int min(int a, int b)
{
        if (a < b) return a;
        return b;
}

// print_availability
// Purpose:     Takes a house id from the user.
//              Calls is_available to determine whether a house with a matching
//              id is available. Prints results to console.
// Parameters:  all_houses
// Effects:     Print to console. Function calls.
void print_availability(House all_houses[ROWS][COLS])
{
        int id;

        cin >> id;

        // determine whether the house is available
        bool available = is_available(id, all_houses);

        if (available) {
                cout << "House " << id << " is available" << endl;
        } else {
                cout << "Sorry, House " << id << " is not available" << endl;
        }
}

// print_matching_houses
// Purpose:     Takes a price, color, and number of bedrooms from console.
//              Finds the number of houses matching these conditions.
//              Prints these results.
// Paremeters:  all_houses
// Effects:     Input and output to console
void print_matching_houses(House all_houses[ROWS][COLS])
{
        float price;
        string color;
        int bedrooms;
        int num;
        House houses[ROWS * COLS];

        cin >> price >> color >> bedrooms;
        
        num = matching_houses(price, color, bedrooms, all_houses, houses);

        cout << "Matching Houses:" << endl;

        for (int i = 0; i < num; i++) {
                print_house(houses[i]);
        }
}

// print_num_neighbors
// Purpose:     Print the number of neighbors to a house.
//              Takes a house id from console and determines the number of
//              neighbors to a house with the matching id. Prints those results.
// Parameters:  The number of neighbors
// Effects:     Prints to console
void print_num_neighbors(House all_houses[ROWS][COLS])
{
        int h_id;
        int neighbors;

        cin >> h_id;

        neighbors = num_neighbors(h_id, all_houses);

        if (neighbors == 0) {
                cout << "You have no neighbors, practice your drums!" << endl;
        } else {
                cout << "You have " << neighbors << " neighbors!" << endl;
        }
}

// print_rent_result
// Purpose:     Print the results of renting a house. Takes an id input from
//              console and uses that to rent a house.
// Parameters:  all_houses
// Effects:     Prints to console
void print_rent_results(House all_houses[ROWS][COLS])
{
        int h_id;
        int rent_result;
        
        cin >> h_id;
        
        rent_result = rent_house(h_id, all_houses);

        if (rent_result == 0) {
                cout << "You can't rent a house that doesn't exist,"
                     << " but good try" << endl;
        } else if (rent_result == 1) {
                cout << "Congrats, you rented a house!" 
                     << " Hope your door knobs don't fall off" << endl;
        } else {
                cout << "Too late...i hear the dumpster"
                     << " behind hill has some spaces open" << endl;
        }
}
