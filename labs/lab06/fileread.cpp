//                            fileread.cpp
//                         Author: Noah Mendelsohn
//
//         Demonstration of reading lines from a named file
//

#include <iostream>
#include <fstream>    // *** Needed to use ifstream ***

using namespace std;

struct ClassInfo
{
        string department;
        int class_num;
};


ClassInfo read_class_info(ifstream& input_file);
void print_class_info(ClassInfo my_class);

int main(int argc, char *argv[])
{
        // check if expected number of arguments are passed.
        if (argc != 2) {
                cerr << "fileread.cpp: Filename missing on command line"
                        << endl;

                return 1;
        }

        string filename = argv[1];
        ifstream input_file;
        int num_reads = 2;

        // open file to read it
        input_file.open(filename);

        // check if file is open
        if (not input_file.is_open()) {
                cerr << "fileread.cpp: could not open file: "
                     << filename << endl;
                return 1;       // if error
        }

        // make array of classes.
        ClassInfo classes[num_reads];

        // read lines from input_file to locations in my_class
        // print the department and class number of read classes
        for (int i = 0; i < num_reads; i++) {
                classes[i] = read_class_info(input_file);
                print_class_info(classes[i]);
        }

        // close input_file
        input_file.close();

        return 0;
}

/* read_class_info
 * Purpose:     read the information from an input file stream to a ClassInfo
 *              struct. only one line is copied at a time and returned.
 * Returns:     a ClassInfo struct
 * Effects:     advances "cursor" position in ifstream input
 */
ClassInfo read_class_info(ifstream& input_file)
{
        ClassInfo my_class;

        input_file >> my_class.department >> my_class.class_num;

        return my_class;
}

/* print_class_info
 * Purpose:     print the department and class number of a class on a single
 *              line; no space
 * Effects:     a cout call.
 */
void print_class_info(ClassInfo my_class)
{
        cout << "CLASS: " << my_class.department
             << my_class.class_num << endl;
}
