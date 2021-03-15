/*
 * most_common_int.cpp
 * Program to test the most_common_int function, whose contract appears below
 * Essential idea: Search an array for something and keep track of every
 * element
 *
 * By:  Neil Powers
 */

#include <iostream>
// #include <cstdlib>
// #include <ctime>

using namespace std;

const int MAX_NUM       = 1000;
const int MAX           = 1000;
const int MIN           = 0;

int most_common_int(int numbers[], int length);
void print_array(int numbers[], int length);
void testing(int array[], int array_len, int correct_num);
// void randomize_array(int numbers[], int length);

int main()
{
        // srand(time(nullptr));

        // initialize test cases
        int array_len1        = 10;
        int array1[]          = {1, 4, 5, 2, 1, 9, 8, 1, 7, 6};

        int array_len2        = 9;
        int array2[]          = {1, 3, 2, 2, 3, 4, 4, 2, 7};

        int array_len3        = 8;
        int array3[]          = {6, 99, 999, 998, 998, 1, 1, 998};

        int array_len4        = 1;
        int array4[]          = {1};

        // test cases for most_common_int
        testing(array1, array_len1, 1);
        testing(array2, array_len2, 2);
        testing(array3, array_len3, 998);
        testing(array4, array_len4, 1);

        // make an array of random numbers of some length
        // int test_array_len   = rand() % (MAX_NUM + 1);
        // int test_array[test_array_len];

        // cout << most_common_int(test_array, test_array_len) << endl;
}

/* most_common_int
 * Purpose:     find the most common integer in an array of numbers
 * Returns:     the most common number in the array
 * Example:     {1, 4, 5, 2, 1, 9, 8, 1, 7, 6} => 1
 */
int most_common_int(int numbers[], int length)
{
        int count[MAX_NUM] = {0};
        int max = 0;

        // count how many of each number there are
        // save counts to a separate array which includes every possible number
        for (int i = 0; i < length; i++) {
                ++count[numbers[i]];
                if (count[numbers[i]] > max) max = count[numbers[i]];
        }

        // find the first number with the maximum count in the new array
        for (int i = 0; i < MAX_NUM; i++) {
                if (count[i] == max) return i;
        }

        return -1;
}

/* print_array
 * Purpose:     print an array of some length, each entry separated by a space.
 * Returns:     nothing
 * Effects:     cout
 * Example:     {1, 2, 3} prints " 1 2 3"
 */
void print_array(int numbers[], int length)
{
        for (int i = 0; i < length; i++) {
                cout << " " << numbers[i];
        }

        cout << endl;
}

/* testing
 * Purpose:     test the functionalality of the most_common_int function
 * Returns:     nothing
 * Effects:     prints to consol and function calls
 */
void testing(int array[], int array_len, int correct_num)
{
        // find the most common int in the array
        int most_common = most_common_int(array, array_len);

        // print results
        cout << "TESTING:";
        print_array(array, array_len);

        if (most_common == correct_num) {
                cout << "SUCCESS: " << most_common << endl;
        } else {
                cout << "FAILURE: " << most_common << endl;
        }

        
}

// I previously used this to randomize an array. No longer in use.
// void randomize_array(int numbers[], int length)
// {
//         for (int i = 0; i < length; i++) {
//                 numbers[i] = rand() % (MAX + 1) + MIN;
//         }
// }
