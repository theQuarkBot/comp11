// iftest.cpp
//      purpose: report number of digits in an integer
//        shows: use of output, input, conditional
//
//  modified by: Neil Powers
//         date: 02/13/21

#include <iostream>

using namespace std;

int countDigits(int input);
void printDigits(int digits);
void printSign(int input);

int main()
{
        int input;
        int digits;

        // gets user input
        cout << "Enter a number: ";
        cin  >> input;
        
        // counts number of digits in input
        digits = countDigits(input);
        
        // prints results to console
        printDigits(digits);
        printSign(input);

        return 0;
}

// counts digits in integer input.
int countDigits(int input)
{
        int digits = 0;
        while (input != 0)
        {
                input /= 10;
                digits++;
        }
        
        return digits;
}

// prints number of digits up to three
void printDigits(int digits)
{
        if (digits == 1) cout << "input has one digit" << endl;
        else if (digits == 2) cout << "input has two digits" << endl;
        else cout << "input has three or more digits" << endl;
}

// prints sign if negative
void printSign(int input)
{
        if (input < 0) cout << "and input is negative" << endl;
}
