#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <thread>
#include <ctime>
#include <random>
#include <algorithm>
#include <list>

// reference word class
#include "Word.h"

// class dictionary that creates the dictionary vector and holds some functions from assignment 1
class Dictionary
{
public:
	Dictionary();
	~Dictionary();
	string stringToLower(string input);
	void saveDictionary();
	void loadDictionary();
	void wordSearch();
	void charSearch();
	void QnoU();

private:
	string dictionaryFile;

protected:
	vector<Word*> dictionary;
};
#endif