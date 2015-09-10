/*
Andrew Behncke
Arithmetic Exceptions
11/2014
AJBinky@gmail.com
*/
#include <iostream>
#include <string>

using namespace std;

class CharConverter {
private:
public:

	string uppercase(string words) {
		for (int i = 0; i < words.length(); i++) {
			if (words[i] >= 97 && words[i] <= 122) {
				words[i] = words[i] - 32;
			}
		}
		return words;
	}

	string properWords(string words) {
		if (words[0] >= 97 && words[0] <= 122) {
			words[0] = words[0] - 32;
		}
		for (int i = 0; i < words.length(); i++) {
			if (words[i] == 32 && ((words[i+1]) >= 97 && (words[i+1]) <= 122)) {
				(words[i+1]) = (words[i+1]) - 32;
			}
		}
		return words;
	}
};

int main() {
	string thisString;
	CharConverter CC;
	cout << "At any time, enter 'exit' to quit the program." << endl;
	while (thisString != "exit") {
		cout << "Enter a string to be converted: ";
		getline(cin, thisString);
		if (thisString != "exit") {
			cout << CC.properWords(thisString) << endl;
			cout << CC.uppercase(thisString) << endl;
		}
	}
	return 0;
}