// welcome.cpp
//
// Purpose: Welcome the squad to their new favorite class.
// Author:  Megan Monroe (mmonroe)
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
        string name;
        
        // Get the user's name
        cout << endl;
        cout << "Hello!";
        cout << endl;
        cout << "Please enter your name: ";
        cin >> name;

        // Print the welcome message
        cout << endl;
        cout << "Hi " << name << "!  ";
        cout << "Welcome to Comp 11 you filthy animal" << endl;
        cout << endl;

        return 0;
} 
