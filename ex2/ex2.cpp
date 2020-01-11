/**
 * The source file containing the entry point for the progrem
 */
#include "ReadFilteredWords.h"
#include "filter1.h"
#include "filter2.h"
#include "filter3.h"
#include <map>

ReadFilteredWords* fw;

int main() {
    
    string filename;
    int choice = 0;
    //     ask the user for a filename
    cout << "Please enter a filename: ";
    cin >> filename;
    
    cout << "Please choose a filter to use: " << endl;
    cout << "1: Filter 1 (string that contains at least one lower-case letter and no upper-case letters)\n"
         << "2: Filter 2 (string containing at least two letters and at least one numeric digit)\n"
         << "3: Filter 3 (string that contains at least one letter and at least one punctuation character)\n";
    cout << "> ";
    cin >> choice;
    
    if (choice == 1) {
        fw = new filter1(filename.c_str());
    }

    /**
     * <string> The word
     * <int> The number of occurrences
     */
    static map<string, int> occurrence; // A map that stores the word that occurred, and it's number of occurrences
    int i = 0;
    while ((fw->getNextFilteredWord() != "")) {
        occurrence.insert(make_pair(fw->getNextWord(), i+=1));
        cout << fw->getNextFilteredWord() << endl;
    }
    
    string buffer;
    cin >> buffer;
            
}
