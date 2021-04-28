/*
 * An attempt at optimizing a WordFreqList by using "bins"
 * Idea:  Rather than store all the WordFrequency data in a single
 * linked list, have 26 linked lists and store a word in the list
 * corresponding to its first letter ('a' goes in bin 0, etc.).
 *
 * Assumes that words being stored all start with a lowercase letter.
 * If this idea pans out, we can relax that, but not this semester.
 *
 * Mark A. Sheldon, Tufts University, Spring 2021
 *
 *
 * Student name:
 * Date:
 *
 * Anything else you would like to include
 */

/*************  Fill in the TODO items below  *************/
/***  You may add additional private member functions   ***/
/**********************************************************/
#include <iostream>
#include <string>

#include "BinnedWordFreqList.h"
#include "WordFreqLinkedList.h"

using namespace std;

WordFreqList::WordFreqList()
{
        // Nothing to do here
        // linked list constructor initializes each instance in
        // my array
}

WordFreqList::~WordFreqList()
{
        // Nothing to do here
        // linked list destructor recycles its own storage
        // when this instance goes out of scope
}



/*
 * Purpose:  Return total number of words stored in the word-frequency list
 */
int WordFreqList::size()
{
        // TODO Replace the following code with your solution
        cout << "ERROR:  Student code for 'size' not implemented" << endl;
        return -1;
}

/*
 * Purpose:  register a new occurrence of word
 *           If word is already in list, it's frequency is incremented by one
 *           If word is not in list, it is added with a frequency of 1
 * Params:   word must be non-empty and begin with a lowercase letter
 * Effects:  Modifies a frequency in the list or adds a new element
 */
void WordFreqList::countOccurrence(string word)
{
        // TODO Replace the following code with your solution
        cout << "ERROR:  student code for 'countOccurrence' not implemented"
             << endl;
}

/*
 * Purpose:  Return the index-th element of the list
 * Params:   index must be in range [0 .. size) where
 *           size is the number of words stored in the list
 * Effects:  if index is out of range, prints error message and exits program
 *           otherwise, none
 */
WordFreq WordFreqList::get(int index)
{
        // TODO Replace the following code with your solution
        cout << "ERROR:  student code for 'get' not implemented" << endl;
        return {"--ERROR--", -1};
}


/*
 * Purpose:  print out the underlying list on cout
 * Effects:  prints to cout
 * Notes:    this function is here for debugging purposes
 *           It will not be called in the final version of the wordfreq
 *           program 
 *           Leave it here:  we will call it in our testing
 */
void WordFreqList::debugPrint()
{
        cout << "Frequency table contains:  " << endl;
        for (int i = 0; i < NUM_BINS; ++i) {
                cout << "    Bin " << i << ":  ";
                wflists[i].debugPrint();
                cout << endl;
        }
}
