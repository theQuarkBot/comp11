/*
 * Preliminary program that reads in the standard input one whitespace 
 * delimited string at a time and prints the lowercase version of those 
 * that begin with a letter.
 * 
 * Only works for ASCII --- Real text is hard!
 *
 * Name: Neil Powers
 * Date: Apr 15, 2021
 * Notes: N/A
 */

#include <iostream>

using namespace std;

bool is_word(string s);
string to_lowercase(string s);

int main()
{
    string word;
    
    // Read every word of a file until the end of a file.
    // If it starts with a letter, print the lowercase version of the word.
    cin >> word;
    while (not cin.eof()) {
        if (is_word(word)) {
            cout << to_lowercase(word) << endl;
        }
        cin >> word;
    }

    return 0;
}

// *************************************************************
//                          is_word
//
// Returns whether a string starts with a letter
//
// Parameters:  A string to check
// Outputs:     None
// Effects:     Returns a boolean
//
// *************************************************************
bool is_word(string s)
{
    // Determines if the first character is a letter
    return ((s[0] >= 97 and s[0] <= 122) or (s[0] >= 65 and s[0] <= 90));
}

// *************************************************************
//                        to_lowercase
//
// Converts all letters in a string to lowercase
//
// Parameters:  A string to convert to lowercase
// Outputs:     None
// Effects:     Returns a non_whitespace string with lowercase
//              letters.
//
// *************************************************************
string to_lowercase(string s)
{
    for (int i = 0; i < (int)s.length(); i++) {
        if ((s[i] >= 65) and  (s[i] <= 90)) {
            // Convert character to lowercase.
            s[i] += 32;
        }
    }

    return s;
}
