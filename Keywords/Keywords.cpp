// Keywords.cpp : Defines the entry point for the console application.
//By hand, choose 10 single code words of your choice, and write down a hint for each word.
//Create a new C++ project called Keywords
//This Code Breaker Training Simulation Program should give the user directions and tell them what it is and how to use it based of the background description above.
//Then your Code Breaker Training Simulation Program should randomly select 3 of the 10 words that are coded in your program.
//Your code breaker will scramble each word on the fly and different each run randomly.
//Now make the user try to solve each one of the three randomly picked coded word from your random list.
//Each turn you should give your user feedback on if they got the guess correct or not.
//You should also offer the user help.
//At the end, you should display their stats and ask if they would like to try again.
//After you have a project, publish your code to a new GitHub repository.

// Keywords are:
//Wave
//Computer
//Puppy
//Sidewalk
//Vehicle
//Homework
//Buddha
//Lightsaber
//Surfboard
//Bedroom






#include "stdafx.h"
#include "iostream"
#include "string"
#include "cstdlib"
#include "ctime"

using namespace std;

int main()
{
	char playAgain; // stores wrether the user wants to play again or not
	enum fields { WORD, HINT, NUM_FIELDS }; // Enumerator
	const int NUM_WORDS = 10; // Number of words 
							  // List of all the words, and their hints 
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
	{ "Wave","On every beach in the world" },
	{ "Computer","You are using it right now" },
	{ "Puppy","A dog that is not fully grown up yet" },
	{ "Sidewalk","On the side of most streets, pedestrians use it" },
	{ "Vehicle","Drives on roads most people own one" },
	{ "Homework","Work you do at home" },
	{ "Buddha","He is not a god merely a man that wants you to learn from his teachings" },
	{ "Lightsaber","Was used to chop of lukes hand in Star Wars" },
	{ "Surfboard","You need this if you want to be a surfer and ride waves" },
	{ "Bedroom","Where you sleep" }
	};
	srand(static_cast<unsigned int>(time(0))); // Seed random
	cout << "\t\tWord Jumble\n\n";
	cout << "I am going to scramble three words.\n";
	cout << "You must unscramble the letters to find the word.\n";
	cout << "Capitalization matters!\n";
	cout << "Enter 'help' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	do // Do at least once, restart point if user wants to play again.
	{
		int word1Attempts = 0; //number of attempts for word 1
		int word2Attempts = 0; //number of attempts for word 2
		int word3Attempts = 0; //number of attempts for word 3
		for (int goodAnswers = 0; goodAnswers < 3; goodAnswers++) // This runs the program 3 times, and resets all variables
		{
			int choice = (rand() % NUM_WORDS); // This choses a random word from the WORDS array
			string theWord = WORDS[choice][WORD]; // Words player is trying to guess 
			string theHint = WORDS[choice][HINT]; // Hint for word associated with choice
			string jumble = theWord; // jumpled version of Word
			int length = jumble.size(); // Length of the word we are going to jumple
			for (int i = 0; i < length; ++i) // This loop jumbles the word
			{
				int index1 = (rand() % length); // This makes index1 a random number 
				int index2 = (rand() % length);
				char temp = jumble[index1]; // This looks at the number stored in index1, and finds the letter in that index from the word stored in jumble, then stores that letter in temp
				jumble[index1] = jumble[index2];
				jumble[index2] = temp; 
			}

			string guess; // This variable stores the users input
			cout << "The jumbled word is " << jumble << "\n"; // Displays jumbled word
			cout << "\n\nYour guess:";
			cin >> guess; // User inserts his/her guess

			if (goodAnswers == 0) // go here if you are on first word
			{
				word1Attempts++; // Add 1 to number of attempts (initial guess)
			}
			else if (goodAnswers == 1) // go here if you are on second word
			{
				word2Attempts++; // Add 1 to number of attempts (initial guess)
			}
			else if (goodAnswers == 3) // go here if you are on third word
			{
				word3Attempts++; // Add 1 to number of attempts (initial guess)
			}

			while ((guess != theWord) && (guess != "quit")) // Main game loop, while user doesn't say quit, and doesn't have correct answer
			{
				if (guess == "help") // if user enters 'hint'
				{
					cout << theHint; // Display the hint to the word
				}
				else // if answer isn't correct
				{
					cout << "Sorry, that's not it.\nPlease try again";
				}
				cout << "\n\nYour guess:";
				cin >> guess; // User inserts his/her guess
				if (goodAnswers == 0) // go here if you are on first word
				{
					word1Attempts++; // Add 1 to number of attempts
				}
				else if (goodAnswers == 1) // go here if you are on second word
				{
					word2Attempts++; // Add 1 to number of attempts
				}
				else if (goodAnswers == 2) // go here if you are on third word
				{
					word3Attempts++; // Add 1 to number of attempts
				}
			}

			if (guess == theWord) // If guess is correct
			{
				cout << "\nThat's it! You guessed it!\n";
				if (goodAnswers == 0) // go here if you are on first word
				{
					cout << "It took you " << word1Attempts << " to unscramble this word.\n\n";
				}
				else if (goodAnswers == 1) // go here if you are on second word
				{
					cout << "It took you" << word2Attempts << " to unscramble this word.\n\n";
				}
				else if (goodAnswers == 2) // go here if you are on third word
				{
					cout << "It took you" << word3Attempts << " to unscramble this word.\n\n";
				}
			}
		}
		cout << "Great job you have unscrambled all the words\n";
		cout << "Stats: \n" << "Word 1: " << word1Attempts << "\nWord 2: " << word2Attempts << "\nWord 3: " << word3Attempts << endl; // Display number of attempts per word
		cout << "Would you like to play again (Y/N)?\n";
		cin >> playAgain; // user choses if they want to play again
		while ((playAgain != 'Y') && (playAgain != 'y') && (playAgain != 'N') && (playAgain && 'n')) 
		{
			cout << "Invalid Input\nWould you like to play again (Y/N)?";
			cin >> playAgain; // user choses if they want to play again
		}
	} while (playAgain == 'y' || playAgain == 'Y'); // If user wants to play again
	cout << "Thanks for playing!\n";

	system("pause"); // pause at end of program
	return 0;
}