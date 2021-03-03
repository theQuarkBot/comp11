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

void print_birthdays(int bdays[], int used);
void print_birthdays_reverse(int bdays[], int used);
void print__birthdays_month(int bdays[], int used, int month);
int count_month_dates(int bdays[], int used, int month);

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
        cout << count_month_dates(bdays, used, OCT) << endl;
}

void print_birthdays(int bdays[], int used)
{
        int pos = 0;
        while (pos < used) {
                cout << pos << ". " << bdays[pos] << endl;
                ++pos;
        }
}

void print_birthdays_reverse(int bdays[], int used)
{
        while (used > 0) {
                used--;
                cout << used << ". " << bdays[used] << endl;
        }
}

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

int count_month_dates(int bdays[], int used, int month)
{
        int pos = 0, i = 0;
        while (pos < used) {
                if (bdays[pos] / 100 == month)
                        i++;
                ++pos;
        }

        return i;
}