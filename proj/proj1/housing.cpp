//===============================================================
//
//
//                        housing.cpp version
//                     Author: <your name here>
//
//
//     [Student should fill in the header per the style guide]
//
//===============================================================


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
};

//===============================================================
//                      Function Prototypes
//===============================================================

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// read one line of the input_file; return corresponding House
House read_one_house(ifstream& input_file);

// print information about a single house
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


// ============================================================
//     INCLUDE COMP11 TESTING CODE
//
//   LEAVE THIS STATEMENT IN PLACE. IT MUST COME 
//   AFTER YOUR PROTOTYPE FUNCTION DECLARATIONS.
// ============================================================

#include "housing_hooks.hpp"

//======================================================================
//                      END FIXED STARTER CODE
//======================================================================

//======================================================================
//======================================================================
//
//            FOLLOWING THE INSTRUCTIONS PROVIDED FOR THIS 
//            PROJECT, FILL IN THE CODE FOR THE FUNCTIONS BELOW.
//
//======================================================================
//======================================================================


//======================================================================
//                              main 
//======================================================================

int main(int argc, char *argv[])
{
        // If you have function arguments that aren't used yet
        // the g++ compiler complains. The following lines are
        // harmless and they suppress the complaint. You can remove
        // the (void) lines and this comment once you start using
        // the arguments

        (void)argc;
        (void)argv;

        //   =======================================================
        //           YOUR MAIN FUNCTION CODE HERE
        //   =======================================================

        return 0;
}

//======================================================================
//                       YOUR FUNCTIONS HERE
//
//        We give you empty starter code for some of the required
//        functions, but you should add any you need to make your
//        code well organized (if you feel the need!)
//======================================================================


// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// read one line of the input_file; return corresponding House
House read_one_house(ifstream& input_file) {
        // IF YOU HAVE FUNCTION ARGUMENTS THAT AREN'T USED YET
        // THE G++ COMPILER COMPLAINS. THE FOLLOWING LINES ARE
        // HARMLESS AND THEY SUPPRESS THE COMPLAINT. YOU CAN REMOVE
        // THE (VOID) LINES AND THIS COMMENT ONCE YOU START USING
        // THE ARGUMENTS
        (void)input_file;

        // YOUR CODE HERE

        // NOTE: THE COMPILER WON'T COMPILE THIS FUNCTION
        // WITHOUT SOMETHING BEING RETURNED, AND YOU HAVEN'T
        // WRITTEN YOUR FUNCTION YET. JUST TO KEEP THE 
        // COMPILER QUIET UNTIL YOU DO, WE'RE PUTTING IN
        // THESE TWO LINES OF CODE, WHICH RETURN A USELESS
        // EMPTY HOUSE STRUCTURE.
        //
        House dummy;           // DELETE THIS LINE
        return dummy;          // CHANGE THIS TO RETURN THE HOUSE YOU'VE READ
}

// print information about a single house
void print_house(House h)  {
        // IF YOU HAVE FUNCTION ARGUMENTS THAT AREN'T USED YET
        // THE G++ COMPILER COMPLAINS. THE FOLLOWING LINES ARE
        // HARMLESS AND THEY SUPPRESS THE COMPLAINT. YOU CAN REMOVE
        // THE (VOID) LINE AND THIS COMMENT ONCE YOU START USING
        // THE ARGUMENTS
        (void)h;
        
        // YOUR CODE HERE

}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// given a lot code, compute the column and row (respectively)
// in the all_houses array
int
col_from_lot(string lot) {
        // IF YOU HAVE FUNCTION ARGUMENTS THAT AREN'T USED YET
        // THE G++ COMPILER COMPLAINS. THE FOLLOWING LINES ARE
        // HARMLESS AND THEY SUPPRESS THE COMPLAINT. YOU CAN REMOVE
        // THE (VOID) LINE AND THIS COMMENT ONCE YOU START USING
        // THE ARGUMENTS
        (void)lot;

        // YOUR CODE HERE

        return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}

int
row_from_lot(string lot) {
        // REMOVE WHEN IMPLEMENTING
        (void)lot;

        // YOUR CODE HERE

        return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}

//  set the no_house_here marker for every position
//  in the array
void
fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]) {
        // IF YOU HAVE FUNCTION ARGUMENTS THAT AREN'T USED YET
        // THE G++ COMPILER COMPLAINS. THE FOLLOWING LINES ARE
        // HARMLESS AND THEY SUPPRESS THE COMPLAINT. YOU CAN REMOVE
        // THE (VOID) LINES AND THIS COMMENT ONCE YOU START USING
        // THE ARGUMENTS
        (void)rows;
        (void)cols;
        (void)all_houses;

        // YOUR CODE HERE
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
