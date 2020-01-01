// temporary main function to allow testing of Student class
// this file should not be submitted as part of the assignment

using namespace std;
#include <iostream>
#include <stdexcept>
#include "Student.h"

int main()
{   
    Student s("Bruh Moment", 12345);
    s.changeName("Bongis Momento");
    cout << "Name is " << s.getName() << endl;
    cout << "Reg is " << s.getRegNo() << endl;
    s.addMark("CE151", 99.5);
    s.addMark("CE221", 5.5);
    try
    { cout << "Mark for CE151 is " << s.getMark("CE151") << endl;
    }
    catch (NoMarkException e)
    { cout << "No mark for CE151" << endl;
    }
    try
    { cout << "Mark for CE221 is " << s.getMark("CE221") << endl;
    }
    catch (NoMarkException e)
    { cout << "No mark for CE204" << endl;
    }
    // cout << "Average mark (which should be 52.5) is " << s.getAverageMark() << endl;
}
