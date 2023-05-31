#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordEntry 
{
	private:
		string word;  // The word
		int numAppearances;  // Number of appearances of the word
		int totalScore;  // Total score of the word

	public:
		// Constructor
		WordEntry(const string &, int);

		// Member functions
		void addNewAppearance(int);  // Add a new appearance of the word with the given score
		const string & getWord() const;  // Get the word
		double getAverage() const;  // Get the average score for the word
};

#endif
