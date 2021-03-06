/*
 * string_converter.cpp
 * Program to test the string_to_int function, whose contract appears below
 * Essential idea:  extract digits from a string and return the integer that
 *                  results.  E. g., "a1b2c3" should produce the integer 123
 *
 * By:  Neil Powers
 */

#include <iostream>

using namespace std;

int string_to_int(string s);
void print_int(int i);
string get_string();
void testing(string s, int val);

/*
 * main function tests the string_to_int function
 */
int main()
{
        // test cases for string_to_int
        testing("E10", 10);
        testing("comp11issoc00L", 1100);
        testing("ericmetajisgr8", 8);
        testing("cann0L15", 15);

        return 0;
}

/* string_to_int
 * Purpose:   extract an integer from the digit characters in a string
 * Arg:       string that may or may not contain digit characters ('0' -- '9')
 * Returns:   the integer that result from extracting digits from string s
 * Notes:     only digit characters are considered.  
 *            Sign characters ('+', '-') are non-digits and are ignored
 * Examples:  "123abc56"   => 12356
 *            "   2times3" => 23
 *            "help me!"   => 0
 *            ""           => 0
 */
int string_to_int(string s)
{
        int out = 0;
        
        // loop through each character of the string
        // if the character is a number (0-9) add that number to the end of the
        // result by multiplying the previous result by ten
        // e.g. "12" => out = 0 * 10 + 1 = 1 => out = 1 * 10 + 2 = 12
        for (int i = 0; i < (int)s.length(); i++) {
                if (s[i] >= 48 and s[i] <= 57) {
                        out = out * 10 + (s[i] - 48);
                }
        }

        return out;
}

/* get_string
 * Purpose:     get a string from an input (cin)
 * Returns:     a string from a user input
 */
string get_string()
{
        string s;
        cin >> s;
        return s;
}

/* print_int
 * Purpose:     prints an integer
 * Returns:     nothing
 * Effects:     cout
 */
void print_int(int i)
{
        cout << i << endl;
}

/* testing
 * Purpose:     test a case for string_to_int and report failure or sucess
 * Returns:     nothing
 * Effects:     calls other functions; outputs 2 lines
 */
void testing(string s, int val)
{
        int num = string_to_int(s);

        cout << "TESTING: " << s << endl;

        if (num == val) {
                cout << "SUCCESS: " << num << endl;
        } else {
                cout << "FAILURE: " << num << endl;
        }
}
