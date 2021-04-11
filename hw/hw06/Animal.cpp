//*********************************************************************
//
//                       Animal.cpp
//       
//        Member function and constructor implementations for 
//        the Animal class.
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

// *************************************************************************
//                   Constructor implementations
//
//     There are two constructors for this class. The "no arguments"
//     constructor we implement for you immediately below. DO NOT
//     modify this constructor
//
//     The constructor that uses file data to initialize the Animal
//     you must write!
//
// *************************************************************************

//
//                        Animal::Animal
//
//       This no arguments constructor is called, among other situations
//       when an array of Animals is created.
//
Animal::Animal()
{
        m_name           = "UNINITIALIZED";
        m_origin         = "UNINITIALIZED";
        m_diet           = "UNINITIALIZED";
        m_ear_size       = "UNINITIALIZED";
        m_classification = "UNINITIALIZED";
}


// -------------------------------------------------------------------------
//                          REQUIRED STUDENT CODE
//
//     Fill in the body of this constructor to initialize all
//     Animal data members from the supplied file.
// -------------------------------------------------------------------------

Animal::Animal(ifstream& input_file)
{

         //                  YOUR CODE HERE


         // DELETE THE FOLLOWING CODE AND THIS COMMENT, AND
         // REPLACE WITH YOUR CODE TO INITIALIZE A SINGLE ANIMAL
         // BY READING DATA VALUES FROM THE OPEN FILE
         //
         // YOU DO NOT NEED TO CHECK FOR END OF FILE OR ERRORS,
         // JUST READ THE VALUES FROM THE STREAM
         //

        (void)input_file;
        cout << "ERROR: Animal constructor called but "
                "student code not implemented"
             << endl;
        
}


// *************************************************************************
//                   Accessor functions
// *************************************************************************

// -------------------------------------------------------------------------
//                   REQUIRED STUDENT CODE
//
//     Fill in each of the accessor functions below with
//     code to return the appropriate data.
//     You do not have to provide function contracts, just implement
//     the functions.
// -------------------------------------------------------------------------


string Animal::name()
{
        // YOUR CODE HERE
        return "";       // REPLACE THIS
}

string Animal::origin()
{
        // YOUR CODE HERE
        return "";       // REPLACE THIS
}

string Animal::diet()
{
        // YOUR CODE HERE
        return "";       // REPLACE THIS
}

string Animal::ear_size()
{
        // YOUR CODE HERE
        return "";       // REPLACE THIS
}

string Animal::classification()
{
        // YOUR CODE HERE
        return "";       // REPLACE THIS
}

// *************************************************************************
//                        Other Member Functions
//
//           NO UPDATES SHOULD BE REQUIRED TO THE CODE BELOW.
//           THIS PRINTS IN THE CORRECT FORMAT.
// *************************************************************************

//
//                        Animal::print
//
//       Print all information about the animal to cout
//
//
void Animal::print()
{
        cout << "name=" << m_name 
             << " origin=" << m_origin
             << " diet=" << m_diet
             << " ear_size=" << m_ear_size
             << " classification=" << m_classification
             << endl;
}
