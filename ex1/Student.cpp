#include <iostream>
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

ostream &operator<<(ostream &str, const Student &s) {
//    This will show a students average, max and min marks for all modules, along with their name and regNo
    /*********************************************/
    /*  Calculate Averages                       */
    /********/
    float minMark;
    float maxMark;
    float averageMark = 0;
    /*******/
    try {
        /* Min */
        float tmp = 9999.99; // some really big value
        for (auto & mark : s.marks) {
            if (mark.second < tmp) tmp = mark.second;
        }  minMark = tmp;

        /* Max */
        float tmp2 = 0;
        for (auto & mark : s.marks) {
            if (mark.second > tmp2) tmp2 = mark.second;
        } maxMark = tmp2;

        /* Average */
        for (auto & mark : s.marks) {
            averageMark += mark.second / s.marks.size();
        }
    } catch (NoMarkException e) {
        string output = "Name: " + s.getName() + " " + to_string( s.getRegNo()) + " has no marks. " + "\n";
    }
    string output = "Name: " + s.getName() + " " + to_string( s.getRegNo()) + "min: " + to_string(minMark)
            + " max: " + to_string(maxMark) + " average: " + to_string(averageMark) + "\n";
    return str  << output;
}

