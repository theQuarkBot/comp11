/*
 * Interactive tester for WordFreqLinkedList class
 *
 * Makes a single instance of a WordFreqLinkedList and then runs a
 * command loop that allows one to call each of the functions in the
 * interface.  
 *
 * Mark A. Sheldon, Tufts University, Spring 2021
 *
 *
 *
 * TODO:  Students should fill in appropriate test code in the command
 *        loop (see TODO items below).
 *        You may define helper functions to call.  If you do, you
 *        must pass the list by reference using a pointer --- you
 *        cannot pass it by value.
 *        Do keep functions under 30 lines long!
 *
 * Student name:
 * Date:
 *
 * Anything else you would like to include
 */
#include <iostream>

#include "WordFreqLinkedList.h"

using namespace std;

void   command_loop      ();
string get_command       ();
void   prompt_for_command();
string getWord           ();
int    getIndex          ();
void   printWordFreq(WordFreq wf);

// TODO
// Students may add declarations for any helper functions they need
// here.  If you don't need any, it's ok.



// A sentinel value for our command list
const string NO_COMMAND = "";

// The list of interactive commands supported.  They are printed as a
// prompt for each user command.
// If you make more, then you can put more commands before the
// sentinel.
const string COMMANDS[] = {"size",
                           "count Word",
                           "get Index",
                           "remove Word",
                           "print",
                           "quit",
                           NO_COMMAND};

int main()
{
        command_loop();

        return 0;
}

/*
 * Purpose:  Make a WordFreqLinkedList instance and run a command loop:
 *           - prompts for command
 *           - reads command
 *           - executes the command
 *           until a command of "quit"
 */
void command_loop()
{
        string  cmd;
        WordFreqLinkedList list;

        // cout << ("abba" < "aab") << endl;

        // list.countOccurrence("word1");
        // list.countOccurrence("word2");
        // list.countOccurrence("word3");
        // list.countOccurrence("word3");

        while ((cmd = get_command()) != "quit" and not cin.fail()) {
                if (cmd == "size") {
                        cout << "Current size: " << list.size() << endl;
                } else if (cmd == "print") {
                        list.debugPrint();
                        cout << endl;
                } else if (cmd == "count") {
                        string word;
                        cin >> word;
                        list.countOccurrence(word);
                } else if (cmd == "get") {
                        int index;
                        cin >> index;
                        cout << "Word at index " << index << ": " << list.get(index).word << endl;
                } else if (cmd == "remove") {
                        string word;
                        cin >> word;
                        list.remove(word);
                }
        }
}

string get_command()
{
        string cmd;

        prompt_for_command();
        cin >> cmd;

        return cmd;
}

/*
 * Purpose:  print the list of supported commands as a prompt on cout
 */
void prompt_for_command()
{
        for (int i = 0; COMMANDS[i] != NO_COMMAND; ++i)
                cout << "  " << COMMANDS[i] << endl;

        cout << ":  ";
}

/*
 * Purpose:  return a string read from cin
 *           does not prompt
 */
string getWord()
{
        string word;

        cin >> word;

        return word;
}

/*
 * Purpose:  return a integer read from cin
 *           does not prompt
 */
int getIndex()
{
        int index;

        cin >> index;

        return index;
}

/*
 * Purpose:  Print the word and frequency in a WordFreq struct
 *           on cout followed by a single newline
 */
void   printWordFreq(WordFreq wf)
{
        cout << "{" << wf.word << ", " << wf.freq << "}" << endl;
}
