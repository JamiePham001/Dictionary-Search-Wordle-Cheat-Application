#ifndef EXTENDEDDICTIONARY_H
#define EXTENDEDDICTIONARY_H

#include "Dictionary.h"

// exteneded dictionary class that references the dictionary vector from the dictionary header file.
class ExtendedDictionary : protected Dictionary
{
public:
	ExtendedDictionary();
	~ExtendedDictionary();
	void palindrome();
	void anagram();
	void guessinggame();
	void wordle();
};


#endif