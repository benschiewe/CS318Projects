/*
Name: Ben Schiewe
Course: CS318
Project: P02 Bulls and Cows
File: Source.cpp

Project Description:

"Create a C++ project for the guessing game called "Bull and Cows"

The program randomly generates four different integers in the range 0 to 9 and
stores them in an answer vector.

The user’s task is to discover the numbers in the answer vector by repeated guesses.

The user should be able to play this repeatedly – "Play again?"
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

std::vector<int> generateAnswer(int maxDigits);
void getValidGuess(int maxDigits, std::vector<int>& guessVec);
void getGuesses(std::vector<int>& answerVec, int maxDigits);
bool hasOnlyDigits(const std::string& s);
bool isUnique(const std::string& s);


int main() {
	srand(time(0));
	std::cout << "*** P02 Bulls and Cows ***\n\n";
	std::cout << "************* New Game *************\n";

	std::vector<int> answer;
	std::string response;
	const int MAX_NUMBERS = 4;

	do {
		answer = generateAnswer(MAX_NUMBERS);
		std::cout << "\nNumber to Guess: ";
		for (int i : answer)	std::cout << i;
		std::cout << "\n\n";

		getGuesses(answer, MAX_NUMBERS);

		std::cout << "Enter Y to play again (anything else to end): ";
		std::cin >> response;
	} while (response == "y");													//Repeat as long as user inputs 'y'
}


std::vector<int> generateAnswer(int maxDigits) {
	std::vector<int> v;
	v.push_back(rand() % 10);

	int x;
	for (int i = 1; i < maxDigits; i++) {
		do {
			x = rand() % 10;
		} while (std::find(v.begin(), v.end(), x) != v.end());					//Generate a new x until we find one that is not repeated
		v.push_back(x);
	}

	return v;
}


void getValidGuess(int maxDigits, std::vector<int>& guessVec) {
	std::string guessString;
	bool c = false;

	do {
		std::cout << "\tEnter guess: ";
		std::cin >> guessString;

		if (guessString.length() != maxDigits) {
			std::cout << "\t\tGuess must be 4 digits -- try again!\n\n";
			c = true;
		}
		else if (!hasOnlyDigits(guessString)) {
			std::cout << "\t\tGuess can only contain digits -- try again!\n\n";
			c = true;
		}
		else if (!isUnique(guessString)) {
			std::cout << "\t\tDigits can not be repeated -- try again!\n\n";
			c = true;
		}
		else	c = false;
	} while (c);																//Repeat up until we get valid input (none of the if's execute)

	for (int i = 0; i < guessVec.size(); i++) {
		guessVec[i] = int(guessString[i]) - '0';								//Effectively returns the vector, since we pass a reference into function
	}
}


void getGuesses(std::vector<int>& answerVec, int maxDigits) {
	std::cout << "\tGuesses entered must be digits 0-9, 4 digits long, no repitition.\n\n";

	int bulls = 0, cows = 0, loop = 0;
	bool cont = true;
	std::vector<int> guessVec(maxDigits);

	do {
		getValidGuess(maxDigits, guessVec);

		bulls = 0, cows = 0, loop++;											//Reset vars, loop counter for output
		bool guessArr[10] = { false }, answerArr[10] = { false };

		for (int i = 0; i < guessVec.size(); i++) {
			int guess = guessVec[i], answer = answerVec[i];
			if (guess == answer)	bulls++;									//If guess[i] == answer[i]... found a bull
			else {
				guessArr[guess] = true;											//Only flip bools if the digit is not a bull
				answerArr[answer] = true;										//Works since we know there are no repeat digits
			}
		}
		for (int i = 0; i < 10; i++) {
			if (guessArr[i] && answerArr[i])	cows++;							//Array of 10 bools - ex. if we find 7 in both vectors,
		}																		//then guess[7] and num[7] are both set to true once loop finishes. Thus, a cow
		
		std::cout << "\t\tGuess #" << loop << ": Bulls " << bulls << " Cows " << cows << "\n\n";

		if (bulls == maxDigits) {
			std::cout << "\t*** YOU WIN ***\n\n";
			cont = false;
		}
	} while (cont);																//Loop until c == false
}


bool hasOnlyDigits(const std::string& s) {
	for (char c : s) {
		if (int(c) < 48 || int(c) > 57)	return false;							//ASCII... 48-57 are '0'-'9'. If outside this range, not a digit
	}
	return true;
}

bool isUnique(const std::string& s) {
	bool nums[10] = { 0 };

	for (char c : s) {
		if (nums[int(c) - '0'])	return false;									//Similar logic to the cow functionality...
		else nums[int(c) - '0'] = true;												//c - '0' is the actual digit, since c++ treats chars as a uint8_t
	}																			//Example: s[0] is the digit 1. Then we set nums[1] = true
	return true;																//If we find that s[2] is also 1, we hit the "return false"
}																				//Since we have found a repeat digit. O(n) rather than O(n^2)