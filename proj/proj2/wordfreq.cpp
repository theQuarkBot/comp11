/*
 * wordfreq
 *
 * 1. Reads in strings from the standard input (cin)
 *    Ignores non-words (where a "word" is a sequence of non-whitespace
 *    characters beginnig with an upper or lowercase letter
 * 2. Converts each word to lower case
 * 3. Inserts each word into a WordFreqList to track the number of
 *    times each word is seen

 * 4. When the input is fully processed, prints a line for each word
 *    in the WordFreqList formatted thus:
 *    the interger number of occurrences of the word, a single space,
 *    the word itself, a newline.  E. g., "14 we\n"
 *
 * Only works for ASCII --- Real text is hard!
 *
 * Mark A. Sheldon, Tufts University, Spring 2021
 *
 *
 * Student name: Neil Powers
 * Date: Apr 27, 2021
 *
 * Anything else you would like to include
 */

#include <iostream>
#include <string>
#include <cctype>

// The following file will be a copy of the file you want
// DON'T CHANGE THIS!
#include "WordFreqList.h"
// Seriously, Don't change the line above.  It's important!

using namespace std;

/*************  Put your program below  *************/

void wordLoop();
string toLowercase(string s);

int main()
{
    wordLoop();

    return 0;
}

void wordLoop()
{
    WordFreqList list;
    

}

string toLowercase(string s)
{
    for (int i = 0; i < (int)s.length(); i++){
        if ((s[i] >= 'A') and (s[i] <= 'Z')){
            s[i] += 32;
        }
    }

    return s;
}
