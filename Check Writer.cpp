/*
Andrew Behncke
Check Writer
11/2014
AJBinky@gmail.com
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

void displayDate();
void cursor(int x, int y);
void wholeNumbers(double num);
void decimals(double num);

using namespace std;

class check {
private:
	string date;
	string name;
	double amount;
public:
	void setDate(string date) {

		check::date = date;
	}
	void setName(string name) {
		check::name = name;
	}
	void setAmount(double amount) {
		check::amount = amount;
	}
	void printDate() {
		cursor(41, 2);
		cout << "Date: " + date << endl;
	}
	void printName() {
		cursor(1, 6);
		cout << "Pay to the Order of: " + name << endl;
	}
	void printAmount() {
		cursor(50, 6);
		cout << "$";
		cout << fixed << setprecision(2) << showpoint << amount << endl;
	}
	string printWords() {
		cursor(1, 8);
		string ones[10] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
		string teens[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
		string tens[8] = { "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
		string finalString;
		int digit[4] = { (fmod(amount/1000, 10)), (fmod(amount / 100, 10)), (fmod(amount / 10, 10)), (fmod(amount, 10)) };
	
		if (digit[0] != 0) {
			finalString = ones[digit[0] - 1] + " thousand ";
		}
		if (digit[1] != 0) {
			finalString = finalString + ones[digit[1] - 1] + " hundred ";
		}
		if (digit[2] == 1) {
			finalString = finalString + teens[digit[3]] + " ";
		}
		else if (digit[2] != 0) {
			finalString = finalString + tens[digit[2] - 2] + " ";
			if (digit[3] != 0) {
				finalString = finalString + ones[digit[3] - 1] + " ";
			}
		}

		double x = floor(amount);
		double y = (amount - x) * 100;
		int z = y;

		if (z < 10) {
			finalString = finalString + "0" + to_string(z) + " cents";
		}
		else {
			finalString = finalString + to_string(z) + " cents";
		}

		return finalString;
	}
};

int main() {
	check obj = check();
	string x, y;
	double z;
	cout << "Enter date: ";
	cin >> x;
	cout << "Enter payee's name: ";
	cin.ignore();
	getline(cin, y);
	cout << "Enter amount on check: ";
	cin >> z;
	while (z <= 0 || z >= 10000) {
		cout << "Make sure the amount is between 0 and 10000: ";
		cin >> z;
	}
	obj.setDate(x);
	obj.setName(y);
	obj.setAmount(z);
	system("cls");
	obj.printDate();
	obj.printName();
	obj.printAmount();
	cout << obj.printWords() << endl;
}

void cursor(int x, int y) {
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(screen, position);
}