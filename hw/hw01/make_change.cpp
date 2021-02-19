// yoda.cpp
//      purpose: reverse a string of four words
//        shows: 
//         note: program could be improved by using an array to store words
//               then reversing the array.
//
//  modified by: Neil Powers
//         date: 02/13/21

#include <iostream>

using namespace std;

void getChange(int change);

int main()
{
    int change; //using float as specified by assignment, takes integer input
    
    cout << "Amount of change in cents: ";
    cin >> change;
    
    getChange((int)change);
    
    return 0;
}

void getChange(int change)
{
    int numQuarters, numDimes, numNickels, numPennies;
    const int QUARTER = 25;
    const int DIME    = 10;
    const int NICKEL  = 5;
    // const int PENNY   = 1;
    
    numQuarters = change / QUARTER;
    change = change % QUARTER;
    
    numDimes = change / DIME;
    change = change % DIME;
    
    numNickels = change / NICKEL;
    change = change % NICKEL;
    
    numPennies = change;
    
    cout << numQuarters << " quarters, "
         << numDimes << " dimes, "
         << numNickels << " nickels, "
         << numPennies << " pennies" << endl;
}
