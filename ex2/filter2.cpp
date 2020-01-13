/**
 * provides the implementation for the second filter derived form ReadFilteredWords
 */

#include "filter2.h"

/**
* @brief This virtual function is overriden from the ReadFilteredWords class, and is manilpulated to return a bool given some conditions
* 
* @param word: The word to be checked
* @return bool  true if its argument is a string containing at least two letters and at least one numeric digit
*/
bool filter2::filter(std::string word) {
    int letterCount = 0;
    int digitCount = 0;
    for (auto & letter : word) {
        if (isalpha(letter))
            letterCount++;
        if (isdigit(letter))
            digitCount++;
    }
    if (letterCount >= 2 && digitCount >= 1) return true;
    else return false;
}

