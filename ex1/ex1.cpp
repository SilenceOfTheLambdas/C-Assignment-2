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
vector<string> lines;

void createStudents();

int main()
{
    createStudents();
}

void createStudents() {
    string filename;
    cout << "Please specify the filename for the student data: ";
    cin >> filename;

    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (file >> line) {
            lines.push_back(line);
        }
    }
    else {
        cout << "File not found: " << filename << endl;
    }  file.close();

    /************************************************/
    /*  Creating Students                           */
    for (int regNo = 0; regNo < lines.size(); regNo += 3) {
        int name = regNo + 1;
        int reg = stoi(lines.at(regNo));
        string fullname = lines.at(name) + " " + lines.at(name + 1);
        if (name != regNo) {
            cout << reg << "|" << fullname << endl;
            Student c(fullname, reg);
        }
    }
    /************************************************/
}
