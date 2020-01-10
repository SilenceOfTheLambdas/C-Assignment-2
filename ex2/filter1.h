/**
 * filter1.h : The header file that defines the derived class for the 1st filter
 */

#ifndef _FILTER1_H
#define _FILTER1_H

#include "ReadFilteredWords.h"

class filter1 : public ReadFilteredWords {
public:
    bool filter(string word) override;    
};

#endif
