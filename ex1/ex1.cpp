// temporary main function to allow testing of Student class
// this file should not be submitted as part of the assignment

using namespace std;
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include "Student.h"

vector<Student> students;

int main()
{
    string filename;
    cout << "Please specify the filename for the student data: ";
    cin >> filename;

    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line, '\n')) {

            stringstream ss;

            /* Storing the whole string into string stream */
            ss << line;

            /* Running loop till the end of the stream */
            string temp;
            string foundName;
            int found;
            while (!ss.eof()) {
                /* extracting word by word from stream */
                ss >> temp;
                int regID = 0;
                string name;

                /* Checking the given word is integer or not */
                if (stringstream(temp) >> found) {
                    regID = found;
                } else if (stringstream(temp) >> foundName) {
                    name = foundName;
                }

                if (!(name.empty())) {
                    Student s(name, regID); // create a new student
                    s.addMark("CE202", 76.5);
                    cout << s.getName() << endl;
                    students.push_back(s); // Add the new student to the students vector
                }
                /* To save from space at the end of string */
                temp = "";
            }
        }
    } else {
        cout << "File not found: " << filename << endl;
    }
}
