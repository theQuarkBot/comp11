// printlist.cpp
//      purpose: A number of helper functions for gold.cpp
//  modified by: Neil Powers
//         date: 03/03/21

/*
 * printlist.cpp  -- shows how to read a list of numbers into an array
 *
 *      1. read in data
 *      2. then prints out the list with line numbers using another loop
 *
 *   Exercises:
 *    [a] print the list in reverse
 *    [b] change loop to print out only the birthdays in October
 *    [c] after printing out the October bdays, print a count of how many
 *    [d] change to print the count for each month, not the actual bdays
 *    [e] use a function to do [c]
 *    [f] EXTRA: print which month has the MOST birthdays
 */
#include <iostream>

using namespace std;

const int CAPACITY = 1000;         // change as needed
const int JAN = 1;
const int FEB = 2;
const int MAR = 3;
const int APR = 4;
const int MAY = 5;
const int JUN = 6;
const int JUL = 7;
const int AUG = 8;
const int SEP = 9;
const int OCT = 10;
const int NOV = 11;
const int DEC = 12;
const string MONTHS[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void print_birthdays(int bdays[], int used);
void print_birthdays_reverse(int bdays[], int used);
void print__birthdays_month(int bdays[], int used, int month);
int count_month_bdays(int bdays[], int used, int month);
void print_most_birthdays(int bdays[], int used);
void get_most_birthdays(int bdays[], int used, bool most[]);

int main() 
{
        int bdays[CAPACITY];    // birthday data
        int used;               // number of spaces used so far
        int pos;                // position in array

        // read in CAPACITY values
        pos = 0;
        while (pos < CAPACITY) {
                cin >> bdays[pos];
                pos++;
        }
        used = pos;             // position is how far we got

        // printbirthdays(bdays[], used)
        // print_birthdays_reverse(bdays, used);
        // print_birthdays_month(bdays, used, OCT);
        // cout << count_month_bdays(bdays, used, JUN) << endl;
        print_most_birthdays(bdays, used);
}

/* print_birthdays
 * Parameters: Birthdays and slots used in the array.
 * Purpose:    Print all the birthdays in order of being entered into the array.
 */
void print_birthdays(int bdays[], int used)
{
        int pos = 0;
        while (pos < used) {
                cout << pos << ". " << bdays[pos] << endl;
                ++pos;
        }
}

/* print_birthdays_reverse
 * Parameters: Pirthdays and slots used in the array.
 * Purpose:    Print all the birthdays in reverse order of print_birthdays.
 */
void print_birthdays_reverse(int bdays[], int used)
{
        while (used > 0) {
                used--;
                cout << used << ". " << bdays[used] << endl;
        }
}

/* print_birthdays_month
 * Parameters: Birthdays, slots used, and a specific month.
 * Purpose:    Print every birthday in a particular month.
 */
void print_birthdays_month(int bdays[], int used, int month)
{
        int pos = 0;
        while (pos < used) {
                if (bdays[pos] / 100 == month) {
                        cout << bdays[pos] << endl;
                }
                ++pos;
        }
}

/* count_month_bdays
 * Parameters: bdays, used slots in bdays, and a specific month.
 * Purpose:    Counts the number of birthdays in a particular month.
 * Returns:    An integer number.
 */
int count_month_bdays(int bdays[], int used, int month)
{
        int pos = 0, i = 0;
        while (pos < used) {
                if (bdays[pos] / 100 == month)
                        i++;
                ++pos;
        }

        return i;
}

/* print_most_birthdays
 * Parameters: bdays, and used slots in bdays
 * Purpose:    Print the month(s) with the most birthdays.
 */
void print_most_birthdays(int bdays[], int used)
{
        bool most[12];

        for (int i = 0; i < 12; i++)
                most[i] = false;

        get_most_birthdays(bdays, used, most);

        cout << "Month(s) with most birthdays:" << endl;

        for (int i = 0; i < 12; i++) {
                if (most[i]) {
                        cout << "    " << MONTHS[i] << " with "
                             << count_month_bdays(bdays, used, i + 1) << endl;
                }
        }
}

/* get_most_birthdays
 * Parameters: bdays, used slots in bdays, and a boolean array with 12 values,
 *             where being set to true means a month has the most birthdays.
 * Purpose:    Compute which months have the most birthdays and represent those
 *             on a provided array (most[]).
 * Returns:    Nothing
 * Effects:    Changes values in a given array (most)
 */
void get_most_birthdays(int bdays[], int used, bool most[])
{
        int max = 0;
        for (int i = 0; i < 12; i++) {
                int num_month = count_month_bdays(bdays, used, i + 1);
                if (num_month > max)
                        max = num_month;
        }

        for (int i = 0; i < 12; i++) {
                int num_month = count_month_bdays(bdays, used, i + 1);
                if (num_month == max)
                        most[i] = true;
        }
}
