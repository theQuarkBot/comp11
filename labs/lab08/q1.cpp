// q1.cpp
// Purpose:     Demonstrate reudimentary knowledge of pointers
// Modified By: Neil Powers
// Modified:    03/31/2021

#include <iostream>

using namespace std;

int main()
{
    int m, n;
    int *p1, *p2;

    p1 = &m;
    p2 = &n;
    *p1 = 3;
    *p2 = 5;
    cout << m << " " << n << endl; // prints "3 5"

    return 0;
}
