#include "Dictionary.h"

// constructor. initialises the class.
// curated 08/05/2022
Dictionary::Dictionary()
{
}

// deconstructor. Clears memory when dictionary class is not in use.
// curated 08/05/2022
Dictionary::~Dictionary()
{
}

// stringtolower function convert string to a lower case.
// takes a string parameter, and outputs a lower case string value.
// curated 08/05/2022
string Dictionary::stringToLower(string input)
{
    // loops through each letter of word and coverts it to a lower case
    for (int i = 0; i <= input.length(); i++)
    {
        input[i] = tolower(input[i]);
    }

    return input;
}

// loaddictionary function is to load data from text onto the dictionary vector. Goess through text file and sets type, name, and defintion to dictionary.
// doesnt have any parameters and doesnt return any value.
// // curated 08/05/2022
void Dictionary::loadDictionary()
{
    string filename = "dictionary2022.txt";
    dictionaryFile = filename;
    Word* aName;
    string name;
    string definition;
    string type;
    string asterisk;

    ifstream myfile(dictionaryFile);

    // opens text file and iterates through until the end of file. Appends type, name and definition into a dictionary object called aName
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, type);
            getline(myfile, name);
            getline(myfile, definition);
            getline(myfile, asterisk); // skip asterisks, so type doesnt catch the asterisks

            aName = new Word;
            aName->setWord(type, name, definition);
            dictionary.push_back(aName);
        };
        myfile.close();
    }
    else cout << "Unable to open file";
}

//saveDictionaryy function allows for a user to create and name a text folder. 
//Once the file is created, the function will write to the file the all of the dictionary's 
//type, name, and definition in three lines and afterward a blank line.
//The function takes no inputs nor returns any value.
//Author: Jamie Pham
//Curated : 29 / 05 / 2022
void Dictionary::saveDictionary()
{
    // string variable userinput to store user's input
    string userinput;
    cin >> userinput;

    // use ofstream class to create an object called 'file', 
    // this 'file' references the folder directory to place the created text file named after the user.
    ofstream file("C:\\Users\\jamie\\source\\repos\\ConsoleApplication1 part 2\\" + userinput + ".txt", std::ofstream::out);

    // check if 'file' is open
    if (file.is_open())
    {
        // using a range-based iterator on the dictionary vector
        for (int i = 0; i < dictionary.size(); i++)
        {
            // place word, type and defintion into text file
            file << dictionary[i]->getWord() << endl << dictionary[i]->getType() << endl << dictionary[i]->getDefinition() << "\n\n";
        }
        // close file
        file.close();
    }
    // else statement if file doesn't open
    else
        cout << "cant open file";
}


// The wordSearch function task is to find the inputted word in the dictionary and print the words name, type and definition
// on the same line. And to print 'word not found' if input is not in dictionary.
// The function also changes the appearance of word types to be shortened and placed in brackets.
// doesnt have any parameters and doesnt return any value.
// Curated: 08/05/22. Reference1: https://stackoverflow.com/questions/28925349/find-in-vector-of-a-struct user: adl.
// Reference2: https://www.delftstack.com/howto/cpp/how-to-iterate-through-a-vector-in-cpp/.
void Dictionary::wordSearch()
{
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << endl << "----------------------------" << endl;
    cout << endl << "        Search Word   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "\n Type an existing word in the dictionary." << endl;

    string word;
    string name; 
    string type;
    string definition;

    cout << "> ";
    cin >> word; 

    transform(word.begin(), word.end(), word.begin(), ::tolower); // makes input case sensitive to dictionary

    // iterate through dictionary vector
    for (int i = 0; i < dictionary.size(); i++) 
    {
        name = dictionary[i]->getWord();
        type = dictionary[i]->getType();
        definition = dictionary[i]->getDefinition();

        if (name == word) // check if iteration matches input
        {
            if (type == "n_and_v") // check if noun and verb was selected
            {
                // replaces 'n_and_v' to '(n.v.)'
                cout << name << " " << "(n.v.)" << " - " << definition << endl;
                cout << "-----------------------------------------------------------------------------------" << endl;
            }
            else // checks if the word type is different
            {
                // changes the style of the word type with brackets
                cout << name << " " << "(" << type << ".)" << " - " << definition << endl;
                cout << "-----------------------------------------------------------------------------------" << endl;
            }
        }
    }

}

// The charSearch function task is to find the word(s) that contain a given character a given number of times or more.
// The function takes a letter and repitition input, and searches the vector for an existing word with matching criteria.
// Contains a reference of the struct vector found in the main(), allowing formed arrays to operate outside of functions.
// doesnt have any parameters and doesnt return any value.
// Curated: 08/05/22. Referenced: https://www.geeksforgeeks.org/string-find-in-cpp/ user: SarthakKhandelwal.
void Dictionary::charSearch()
{
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << endl << "----------------------------" << endl;
    cout << endl << "        Character Search   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "\n Find words that contains a given character a given number of timers or more." << endl;
    cout << endl << "(Make sure letters are entered for letter input ";
    cout << "and repititons input is digits)" << endl;
    cout << endl;

    string letter; // string variable for letter input
    string checkWord; // displays name from dictionary
    int numOfChars; // integer variable to keep track of characters
    int posOfChar; // integer variable to keep track of position of characters
    int next; // integer variable to keep track of position of letter
    int repetitions; // integer aariable for repetitions input

    cout << "Letter: ";
    cin >> letter; // input with variable letter

    letter = stringToLower(letter);

    cout << "Repetitions: ";
    cin >> repetitions; // input with variable repetitions
    cout << endl;

    // if wrong input, clear and ignore input
    if (cin.fail()) 
    {
        cout << "Word not found...\n";
        cin.clear();
        cin.ignore();
    }
    else
    {
        for (Word* i : dictionary) // range-based loop with struct vector
        {
            numOfChars = 0; // set number of characters to 0
            checkWord = stringToLower(i->getWord()); // set dictionary name to checkwork
            posOfChar = checkWord.find(letter); // set posOfChar to search inputted letter from library

            while (posOfChar != string::npos) //scans string for letter
            {
                numOfChars++; // increment numOfChars
                if (posOfChar != checkWord.length()) // if posOfChar doesnt equate to length of struct vector name
                {
                    next = posOfChar + 1; // assign next to posOfChar to increment +1
                    posOfChar = checkWord.find(letter, next); // assign posOfChar to find inputted letter and increment 
                }
            }
            if (numOfChars > repetitions) // if numOfChars is more than repetitions
            {
                cout << "- " << i->getWord() << "\n"; // print existing words
            }
        }
    }
}

// The QnoU function basic task is to list all words in the dictionary that have a 'q' without a following 'u' eg 'Iraqi'
// Contains a reference of the struct vector found in the main(), allowing formed arrays to operate outside of functions.
// doesnt have any parameters and doesnt return any value.
// Curated: 31/03/22. Referenced: https://www.geeksforgeeks.org/string-find-in-cpp/ user: SarthakKhandelwal.
void Dictionary::QnoU()
{
    cout << endl << "----------------------------" << endl;
    cout << endl << "        Q Without U   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << "\n Checking for words with 'q' without a following 'u'..." << endl;
    cout << endl;

    string checkLetter; // string variable to assign 'name' struct vector
    int posQ; // int variable to keep track of 'q' position
    int posU; // int variable to keep track of 'u' position
    int next; // int variable to keep track of next character in a word

    // range based iterator for dictionary vector
    for (Word* i : dictionary)
    {
        checkLetter = stringToLower(i->getWord()); // assign checkLetter to struct vector name

        posQ = checkLetter.find('q'); // look for 'q' in vector

        while (posQ != string::npos) // scans string for 'q'
        {
            if (checkLetter.length() != posQ) // check if 'q' is not the last letter
            {
                next = posQ + 1; // add +1 to iterate to next character
                posU = checkLetter.find('u', next); // check for a following letter 'u'

                if (posU != next) // if the following letter is not 'u', print word
                {
                    cout << "- " << i->getWord() << "\n";
                }
                posQ = checkLetter.find('q', next); // assign posQ to check if there is another 'q' in a word
            }
            else // if 'q' is the last letter, print word
            {
                cout << "- " << i->getWord() << "\n";
            }
        }
    }
}
