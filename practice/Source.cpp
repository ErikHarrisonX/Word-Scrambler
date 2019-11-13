#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main() {
	// Display directions to the recruit on how to use Keywords
	//While recruit has entered a letter that he or she has already guessed
	//Get recruit ’s guess
	//Add the new guess to the group of used letters
	//If the guess is in the secret word
	//Tell the recruit the guess is correct
	//Update the word guessed so far with the new letter
	// Tell the recruit the guess is incorrect
	// Ask the recruit if they would like to run the simulation again
	// If the recruit wants to run the simulation again
	//Move program execution back up to // Display the simulation # is starting to the recruit. 
	//Pause the Simulation with press any key to continue
	// Create an int var to count the number of simulations being run starting at 1
	// Display the simulation # is starting to the recruit. 
	// Increment the number of simulations ran counter
	bool playAgain = false;
	string UsersChoiceToPlayAgain;
	string Username;
	cout << "\nPlease enter your Username.";
	cin >> Username;
	do {
		//setup
		// Display an overview of what Keywords II is to the recruit 
		// Create a collection of 10 words you had written down manually
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		const int MAX_WRONG = 8; // max of incorrect guesses allowed
		vector<string> words; // collection of words to guess
		words.push_back("CONTINUE");
		words.push_back("EXPLICIT");  
		words.push_back("TYPENAME");
		words.push_back("VOLATILE");
		words.push_back("VIRTUAL");
		words.push_back("OPERATOR");
		words.push_back("PROTECTED");
		words.push_back("EXTERN");
		words.push_back("UNSIGNED");
		words.push_back("REGISTER");
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());
		const string THE_WORD = words[0]; //word to guess
		int wrong = 0; //number of guesses
		string soFar(THE_WORD.size(), '-'); //word guessed so far
		string used = ""; //letters already guessed
		// Display Title of the program to the user
		cout << "\n\t\t\t*******WELCOME TO THE HANGMAN GAME********\n";
		cout << "\n\tThe rules are to guess the words by guessing the letter. Good luck!^_^\n";
		// Ask the recruit to log in using their name
		// Hold the recruit's name in a var, and address them by it throughout the simulation.
		//main loop
		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		//     Get recruit's next guess
		while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
			// Tell recruit how many incorrect guesses he or she has left
			//Show recruit the letters he or she has guessed
			// Show player how much of the secret word he or she has guessed
			cout << Username << "\n\tYou have " << (MAX_WRONG - wrong);
			cout << " incorrect guesses left.\t";
			cout << "\n\tYou have used the following letters:\n" << used << endl;
			cout << "\n\tSo far, the word is: \n\t" << soFar << endl;
			char guess;
			cout << "\n\tEnter your guess: ";
			cin >> guess;
			guess = toupper(guess); //Makes in uppercase since secret word in uppercase.
			while (used.find(guess) != string::npos) 
			{
				cout << "\nYou've already guessed " << guess << endl;
				cout << "\nEnter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}
			used += guess;
			if (THE_WORD.find(guess) != string::npos) {
				cout << "That's correct! " << guess << " is in the word.\n";
				//update soFar to include newly guessed letter
				for (int i = 0; i < THE_WORD.length(); ++i) {
					if (THE_WORD[i] == guess) {
						soFar[i] = guess;
					}
				}
			}
			else {
				//Increment the number of incorrect guesses the recruit has made
				cout << "\nSorry, " << Username << " " << guess << " isn't in the word.\t";
				++wrong;
			}
		}
		//shut down
		// If the recruit has made too many incorrect guesses
//     Tell the recruit that he or she has failed the Keywords II course.
		if (wrong == MAX_WRONG) {
			cout << "\nYou've been hanged!\t You lose!";
		}
		else {
			//     Congratulate the recruit on guessing the secret words
			cout << "\nYou guessed it right! You win!";
		}
		cout << "\n\tThe word was " << THE_WORD << endl;
		cout << "\t" << Username << endl;
		cout << "\nWould you like to play again?(y / n)";
		//user choice for end round
		cin.ignore();
		getline(cin, UsersChoiceToPlayAgain);
		//Analyze choice for user
		if (UsersChoiceToPlayAgain == "y" || UsersChoiceToPlayAgain == "Y" || UsersChoiceToPlayAgain == "yes" || UsersChoiceToPlayAgain == "YES" || UsersChoiceToPlayAgain == "Yes") {
			playAgain = true;
		}
		else {
			playAgain = false;
		}
		//     Display End of Simulations to the recruit
	} while (playAgain);
	return 0;
}