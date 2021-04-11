//*********************************************************************
//
//                       Animal.cpp
//       
//        Member function and constructor implementations for 
//        the Animal class.
//
//  Author:     Neil Powers
//  Date:       04/11/2021
//
//  Purpose:    Implementation for Animal object;
//              Creates an animal with a provided name, origin, diet
//              ear_size, and classification.
// 
//  Known bugs: None
//
//  Testing performed: Yes
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
        input_file >> m_name
                   >> m_origin
                   >> m_diet
                   >> m_ear_size
                   >> m_classification;

        // if (m_name              == "UNINITIALIZED"
        //     or m_origin         == "UNINITIALIZED"
        //     or m_diet           == "UNINITIALIZED"
        //     or m_ear_size       == "UNINITIALIZED"
        //     or m_classification == "UNINITIALIZED") {
                // cerr << "ERROR: Animal constructor called but "
                        // "animal could not be read."
                //      << endl;
        //     }
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
        return m_diet;
}

string Animal::ear_size()
{
        return m_ear_size;
}

string Animal::classification()
{
        return m_classification;
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
        cout << "name="            << m_name 
             << " origin="         << m_origin
             << " diet="           << m_diet
             << " ear_size="       << m_ear_size
             << " classification=" << m_classification
             << endl;
}
