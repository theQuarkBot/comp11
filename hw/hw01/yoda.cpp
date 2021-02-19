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

int main()
{
    string w1, w2, w3, w4;
    
    cout << "Type in four words: ";
    cin >> w1 >> w2 >> w3 >> w4;
    
    cout << w4 << " " << w3 << " " << w2 << " " << w1 << endl;
    
    return 0;
}