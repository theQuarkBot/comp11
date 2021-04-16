/*
 * Preliminary program that reads in the standard input one whitespace 
 * delimited string at a time and prints the lowercase version of those 
 * that begin with a letter.
 * 
 * Only works for ASCII --- Real text is hard!
 *
 * Name: Neil Powers
 * Date: 
 * Notes: N/A
 */
/*************  Put your program below  *************/

#include <iostream>

using namespace std;

bool is_word(string s);
string to_lowercase(string s);

int main()
{
    string word;
    cin >> word;
    while (not cin.eof()) {
        if (is_word(word)) {
            cout << to_lowercase(word) << endl;
        }
        cin >> word;
    }

    return 0;
}

bool is_word(string s)
{
    return ((s[0] >= 97 and s[0] <= 122) or (s[0] >= 65 and s[0] <= 90));
}

string to_lowercase(string s)
{
    for (int i = 0; i < (int)s.length(); i++) {
        if ((s[i] >= 65) and  (s[i] <= 90)) {
            s[i] += 32;
        }
    }

    return s;
}
