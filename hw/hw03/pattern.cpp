// pattern.cpp
//      purpose: Print a pattern based on the specified inputs.
//  modified by: Neil Powers
//         date: 03/02/21
//        notes: No bugs.

#include <iostream>

using namespace std;

const int REPETITIONS = 5;

void make_pattern();
void output_pattern(string s1, string s2, int n);
string print_line(string s1, string s2, int reps_left);

int main()
{
        make_pattern();
}

/* make_pattern
 * Parameters: None
 * Purpose:    Make a text-based pattern of two strings.
 * Returns:    Nothing
 */
void make_pattern()
{
        string s1, s2;
        int n;

        cin >> s1 >> s2 >> n;

        // testing for empty s1 and s2
        // s1 = "";
        // s2 = "";
        // cin >> n

        output_pattern(s1, s2, n);
}

/* output_pattern
 * Parameters: Two strings: s1 and s2; how many lines to repeat the pattern, 
 *             lines left.
 * Purpose:    Print s1 and s2 REPETITIONS times per line, for lines_left times.
 * Returns:    Nothing
 * Effects:    Calls other functions including itself, prints something.
 */
void output_pattern(string s1, string s2, int lines_left)
{
        if (lines_left >= 1) {
                output_pattern(s1, s2, lines_left - 1);

                if (lines_left % 2 == 1)
                        cout << print_line(s1, s2, REPETITIONS);
                else
                        cout << print_line(s2, s1, REPETITIONS);
        }
}

/* print_line
 * Parameters: Two strings, s1 and s2, and the number of times to repeat them,
 *             reps_left.
 * Purpose:    Combine two strings reps_left number of times inline.
 * Returns:    Returns combined string.
 */
string print_line(string s1, string s2, int reps_left)
{
        if (reps_left >= 1)
                return s1 + s2 + print_line(s1, s2, reps_left - 1);
        return "\n";
}
