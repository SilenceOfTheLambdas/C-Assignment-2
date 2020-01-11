// #include <iostream>
// #include <stdexcept>
// #include <algorithm>
// #include <fstream>
// #include <iomanip>
// #include <vector>
// #include "Student.h"
// 
// vector<Student> students; // The vector of student objects
// vector<string> lines; // The lines of the file being read
// 
// void createStudents();
// void updateMarks();
// void printModuleMarksMin(const vector<Student> &, float);
// void printModuleMarkMax(const vector<Student> &, string, float);
// 
// auto main() -> int {
//     int userChoice = 0;
//     bool quit = false;
//     createStudents();
//     updateMarks();
//     while (!(quit)) {
//         cout << "Please choose from the following options: " << endl;
//         cout << "1: Display module marks (specifying minumum marks) " << endl << "2: Display module marks (specifying maximum marks) " << endl;
//         cout << "0: Quit" << endl;
//         cout << "> ";
//         cin >> userChoice;
//         
//         if (userChoice == 1) {
//             float userMark;
//             cout << "Please enter the minumum mark to sort by\n" << "> ";
//             cin >> userMark;
//             printModuleMarksMin(students, userMark);   
//         }
//         if (userChoice == 2) {
//             string moduleCode;
//             float userMark;
//             cout << "Please enter the module code\n" << "> ";
//             cin >> moduleCode;
//             cout << "Now please enter the maximum mark to sort by\n" << "> ";
//             cin >> userMark;
//             printModuleMarkMax(students, moduleCode, userMark);
//         }
//         if (userChoice == 0) return 0;
//     }
//     
//     return 0;
// }
// 
// void createStudents() {
// /**
// * @brief Reads from the file and creates student objects according to that data
// */
// 
//     /************************************************/
//     /*  Read File & Add to vector                   */
//     A:
//     string filename;
//     cout << "Please specify the filename for the student data: ";
//     cin >> filename;
// 
//     ifstream file(filename);
//     string line;
//     if (file.is_open()) {
//         while (file >> line) {
//             lines.push_back(line);
//         }
//     }
//     else {
//         cout << "File not found: " << filename << endl;
//         goto A;
//     }  file.close();
//     /************************************************/
// 
//     /************************************************/
//     /*      Creating student objects                */
//     for (int regNo = 0; regNo < lines.size(); regNo += 3) {
//         int name = regNo + 1;
//         int reg = stoi(lines.at(regNo));
//         string fullname = lines.at(name) + " " + lines.at(name + 1);
//         if (name != regNo) {
//             Student c(fullname, reg);
//             students.push_back(c); // Add the new student into the students vector
//         }
//     }
//     /************************************************/
// }
// 
// void updateMarks() {
// /**
// * @brief Reads from a file; information attaining to student marks, then assigns students
// * specified in the file a mark
// */    
//     
//     /************************************************/
//     /*      Read File                               */
//     A:
//     lines.clear(); // Reset the lines vector
//     string filename;
//     cout << "Please specify the filename for the module data: ";
//     cin >> filename;
//     ifstream file(filename);
//     string line;
// 
//     /* Add each line of the file into a new vector */
//     if (file.is_open()) {
//         while (file >> line) {
//             lines.push_back(line);
//         }
//     }
//     else {
//         cout << "File not found: " << filename << endl;
//         goto A;
//     }  file.close();
//     /************************************************/
// 
//     /************************************************/
//     /*      Assign Marks                            */
//     
//     string module; // hold the module code
//     int regID; // he student's ID
//     float mark; // The mark they obtained
//     
//     bool found;
//     for (int moduleNo = 0; moduleNo < lines.size(); moduleNo += 3) {
//         module = lines.at(moduleNo); // The module number
//         int r = moduleNo + 1; // temp student ID
//         int s = r + 1; // temp mark
// 
//         regID = stoi(lines.at(r)); // Student registration ID
//         mark = stof(lines.at(s)); // The mark a student got for that module
//         /* Check to see if the student exists within the students vector */
//         found = true;
//         for (auto & student : students) {
//             found = true;
//             if (student.getRegNo() == regID) {
//                 student.addMark(module, mark);
//             } else {
//                 found = false;
//             }
//         }   
//         /************************************************/
//     }
//     if (!(found)) {
//             cout << "One or more students were not found!" << endl;
//     }
// }
// void printModuleMarksMin(const vector<Student> &studs, float mark) {
// /**
// * @brief Prints only student marks that are more than or equal to the mark param
// * 
// * @param studs p_studs: A reference to the collection of students
// * @param mark p_mark: The minumum mark specified by the user
// */
//     for (auto & student : studs) {
//         if (student.sortMinMarks(mark))
//             cout << student;
//         else cout << student.getName() << "\tNo marks available\n";
//     }
// }
// 
// void printModuleMarkMax(const vector<Student> &studs, string modNumber, float mark) {
// /**
// * @brief This function prints inforation about the module and the mark obtained sorted
// * by the maximum mark
// * 
// * @param studs p_studs: A reference to a collection of students
// * @param modNumber p_modNumber: The module number to sort via
// * @param mark p_mark: The maximum mark to display
// */
//     for (auto & student : studs) {
//         try {
//             if (student.getMark(modNumber) <= mark)
//                 cout << setw(student.getName().length()) << left << "\t" << student.getName() << setw(5) << "\t" << modNumber << setw(5) << "\t" << student.getMark(modNumber) << endl;
//         } catch (NoMarkException e) {
//             cout << student.getName() << "\t" << modNumber << "\t" << "Student has no marks" << endl;
//         }
//         
//     }
// }
// 
