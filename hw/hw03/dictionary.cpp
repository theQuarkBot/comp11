// dictionary.cpp
//      purpose: Get a word from a user and define it.
//  modified by: Neil Powers
//         date: 03/01/21
//        notes: No bugs

#include <iostream>
// #include <array>
// #include <string>

using namespace std;

string GetWord();
void DefineWord(string word);
string ToLower(string word);
int GetLocation(string word, string words[]);
void PrintDefinition(int location, string definitions[]);

int main()
{
        DefineWord(GetWord());
}

/* GetWord
 * Parameters: None
 * Purpose:    Get a word from a user.
 * Returns:    A single string.
 */
string GetWord()
{
        string word;
        cin >> word;
        return word;
}

/* DefineWord
 * Parameters: A word
 * Purpose:    Print the definition of a word if it is found in a dictionary.
 * Returns:    Nothing
 * Notes:      words[] and definitions[] could probably be moved to a separate
 *             function or file.
 */
void DefineWord(string word)
{
        string words[] = {"variable",
                          "function",
                          "recursion",
                          "pseudocode",
                          "conditional",
                          "comp11",
                          "parameter"};

        string definitions[] = {
                "A location in the computer's memory that can store a value",
                "A named block of code that can be invoked as a statement or "
                        "within an expression",
                "A situation in which a definition refers to the term it is "
                        "defining",
                "Plain text code intended to be easlily readeable and "
                        "understood by people",
                "A method to execute a block of code depending on the outcome "
                        "of an expression",
                "An introduction to computer science",
                "An argument fed into a function to let it access necessary "
                        "data"
        };

        int word_location = GetLocation(ToLower(word), words);

        PrintDefinition(word_location, definitions);
}

/* ToLower
 * Parameters: A string
 * Purpose:    Convert the string to all lowercase; only affects letters.
 * Returns:    The same word but lowercase.
 */
string ToLower(string word)
{
        for (int i = 0; i < (int)word.length(); i++)
        {
                if (word[i] <= 96 and word[i] >= 65)
                        word[i] += 32;
        }
        return word;
}

/* GetLocation
 * Parameters: A string and an array of strings.
 * Purpose:    Return the location of a string if it appears in words.
 * Returns:    -1 if it is not found, else the location of the word.
 */
int GetLocation(string word, string words[])
{
        for (int i = 0; i < *(&words + 1) - words; i++) // Had to look this up
        {
                if (word == words[i])
                        return i;
        }
        
        return -1;
}

/* PrintDefinition
 * Parameters: An integer location - the location of a definition in an array
 *             of definitions.
 * Purpose:    Prints the definition of a word given by location.
 * Returns:    null.
 */
void PrintDefinition(int location, string definitions[])
{
        if (location == -1)
        {
                cout << "Definition Not Found" << endl;
        }
        else
        {
                cout << definitions[location] << endl;
        }
}