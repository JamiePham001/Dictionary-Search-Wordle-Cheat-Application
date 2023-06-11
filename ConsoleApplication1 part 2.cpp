#include "Dictionary.h"
#include "ExtendedDictionary.h"

// the menu function displays the ui, that displays the different options for the user.
// doesnt take any parameters or outputs any values.
// Curated 08/05/2022.
void menu()
{
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << endl;
    cout << "\nPlease select a task from the below list by entering the corresponding number: \n\n";
    cout << "1. Look up definition\n";
    cout << "2. Look for word(s) with more than three 'z''s\n";
    cout << "3. List the words that have a 'q' without a following 'u' eg 'Iraqi'\n";
    cout << "4. List of words that are palidromes\n";
    cout << "5. List of words that are anagrams to an input\n";
    cout << "6. Guessing game\n";
    cout << "7. Cheat at Wordle\n";
    cout << endl;
}

// the menu selection allows user to select digit option to reach a desired function.
// creates objects dictionary and extendeddictionary classes to allow for access of functions.
// loads dictionary vector to be used by functions.
// doesnt take any parameters or outputs any values.
// Curated 08/05/2022.
void main()
{
    Dictionary myDictionary;
    ExtendedDictionary myExtDictionary;
    myDictionary.loadDictionary();
    myDictionary.saveDictionary();

    menu(); 
    cout << "select: ";

    string opt; 

    while (true) 
    {
        cin >> opt; 
        if (opt == "1") 
        {
            system("cls");
            myDictionary.wordSearch(); 
            menu(); 
        }
        else if (opt == "2")
        {
            system("cls");
            myDictionary.charSearch();
            menu();
        }
        else if (opt == "3")
        {
            system("cls");
            myDictionary.QnoU();
            menu();
        }
        else if (opt == "4")
        {
            system("cls");
            myExtDictionary.palindrome();
            menu();
        }
        else if (opt == "5")
        {
            system("cls");
            myExtDictionary.anagram();
            menu();
        }
        else if (opt == "6")
        {
            system("cls");
            myExtDictionary.guessinggame();
            menu();
        }
        else if (opt == "7")
        {
            system("cls");
            myExtDictionary.wordle();
            menu();
        }
        else
            // error message
            cout << endl << "Selection doesnt exist... \n" << endl;
            cout << "select: ";
    }
}
