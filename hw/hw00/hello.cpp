/*
 * First c++ program
 * 
 * Purpose: Simple command-line introduction
 * Author: Neil Powers (npower03)
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "Neil";
    string year = "Freshman";
    string food = "black-eyed pea fritters";
    string from = "Houston, TX";
    
    cout << "Hi, I'm " << name << ", a " << year << " at Tufts University.";
    cout << "\nI'm from quite far away, all the way down in " << from << ".";
    cout << "\nMy major is undecided, but I do know I love " << food << ".";
    cout << "\nIt's gonna be a pleasure to learn c++ here!\n";
    
    // P.S. I've always wanted to learn to use the command line but never had
    // the courage to start leaning it. Glad I'm forced to learn it now :P
    
    return 0;
}
