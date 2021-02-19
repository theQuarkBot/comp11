// bicycles.cpp
//      purpose: count the number of bicycles that can be made given available materials.
//        shows: number of bicycles and leftover parts.
//         note: 
//
//  modified by: Neil Powers
//         date: 02/18/21

#include <iostream>

using namespace std;

const int NUM_WHEELS = 2;
const int NUM_FRAMES = 1;
const int NUM_LINKS  = 50;
const string WHEEL   = "wheel";
const string FRAME   = "frame";
const string LINK    = "link";

int getInt(string prompt);
int possibleBikes(int wheels, int frames, int links);
string leftoverPart(int bikes, int part, string partName);

int main()
{
        int wheels;
        int frames;
        int links;
        int bikes;

        // Prompt the user for how many of each part they have.
        wheels = getInt("Enter the number of wheels: ");
        frames = getInt("Enter the number of frames: ");
        links = getInt("Enter the number of links: ");

        bikes = possibleBikes(wheels, frames, links);

        string remainingWheels = leftoverPart(bikes, wheels, WHEEL);
        string remainingFrames = leftoverPart(bikes, frames, FRAME)
        string remainingLinks = leftoverPart(bikes, links, LINK);
        
}

/* getInt
 * Parameters: A prompt to be printed to the console.
 * Purpose:    Get a user input (int) based on a prompt.
 * Returns:    An integer console input.
 */
int getInt(string prompt)
{
        int out;
        
        cout << prompt;
        cin >> out;
        
        if (out < 0) {
                cout << "You have to enter a positive number." << endl;
                return getInt(prompt);
        }
        
        return out;
}

/* possibleBikes
 * Parameters: The number of wheels, frames, and links available.
 * Purpose:    Calculate the number of bikes that can be made.
 * Returns:    The number of bikes that can be made.
 */
int possibleBikes(int wheels, int frames, int links)
{
        int bikes = 0;
        
        bikes = wheels / NUM_WHEELS;
        if (frames / NUM_FRAMES < bikes)
        {
                bikes = wheels / NUM_FRAMES;
        } else if (links / NUM_LINKS < bikes)
        {
                bikes = links / NUM_LINKS;
        }
        
        return bikes;
}

string leftoverPart(int bikes, int part, string partName)
{
        string out = "";
        int leftover = 0;
        
        leftover = part - bikes * getNumPart(partName);
        
        
}

int getNumPart(string partName)
{
        if (partName == NUM_WHEELS) return NUM_WHEELS;
        else if (partName == NUM_FRAMES) return NUM_FRAMES;
        else return NUM_LINKS;
}