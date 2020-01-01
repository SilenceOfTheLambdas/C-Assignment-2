// temporary main function to allow testing of Student class
// this file should not be submitted as part of the assignment

using namespace std;
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <sstream>
#include "Student.h"

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
            int found;
            while (!ss.eof()) {

                /* extracting word by word from stream */
                ss >> temp;

                /* Checking the given word is integer or not */
                if (stringstream(temp) >> found)
                    cout << found << " ";

                /* To save from space at the end of string */
                temp = "";
            }
        }
    } else {
        cout << "File not found: " << filename << endl;
    }

//    Student s("Bruh Moment", 12345);
//    s.changeName("Bongis Momento");
//    cout << "Name is " << s.getName() << endl;
//    cout << "Reg is " << s.getRegNo() << endl;
//    s.addMark("CE151", 99.5);
//    s.addMark("CE221", 5.5);
//    try
//    { cout << "Mark for CE151 is " << s.getMark("CE151") << endl;
//    }
//    catch (NoMarkException e)
//    { cout << "No mark for CE151" << endl;
//    }
//    try
//    { cout << "Mark for CE221 is " << s.getMark("CE221") << endl;
//    }
//    catch (NoMarkException e)
//    { cout << "No mark for CE204" << endl;
//    }
//    // cout << "Average mark (which should be 52.5) is " << s.getAverageMark() << endl;
}
