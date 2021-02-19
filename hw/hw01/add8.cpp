// add8.cpp
//      purpose: add 8 floating point numbers (can be varied to other amounts)
//        shows: use of input, output, and for loops
//         note: to change the amount of numbers to add, change REPETITIONS
//
//  modified by: Neil Powers
//         date: 02/13/21

#include <iostream>

using namespace std;

float addInputs(int reps);

int main()
{
    const int REPETITIONS = 8;
    
    float sum = addInputs(REPETITIONS);
    
    cout << "The sum is: " << sum << endl;
    
    return 0;
}

float addInputs(int reps)
{
    float sum = 0;
    
    for (int i = 0; i < reps; i++)
    {
        float tempNum;
        cout << "Enter a floating point number: ";
        cin >> tempNum;
        sum += tempNum;
    }
    
    return sum;
}