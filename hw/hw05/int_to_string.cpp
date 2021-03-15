/*
 * int_to_string.cpp
 * Program to test the int_to_string function, whose contract appears below
 * Essential idea:  Given an integer, like 87, return the string
 * consisting of the same digits, i. e., "87".
 *
 * By:  Neil Powers
 */

#include <iostream>

using namespace std;

string int_to_string(int num);
string int_to_string_recursive(int num);
void testing(int number, string correct_output);

/*
 * main function tests the int_to_string function
 */
int main()
{
        // test cases for int_to_string
        testing(123, "123");
        testing(0, "0");
        testing(-104, "-104");
        testing(100, "100");

        return 0;
}

/* int_to_string
 * Purpose:     convert an integer to a string, while preserving sign.
 * Args:        any real integer
 * Returns:     a string result of converting the int to string
 * Examples:    123 => "123"
 *              0 => "0"
 *              -123 => "-123"
 *              001 => "1"
 */
string int_to_string(int num)
{
        bool negative = false;

        // determine if number is negative; make positive if true
        if (num == 0) return "0";
        else if (num < 0) {
                negative = true;
                num *= -1;
        }

        string out = "";
        
        // convert every number to a character and concetenate them.
        while (num != 0) {
                char cur = (num % 10) + 48;
                out = cur + out;
                num = num / 10;
        }

        // add negative sign to string if it is negative
        if (negative) out = "-" + out;

        return out;
}

/* int_to_string_recursively
 * Purpose:     recursively convert an integer to a string, while
 *              preserving sign.
 * Args:        any real integer
 * Returns:     a string result of converting the int to string
 * Examples:    123 => "123"
 *              0 => "0"
 *              -123 => "-123"
 *              001 => "1"
 */
string int_to_string_recursive(int num)
{
        // determine if number is zero or negative. If not, convert the last
        // digit to integer and add that to the end of the string.
        if (num == 0) {
                return "0";
        } else if (num < 0) {
                return "-" + int_to_string(num * -1);
        } else {
                char cur = num % 10 + 48;
                return int_to_string(num / 10) + cur;
        }
}

/* testing
 * Purpose:     compare the result of int_to_string with the correct result
 * Args:        a test case and the correct result
 * Returns:     nothing
 * Effects:     outputs test case, result (success/failure and output)
 */
void testing(int number, string correct_output)
{
        string output = int_to_string(number);

        cout << "TESTING: " << number << endl;

        if (output == correct_output) {
                cout << "SUCCESS: " << output << endl;
        } else {
                cout << "FAILURE: " << output << endl;
        }
}
