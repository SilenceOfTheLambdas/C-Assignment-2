// temporary main function to allow testing of Student class
// this file should not be submitted as part of the assignment

using namespace std;
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include "Student.h"
#include "Student.h"

vector<Student> students; // The vector of student objects
vector<string> lines; // The lines of the file being read

void createStudents();
void updateMarks();

int main()
{
    createStudents();
    updateMarks();
    
//     cout << printModuleMarks() << endl
    
    return 0;
}

void createStudents() {

    /************************************************/
    /*  Read File & Add to vector                   */
    A:
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
        goto A;
    }  file.close();
    /************************************************/

    /************************************************/
    /*      Creating students                       */
    for (int regNo = 0; regNo < lines.size(); regNo += 3) {
        int name = regNo + 1;
        int reg = stoi(lines.at(regNo));
        string fullname = lines.at(name) + " " + lines.at(name + 1);
        if (name != regNo) {
            Student c(fullname, reg);
            cout << reg << " | " << fullname << endl; // TODO: Remove before release
            students.push_back(c); // Add the new student into the students vector
        }
    }
    /************************************************/
}

void updateMarks() {
    /************************************************/
    /*      Read File                               */
    A:
    lines.clear(); // Reset the lines vector
    string filename;
    cout << "Please specify the filename for the module data: ";
    cin >> filename;
    ifstream file(filename);
    string line;

    /* Add each line of the file into a new vector */
    if (file.is_open()) {
        while (file >> line) {
            lines.push_back(line);
        }
    }
    else {
        cout << "File not found: " << filename << endl;
        goto A;
    }  file.close();
    /************************************************/

    /************************************************/
    /*      Assign Marks                            */
    string module;
    int regID;
    float mark;
    for (int moduleNo = 0; moduleNo < lines.size(); moduleNo += 3) {
        module = lines.at(moduleNo); // The module number
        int r = moduleNo + 1;
        int s = r + 1;

        regID = stoi(lines.at(r)); // Student registration ID
        mark = stof(lines.at(s)); // The mark a student got for that module
    }
    /* Check to see if the student exists within the students vector */
    bool found = true;
    for (auto & student : students) {
        if (regID != student.getRegNo()) {
            found = false;
        }
        else if (regID == student.getRegNo()) {
            student.addMark(module, mark);
        } 
        cout << student.getName() << " " << student.getRegNo() << endl;
    }
    if (!(found)) {
        cout << "One or more students were not found!" << endl;
    }
        
    /************************************************/
}

ostream printModuleMarks(const vector<Student> &studs, float &marks) {
    /**
     * @param &studs a vector that contains a list of student objects
     * @param &marks a float attaining to the mark of that module
     */
//     TODO: Figure out how to use the operator<< function
    
}

