/**
 * @author Callum-James Smith
 * @date 10th January 2020
 */

#include "ReadFilteredWords.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

/**
* @brief The class declaration contains a function called getNextFilteredWord – this should
* return the next word from the input (obtained by calling getNextWord) that satisfies the criterion, or
* an empty string if there are no more words that satisfy it. (It is assumed that an empty string will
* never satisfy a filter, so it cannot be returned if there are more words that satisfy the filter.) You must
* implement this function in a new ReadFilteredWords.cpp file.
* 
* @return std::__cxx11::string the processed string that satisfies the filter
*/

string ReadFilteredWords::getNextFilteredWord() {
    string word = getNextWord();
    if (filter(word)) {
        return word;
    } else {
        return "";
    }
}
