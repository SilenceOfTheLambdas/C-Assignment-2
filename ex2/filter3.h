/**
 * The header source file outlining the filter 3 class; this class overrides the filter method from ReadFilteredWords
 */

#ifndef _FILTER3_H
#define _FILTER3_H

#include "ReadFilteredWords.h"

class filter3 : public ReadFilteredWords {
    public:
        bool filter(string word) override;
};

#endif
