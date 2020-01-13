/**
 * This source file provides the imeplmentation for the filter3 class
 */

#include "filter3.h"

/**
* @brief In the third class the filter function should return true if its argument is a string
* that contains at least one letter and at least one punctuation character (as defined by the function
* ispunct declared in the header file <cctype>)
* 
* @param word : The word to be checked
* @return bool true if its argument is a string that contains at least one letter and at least one punctuation character
*/
bool filter3::filter(std::string word) {
    for (auto & letter : word) {
        if (isalpha(letter) && ispunct(letter)) return true;
    }
    return false;
}

