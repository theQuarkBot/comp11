/*
 * recursion.cpp
 * Purpose:     A number of random functions for learning recursion.
 * Modified by: Neil Powers
 * Bugs:        N/A
 */

#include <iostream>

using namespace std;

int Multiply(int x, int y);
int Power(int x, int k);
int SumFrom(int a, int b);
// int DoubleDigits(int n);

int main()
{
        // cout << Multiply(100, 4) << endl;
        // cout << Power(2, 3) << endl;
        cout << SumFrom(2, 6) << endl;
}

/* Multiply
 * Parameters: Two positive integers.
 * Purpose:    Multiply two positive numbers using only addition.
 * Returns:    An integer.
 */
int Multiply(int x, int y)
{
        if (x == 0 or y == 0)
        {
                return 0;
        }
        else if (x == 1 or y == 1)
        {
                return x + y - 1;
        } 
        else
        {
            return x + Multiply(x, y - 1);
        }
}


int Power(int x, int k)
{
        if (k == 0)
        {
                return 1;
        }
        else if (x == 0 or x == 1 or k == 1)
        {
                return x;
        }
        else
        {
                return x * Power(x, k - 1);
        }
}


int SumFrom(int a, int b)
{
        if (a == b)
        {
                return b;
        }
        else if (a > b)
        {
                return b + SumFrom(b + 1, a);
        }
        else
        {
                return a + SumFrom(a + 1, b);
        }
}


// int DoubleDigits(int n)
// {

// }