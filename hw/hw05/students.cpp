/*
 * students.cpp
 * Program to show functionality of searching an array of structs and
 * accessing/using the values stored within
 * Essential idea: Show usage of arrays and structs.
 *
 * By:  Neil Powers
 */

#include <iostream>
#include <string>

using namespace std;

// declare the Student struct
struct Student {
    int    id;
    string firstName;
    char   lastInitial;
    float  gpa; 
};

const int TOTAL_STUDENTS = 10;

// Function Prototypes
int  find_student(int id, Student students[], int num_students);
void print_student(int index, Student students[]);
int get_student();


int main()
{
    // declare and initialize array of 
    // student structs of size TOTAL_STUDENTS
    Student students [TOTAL_STUDENTS] = {
        {268, "Dana",     'J', 4.0},
        {123, "Rachel",   'G', 3.42},
        {126, "Sam",      'B', 3.8},
        {431, "Keisha",   'M', 3.9},
        {231, "Joe",      'W', 2.7},
        {272, "Isabella", 'U', 3.73},
        {112, "Sook-Hee", 'E', 3.54},
        {289, "Molly",    'C', 3.6},
        {345, "Talia",    'K', 3.63},
        {228, "Jackson",  'P', 3.33}
    };

    print_student(find_student(get_student(),
            students, TOTAL_STUDENTS), students);

    return 0;
}

/* get_student
 * Purpose:     get user input
 * Returns:     integer
 * Effects:     gets user input
 */
int get_student()
{
    int student_number;

    cin >> student_number;

    return student_number;
}

/* find_student
 * Purpose: search an array of students for the index of the student with
 *          the matching id number
 * Args:    an id to search for, an array of students, the number of students
 *          in the array
 * Returns: the index of the first matching student
 */
int find_student(int id, Student students[], int num_students)
{
    // loops through array of students until it finds a student with a matching
    // id number.
    for (int i = 0; i < num_students; i++) {
        if (id == students[i].id) {
            return i;
        }
    }

    return -1;
}

/* print_student
 * Purpose: print name and gpa of a student at a given index
 * Args:    an index and an array of students
 * Effects: prints to console
 * Example: "Name: John D"
 *          "GPA: 3.56"
 */
void print_student(int index, Student students[])
{
    // if student exists, print their information.
    if (index == -1) {
        cout << "Student not found." << endl;
    } else {
        cout << "Name: " << students[index].firstName << " " 
            << students[index].lastInitial << endl;
        cout << "GPA: " << students[index].gpa << endl;
    }
}
