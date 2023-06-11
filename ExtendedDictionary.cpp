#include "ExtendedDictionary.h"

using namespace std;

// constructor. initialises the class.
// curated 09/05/2022
ExtendedDictionary::ExtendedDictionary()
{
	Dictionary::loadDictionary(); // load the dictionary within constructor for use within ExtendedDictionary
}

// deconstructor. Clears memory when extendeddictionary class is not in use.
// curated 09/05/2022
ExtendedDictionary::~ExtendedDictionary()
{

}

// The palindrome function is used to list all words in the dictionary that are palindromee. e.g. civic.
// Doesnt take any parameters or output a value. As the inputs are built into the the function.
// Curated 09/05/2022.
void ExtendedDictionary::palindrome()
{
	string checkWord;
	bool charMatch;
	unsigned int counter;

	for (Word* i : dictionary) // range based loop for dictionary vector
	{
		checkWord = stringToLower(i->getWord()); // set checkword to output name from Word.h
		charMatch = true; 
		counter = 0; // begin counter at 0
		while (charMatch == true && counter < (checkWord.length() / 2)) // loop to check if charmatch is still true and counter is smaller than length of checkword
		{
			if (checkWord[counter] == checkWord[checkWord.length() - (counter + 1)]) // check if word equates to reversed word
			{
				charMatch = true;
			}
			else
			{
				charMatch = false; 
			}

			counter++;
		}
		if (charMatch == true) // if charmatch true, print out palindrome
		{
			cout << "- " << i->getWord() << "\n";
		}
	}
}

// The anagram function lists all anagrams from dictionary of user inputted word.
// Doesnt take any parameters or output a value. As the inputs are built into the the function.
// curated 09/05/2022.
void ExtendedDictionary::anagram()
{
	string compareWord;
	string findName;

	cout << "Input a word to search for anagrams for that word." << endl;
	cout << "> ";
	cin >> findName;

	int posMatch;
	bool next;
	unsigned int counter;
	findName = stringToLower(findName);

	for (Word* i : dictionary) // iterate through dictionary vecotr
	{
		compareWord = stringToLower(i->getWord());
		// check words are same length and are not the same word
		if (findName.length() == compareWord.length() && findName != compareWord)
		{
			counter = 0;
			next = true;
			// check each letter of inputted word to see if it exists in the dictionary
			while (counter < findName.length() && next == true)
			{
				posMatch = compareWord.find(findName[counter]);
				// if a letter is found, errase letter to avoid running into it again
				if (posMatch != string::npos)
				{
					compareWord.erase(posMatch, 1);
					counter++;
				}
				else
				{
					next = false;
				}
			}
			// if counter is the same as the length of user input. Print anagram
			if (counter == findName.length())
			{
				cout << "- " << i->getWord() << "\n";
			}
		}
	}
}

// The guessinggame function presents a definition of a noun and word length to the user, with this information
// they're given three tries to guess the word, for each wrong guess, a letter is given as a hint.
// Doesnt take any parameters or output a value. As the inputs are built into the the function.
// // curated 10/05/2022.
void ExtendedDictionary::guessinggame()
{
	string randtype;
	string randword;
	string userInput;
	int attempts;
	int triesremaining;
	int randnum;

	// while word type doesnt equal a noun
	while (randtype != "n")
	{
		// geenrate random number
		random_device dev;
		mt19937 rng(dev());
		uniform_int_distribution<mt19937::result_type> dist(0, dictionary.size());
		randnum = dist(rng);
		randtype = dictionary[randnum]->getType();
		if (randtype == "n") // if random word type is a noun, set randword as the solution word.
		{
			randword = dictionary[randnum]->getWord();
		}
	}

	attempts = 1;
	triesremaining = 3;

	cout << "<Guessing Game>" << endl;
	cout << "You're given a random noun along with its definition. You have 3 tries to guess the word. After each attempt another letter will be revealed.\n\n" ;
	cout << "Length of noun: " << randword.length() << endl;
	cout << "Definition: " << dictionary[randnum]->getDefinition() << "\n\n";

	while (attempts <= 3) // while attempts are smaller or equal to 3 
	{
		cout << "Tries remaining: " << triesremaining << endl;
		cout << "Word: ";

		if (attempts == 1) // if on attempt 1, print visual of size of letter
		{
			for (int i = 1; i <= randword.length(); i++) // iterate by word length
			{
				cout << "_ ";
			}
		}
		if (attempts == 2) // if on attempt 2, print hint with visual of size of letter
		{
			cout << randword[0] << " "; // hint
			for (int i = 2; i <= randword.length(); i++) // iterate by word length with hint in mind
			{
				cout << "_ ";
			}
		}
		if (attempts == 3) // if on attempt 3, print second hint with visual of size of letter
		{
			cout << randword[0] << randword[1] << " "; // hint 1 and hint 2
			for (int i = 3; i <= randword.length(); i++) // iterate by word length with hints in mind
			{
				cout << "_ ";
			}
		}
		cout << "\n\nAttempt: " << attempts << endl;
		cout << "> ";
		cin >> userInput;

		if (stringToLower(userInput) == stringToLower(randword)) // if user guess correctly, print correct word, and set attempts 4
		{
			attempts = 4;
			cout << "\n\nCongratulations, you guessed right. The word was" << randword << ".";
		}
		else // if incorrect, increment attempts and tries remaining.
		{
			attempts++;
			triesremaining--;
		}
	}

	if (triesremaining == 0) // if didnt guess with full tries, print game over message with solution word
	{
		cout << "\n\n GAME OVER. The word was " << randword << ".";
	}
}

// Wordle function is a cheat program to narrow down and see all possible remaining words. This is done with te user
// entering greyy, yellow, green letters to narrow the search.
// Doesnt take any parameters or output a value. As the inputs are built into the the function.
// // curated 12/05/2022.
void ExtendedDictionary::wordle()
{
	cout << "<Cheating Wordle>\n\n";
	cout << "Wordle is a web browser game, where players have to guess a 5-letter mystery word within 6 attempts." << endl;
	cout << "When a players enters a 5 letter word in, each character in that word has 3 levels of correctness. " << endl;
	cout << "The first level of correctness is grey letters, grey letters mean the character doesnt exist in the mystery word. " << endl;
	cout << "The second level of correctness is yellow letters, yellow letters mean the character exists in the mystery word " << endl;
	cout << "but is in the wrong position. The third level of correctnesss is the green letters, green letters mean the character " << endl;
	cout << "exists and the position of the guessed word matches that of the mystery word.";
	cout << "The purpose of this program is to narrow down the mystery word of the Wordle game and guess the mystery word " << endl;
	cout << "in the least amount of tries.\n\n ";

	string userInput;
	string userInput2;
	string userInput3;
	userInput = stringToLower(userInput);
	userInput2 = stringToLower(userInput2);
	userInput3 = stringToLower(userInput3);

	list<string> greychar;
	list<string> yellowinput;
	list<string> yellowchar;
	list<string> greenchar;
	list<string> greenwords;
	
	int count;
	int countpos;
	int correctpos;
	int currentpos;
	int numofletters;

	currentpos = 1;
	numofletters = 0;

	// sort dictionary words into a list (greychar) that contain only 5 letter words.
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (dictionary[i]->getWord().length() == 5)
		{
			greychar.push_back(dictionary[i]->getWord());
		}
	}

	cout << "Enter grey letters. Enter 0 to eixt." << endl;

	// user inputs grey letters and checks if letter exists in any of the words in the greychar list, erase word from list
	while (userInput != "0")
	{
		list<string>::const_iterator it = greychar.cbegin();
		cout << "> ";
		cin >> userInput;

		if (any_of(begin(userInput), end(userInput), isalpha) && userInput.length() == 1)
		{
			while (it != greychar.cend())
			{
				if (it->find(userInput) != string::npos)
				{
					it = greychar.erase(it);
				}
				else
				{
					it++;
				}
			}
		}
		else if (userInput == "0")
		{
			cout << "\n\n";
		}
		else
			cout << "Incorrect input" << endl;
	}

	int size;
	size = 0;
	cout << "Enter yellow letters. Press 0 to exit." << endl;

	// user enters yellow letters, they are appeneded to a yellowinput list, they enter 0 when they're finished
	while (userInput2 != "0")
	{
		cout << "> ";
		cin >> userInput2;

		if (any_of(begin(userInput2), end(userInput2), isalpha) && userInput2.length() == 1)
		{
			yellowinput.push_back(userInput2);
			size++;
			if (size == 5)
			{
				cout << "\n\n";
				break;
			}
		}
		else if (userInput2 == "0")
		{
			cout << "\n\n";
		}
		else
			cout << "Incorrect input" << endl;
	}

	// processes greychar list against yellowinput list to see if all the yellow letters exist in any greychar words. If this is so, append to yellowchar list
	for (auto const& i : greychar)
	{
		count = 0;
		for (auto const& x : yellowinput)
		{
			if (i.find(x) != string::npos)
			{
				count++;
				if (count == yellowinput.size())
				{
					yellowchar.push_back(i);
				}
			}
		}
	}

	cout << "Enter known letter based on given position. " << endl;
	cout << "enter '0' if position of letter is unknown. " << endl;
	// iterate 5 times, during each iteration the user enters either a known letter in that position or enters 0 if unknown.
	// all of these inputs are appended into a list called greenchar.
	while (currentpos != 6)
	{
		cout << "Position: " << currentpos << endl;
		cout << "Enter letter : ";
		cin >> userInput3;

		if (any_of(begin(userInput3), end(userInput3), isalpha) && userInput3.length() == 1 || userInput3 == "0")
		{
			currentpos++;
			greenchar.push_back(userInput3);
			if (any_of(begin(userInput3), end(userInput3), isalpha))
			{
				numofletters = numofletters + 1;
			}
		}
		else
			cout << "Incorrect input" << endl;
	}

	// process the yellowchar list against the greenchar list to see if the positon of the matched letter in yellowchar is the same as all the greenchar letter position.
	// if there is a match, append the word to a list called greenwords.
	for (auto const& i : yellowchar)
	{
		countpos = 0;
		correctpos = 0;
		for (auto const& x : greenchar)
		{
			if (i.find(x) == countpos)
			{
				correctpos++;
				if (correctpos == numofletters)
				{
					greenwords.push_back(i);
				}
			}
			countpos++;
		}
	}
	
	cout << "\n\nWords founds based on criteria... \n\n";
	// iterate through greenwords list and print each word from the list
	for (auto const i : greenwords)
	{
		cout << i << endl;
	}

	// if no words were appened to list, display a message.
	if (greenwords.size() == 0)
	{
		cout << "no words found. ";
	}
}