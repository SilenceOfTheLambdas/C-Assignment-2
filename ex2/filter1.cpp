/**
 * This file implements the virtual function filter derived from ReadWords
 */

#include "filter1.h"
#include "ReadFilteredWords.h"

/**
* @brief This virtual function is overriden to check a word given
* 
* @param word p_word: The word to be checked
* @return bool true if its argument is a string that contains at least one lower-case letter and no upper-case letters
*/

bool filter1::filter(string word) {
    
    for (auto & letter : word) {
        if (isupper(letter) && islower(letter)) {
            return true;
        }
    }
    return false;
}

