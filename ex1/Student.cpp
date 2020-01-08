/**
 * @author Callum-James Smith (1804096)
 * @date 31st December 2019 @ 10:08:51pm
 */

#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

Student::Student(const string &name, int regNo): Person(name) {
    this->name = name;
    this->regNo = regNo;
    marks.clear();
}

int Student::getRegNo() const {
    return regNo;
}

void Student::addMark(const string& module, float mark) {

    if (marks.find(module) == marks.end()) {
        // If the module code has already been added
        marks.insert(pair<string, float>(module, mark));
    } else {
        // if not
        marks[module] = mark;
    }
}

float Student::getMark(const string &module) const {
    if (marks.find(module) != marks.end()) {
        // If the module exists
        return marks.at(module);
    } else {
        throw NoMarkException();
    }
}

bool Student::sortMinMarks(float mark) const
{
    for (auto & m : marks) {
        if (m.second >= mark) {
            return true;
        }
    }
    return false;
}

ostream &operator<<(ostream &str, const Student &s) {
/**
 * This function implements the << operator and allows for the output of student information.
* @param &str the ostream output
* @param &s the student object
*/
    /*********************************************/
    /*  Calculate Averages                       */
    /********/
    float minMark = 9999;
    float maxMark = 0;
    float averageMark = 0;
    /*******/
    if (s.marks.empty()) { // if the student has no marks
        str << setw(s.getName().length()) << left << s.getName() << setw(5) << "\t" << to_string( s.getRegNo()) << " Student has no marks" << endl;
    }
    else { // if the student does have at least 1 mark
        for (auto & mark : s.marks) {
            if (minMark > mark.second) minMark = mark.second; // Min
            if (mark.second > maxMark) maxMark = mark.second; // Max
            averageMark = s.marks.size() == 1 ? mark.second : (averageMark += mark.second) / s.marks.size(); // Average
        }
        str << setw(5) << left << to_string( s.getRegNo()) << "\t" << setw(s.getName().length()) << s.getName() << "\t"  << " MIN: " 
        << setprecision(2) << fixed << setw(4) << minMark << " MAX: " << maxMark << " AVERAGE: " << averageMark << endl;
    }
        
    return str; // return the ostream
    /*********************************************/
}

