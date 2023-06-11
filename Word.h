#ifndef WORD_H
#define WORD_H

#include <string>

using namespace std;

// word class. holds dictionary name, type, and defintion.
class Word
{
public:
	Word();
	~Word();
	void setWord(string type, string name, string definition);
	string getWord();
	string getType();
	string getDefinition();
	bool isNoun();
protected:
	string name;
	string type;
	string definition;
};

#endif
