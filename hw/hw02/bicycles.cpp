// bicycles.cpp
//      purpose: count the number of bicycles that can be made given
//               the available materials.
//        shows: number of bicycles and leftover parts.
//  modified by: Neil Powers
//         date: 02/20/21

#include <iostream>

using namespace std;

const int NUM_WHEELS = 2;
const int NUM_FRAMES = 1;
const int NUM_LINKS  = 50;
const string WHEEL   = "wheel";
const string FRAME   = "frame";
const string LINK    = "link";

int get_int(string prompt);
int possible_bikes(int wheels, int frames, int links);
void print_possible_bikes(int bikes, int wheels, int frames, int links);
string ends_with(int num);

int main()
{
        int wheels;
        int frames;
        int links;
        int bikes;

        // Prompt the user for how many of each part they have.
        wheels = get_int("Enter the number of wheels: ");
        frames = get_int("Enter the number of frames: ");
        links = get_int("Enter the number of links: ");

        bikes = possible_bikes(wheels, frames, links);

        // Prints number of bikes that can be made and remaining parts.
        print_possible_bikes(bikes, wheels, frames, links);

        return 0;
}

/* getInt
 * Parameters: A prompt to be printed to the console.
 * Purpose:    Get a user input (int) based on a prompt.
 * Returns:    An integer console input.
 */
int get_int(string prompt)
{
        int out;
        
        cout << prompt;
        cin >> out;
        
        if (out < 0) {
                cout << "You have to enter a positive number." << endl;
                return get_int(prompt);
        }
        
        return out;
}

/* possibleBikes
 * Parameters: The number of wheels, frames, and links available.
 * Purpose:    Calculate the number of bikes that can be made.
 * Returns:    The number of bikes that can be made.
 */
int possible_bikes(int wheels, int frames, int links)
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

/* print_possible_bikes
 * Parameters: The number of wheels, frames, and links available; num bikes.
 * Purpose:    Print to console the number of bikes that can be made.
 *             Also prints ant leftover parts.
 * Effects:    Console print.
 */
void print_possible_bikes(int bikes, int wheels, int frames, int links)
{
        // I know the assignment recommends using the mod operator but it
        // does not work that well for this application.
        int r_wheels = wheels - (NUM_WHEELS * bikes);
        int r_frames = frames - (NUM_FRAMES * bikes);
        int r_links  = links - (NUM_LINKS * bikes);

        cout << "You can make " << bikes << " bike" << ends_with(bikes) << ". "
                << "There are " << r_wheels << " wheel" << ends_with(r_wheels)
                << ", " << r_frames << " frame" << ends_with(r_frames)
                << ", " << r_links << " link" << ends_with(r_links)
                << " leftover." << endl;
}

/* ends_with
 * Parameters: An integer number.
 * Purpose:    Returns an "s" depending on part plurality.
 * Returns:    "s" or ""
 */
string ends_with(int num)
{
        if (num != 1)
                return "s";
        return "";
}
