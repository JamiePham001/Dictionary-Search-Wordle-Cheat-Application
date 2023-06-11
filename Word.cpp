#include "Word.h"

// constructor. initialises the class.
// curated 09/05/2022
Word::Word() 
{
}

// deconstructor. Clears memory when word class is not in use.
// curated 09/05/2022
Word::~Word() 
{
}

// function to help load the dictionary to set different lines to approriate type.
// curated 09/05/2022
void Word::setWord(string type, string name, string definition) 
{
	Word::type = type;
	Word::name = name;
	Word::definition = definition;
}

// function that returns the name from the dictionary
// curated 09/05/2022
string Word::getWord() 
{
	return name;
}

// function that returns the type of a word from the dictionary
// curated 09/05/2022
string Word::getType()
{
	return type;
}

// function that returns the definition from the dictionary
// curated 09/05/2022
string Word::getDefinition()
{
	return definition;
}
