/*
 * A linked-list based implementation of a class that keeps track of 
 * word-frequecy data.
 * 
 * The data are stored as a singly-linked sequence of nodes accessed
 * from a single pointer (in the data member 'front') to the first
 * node in the list (or the nullptr if the list is empty).  Each node
 * has a word (stored as a string), and an integer representing the
 * number of times that word has been counted.
 *
 * IMPORTANT INVARIANT:
 * The words are in the list in alphabetical order. 
 *
 * Mark A. Sheldon, Tufts Uiversity, Spring 2021
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
#include <cstdlib>

#include "WordFreqLinkedList.h"

using namespace std;

/*
 * Purpose:  Constructor initializes an empty list
 */
WordFreqLinkedList::WordFreqLinkedList()
{
        // TODO
}

/*
 * Purpose:  Destructor recycles the space associated with all nodes
 *           in the list
 */
WordFreqLinkedList::~WordFreqLinkedList()
{
        // TODO
}

/*
 * Purpose:  Return the current size of the list, 
 *           i. e., the number of words/nodes in the list
 */
int WordFreqLinkedList::size()
{
        // TODO
}

/*
 * Purpose:  Register one more occurrence of the given word
 *           If word is already in list, it's frequency is incremented by one
 *           If word is not in list, it is added with a frequency of 1
 *           Words are always added in alphabetical order, that is
 *           adding a new word means it goes in front of the first
 *           word that compares > than the new word, or at the end of
 *           the list if this word comes after all the words in the
 *           list alphabetically.
 * Params:   The string word to be added to the list
 * Effects:  Modifies a frequency in the list or adds a new element
 */
void WordFreqLinkedList::countOccurrence(string word)
{
        // TODO
}


/*
 * Purpose:  Return the index-th element of the list
 * Params:   index must be in range [0 .. size) where
 *           size is the number of words stored in the list
 * Effects:  if index is out of range, prints error message and exits program
 *           otherwise, none
 */
WordFreq WordFreqLinkedList::get(int index)
{
        // TODO
}

/*
 * Purpose:  Remove word from the list.  That is, it removes and 
 *           recycles the node containing the word (and its count)
 */
void WordFreqLinkedList::remove(string word)
{
        // TODO
}


/*
 * Purpose:  print out the underlying list on cout
 * Effects:  prints to cout
 * Notes:    this function is here for debugging purposes.
 *           It will not be called in the final version of the wordfreq
 *           program.
 *           Still LEAVE IT AS-IS:  WE WILL USE IT FOR TESTING.
 */
void WordFreqLinkedList::debugPrint()
{
        Node *curr = front;

        cout << "[";
        while (curr != nullptr) {
                cout << "{" << curr->data.word << ", "
                     << curr->data.freq << "}";
                if (curr->next != nullptr)
                        cout << ", ";
                curr = curr->next;
        }
        cout << "]";
}
