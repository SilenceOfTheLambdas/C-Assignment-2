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

