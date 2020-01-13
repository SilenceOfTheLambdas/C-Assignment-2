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
    
    string filename = "../../../ex2/gpl-3.0.txt";
    int choice = 0;
    //     ask the user for a filename
    /*cout << "Please enter a filename: ";
    cin >> filename;*/
    
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
    string word = fw->getNextFilteredWord();
    while (word != "") {
        for (auto& w : occurrence) {
            if (w.first == word)
                w.second += 1;
        }
        occurrence.insert(make_pair(word, 1));
        cout << word << endl;
        word = fw->getNextFilteredWord();
    }
    
    string buffer;
    cin >> buffer;
            
}
