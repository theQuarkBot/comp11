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
 * Student name: Neil Powers
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
        front = nullptr;
}

/*
 * Purpose:  Destructor recycles the space associated with all nodes
 *           in the list
 */
WordFreqLinkedList::~WordFreqLinkedList()
{
        while (front != nullptr) {
                removeFirst();
        }
}

/*
 * Purpose:  Return the current size of the list, 
 *           i. e., the number of words/nodes in the list
 */
int WordFreqLinkedList::size()
{
        int count = 0;
        for (Node *np = front; np != nullptr; np = np->next) {
                count++;
        }

        numElements = count;
        return count;
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
        // Special case if list is empty.
        if (front == nullptr) {
                front = newNode(word);
                return;
        } // Special case if first node is the given word
        else if (front->data.word == word) {
                front->data.freq++;
                return;
        } else { 
                Node * cur = front;
                Node * new_node = newNode(word);

                while (cur->next != nullptr and cur->next->data.word < word) {
                        // Increment count if word exists
                        // if (cur->next->data.word == word) {
                                // cur->next->data.freq++;
                                // return;
                        // }
                        // Save location of where new node should go
                        // if (new_node->data.word) {
                                cur = cur->next;
                        // }
                }
                // Insert the new node
                new_node->next = cur->next;
                cur->next = new_node;
                return;
        }
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
        size();

        // Exit if index is out of range
        if ((index < 0) or (index >= numElements)) {
                cerr << "index " << index
                     << " out of range [0, " << numElements << ")"
                     << endl;
                _Exit(1);
        }

        // Find the node at position index
        for (Node *np = front; np->next != nullptr; np = np->next) {
                if (index-- == 0) {
                        return np->data;
                }
        }

        // Prevent return error
        cerr << "could not find node." << endl;
        _Exit(1);
}

/*
 * Purpose:  Remove word from the list.  That is, it removes and 
 *           recycles the node containing the word (and its count)
 */
void WordFreqLinkedList::remove(string word)
{
        Node * cur = front;
        Node * prev = nullptr;

        // Special case: Delete head node if it contains word.
        if ((cur != nullptr) and (cur->data.word == word)) {
                front = cur->next;
                delete cur;
                return;
        }
        // Else search for word to be deleted
        while (cur != nullptr and cur->data.word != word) {
                prev = cur;
                cur = cur->next;
        }

        // If word was not found, do nothing;
        if (cur == nullptr) return;

        // Remove node from list
        prev->next = cur->next;

        // Free memory
        delete cur;
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

/*
 * Purpose:  remove the first node of the linked list.
 *           recycles the node by deleting it from memory.
 */
void WordFreqLinkedList::removeFirst()
{
        Node *to_delete = front;
        if (to_delete != nullptr) {
                front = front->next;
                delete to_delete;
                to_delete = nullptr;
        }
}

/*
 * Purpose:   create a new node in the heap containing a provided string
 * Returns:   pointer to a node in the heap
 * Notes:     node is declared with s as word, 1 as frequency. points to null
 */
WordFreqLinkedList::Node * WordFreqLinkedList::newNode(string s)
{
        Node *new_node = new Node();

        new_node->data.word = s;
        new_node->data.freq = 1;
        new_node->next = nullptr;

        return new_node;
}
