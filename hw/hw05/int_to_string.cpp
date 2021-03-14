/*
 * int_to_string.cpp
 * Program to test the int_to_string function, whose contract appears below
 * Essential idea:  Given an integer, like 87, return the string
 * consisting of the same digits, i. e., "87".
 *
 * By:  <Student name here>
 */

#include <iostream>

using namespace std;

string int_to_string(int num);
void testing(int number, string correct_output);

/*
 * main function tests the int_to_string function
 */
int main()
{
        testing(123, "123");
        testing(0, "0");
        testing(-104, "-104");
        testing(100, "100");

        return 0;
}

string int_to_string(int num)
{
        bool negative = false;

        if (num == 0) return "0";
        else if (num < 0) {
                negative = true;
                num *= -1;
        }

        string out = "";
        
        while (num != 0) {
                char cur = (num % 10) + 48;
                out = cur + out;
                num = num / 10;
        }

        if (negative) out = "-" + out;

        return out;
}

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