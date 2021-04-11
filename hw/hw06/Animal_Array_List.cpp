//*********************************************************************
//
//                       Animal_Array_list.cpp
//       
//        Member function and constructor/destructor implementations for 
//        the Animal_Array_List class.
//
//  Author:
//  Date:
//
//  Purpose:
//
//  Known bugs:
//
//  Testing performed:
//
//*********************************************************************

#include <fstream>
#include <iostream>

using namespace std;

#include "Animal.h"
#include "Animal_Array_List.h"


// *****************************************************************
//         STARTER CODE PROVIDES EMPTY FUNCTION BODIES
// *****************************************************************

//                  ****STUDENT CODE NEEDED HERE***             //

//   
//   FILL IN THE REMAINDER OF THIS FILE WITH DEFINITIONS OF 
//   ALL THE MEMBER FUNCTIONS REQUIRED FOR THE AnimalArrayList
//   TYPE.
//
//   You do not need to update the function contracts.  We have not
//   provided full contracts according to the style guide, but
//   we believe the abbreviated contracts are sufficient here.
//   Just complete the functions.
//

//
// Default constructor
//
Animal_Array_List::Animal_Array_List()
{
        //   REPLACE THE FOLLOWING WITH YOUR CODE
        cout << "ERROR: Animal_Array_List constructor called "
             <<  "but student code not implemented"
             << endl;
}

//
// Destructor: Frees heap-allocated memory associated with arraylist
//
Animal_Array_List::~Animal_Array_List()
{
        //   REPLACE THE FOLLOWING WITH YOUR CODE
        cout << "ERROR: Animal_Array_List destructor called "
             <<  "but student code not implemented"
             << endl;
}

//
// Adds a to the back of the list.
// Effects: may expand if necessary
//
void 
Animal_Array_List::add(Animal a)
{
        //   REPLACE THE FOLLOWING WITH YOUR CODE
        (void) a;
        cout << "ERROR: Animal_Array_List::add called "
             <<  "but student code not implemented"
             << endl;
}

//
// Returns the number of Animals currently stored
//
int
Animal_Array_List::num_animals()
{
        //   REPLACE THE FOLLOWING WITH YOUR CODE
        cout << "ERROR: Animal_Array_List::num_animals called "
             <<  "but student code not implemented"
             << endl;
        return 0;       // REPLACE THIS
}

//
// Returns the Animal located at position index  
// 
Animal 
Animal_Array_List::animal_at(int index)
{
        //   REPLACE THE FOLLOWING WITH YOUR CODE
        (void) index;
        cout << "ERROR: Animal_Array_List::animal_at called "
             <<  "but student code not implemented"
             << endl;
        // The following return statement is a placeholder
        // that returns an "empty" animal until
        // you have properly implemented this
        // function. Replace it with a statement
        // returning the requested Animal from the
        // list
        return Animal{};
}

//
// Doubles the capacity of the animals array
//
void
Animal_Array_List::expand()
{
        //   REPLACE THE FOLLOWING WITH YOUR CODE
        cout << "ERROR: Animal_Array_List::expand called "
             <<  "but student code not implemented"
             << endl;
}


//
//                       print
//
//       Ask all the Animals in the list to print themselves
//
void
Animal_Array_List::print()
{
        //   REPLACE THE FOLLOWING WITH YOUR CODE
        cout << "ERROR: Animal_Array_List::print called "
             <<  "but student code not implemented"
             << endl;
}
