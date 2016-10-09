// cs101 - Find the tokens (words) in a given sentence.
// Read an entire line from input into a string and output the individual words.

#include <iostream>
#include <string>
using namespace std;

class tokenizer {
  private:
	string sentence;
  public:
	tokenizer () {sentence = " ";}; // default constructor.
	tokenizer (string str); // constructor.
	void readSentence(); // Read a sentence from input.
	void printSentence(); // Print the sentence.
	void printTokens(); // Print the words in the sentence.
};

tokenizer::tokenizer(string str) {
	sentence = str;
}
void tokenizer::readSentence() {
	getline (cin, sentence);	
}
void tokenizer::printSentence() {
	cout << sentence << endl;	
}
void tokenizer::printTokens() {
	string str1, str2;
	int pos;
	str1 = sentence;
	do {
		pos = str1.find(" ");
		str2 = str1.substr(0, pos);
		cout << str2 << endl;
		str1 = str1.substr(pos+1, '$');
	} while (pos != -1); //str1.find() returns -1 if " " is not found
}

int main() {
tokenizer s1;
tokenizer s2 ("This is a line");

	s1.printSentence();
	s2.printSentence();
	s2.printTokens();

	s1.readSentence();
	s1.printSentence();
	s1.printTokens();
}
