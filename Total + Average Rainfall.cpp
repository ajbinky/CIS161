/*
Andy Behncke
Using Files - Total and Average Rainfall (modified for old edition)
4/14
AJBehncke1@dmacc.edu
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
I had the old version of the book, so I had to do a modified version of that was asked.
I will quote the problems again for you in the email that I attach these to.
The problem said to take specifically 3 months, originally. This was when it was supposed to get the data from cin.
I did a little bit more than it asks, and made it read all the lines in the file.
It does make the output of this pretty messy if there are many lines in the file, but it get's the job done.
*/

int main()
{
	string month;
	double inches = 0;
	double totalin = 0;
	int i = 0;
	ifstream inFile;
	inFile.open("rainfall.txt");

	// Reads every line of file, adding up all the inches of rain to "totalin" and counting number of lines with "i".
	// File must have lines with this format: "month inches"
	// For example... "Jan 10"
	while (inFile >> month >> inches)
	{
		cout << "The month of " << month << " had " << inches << " inches of rain." << endl;
		totalin += inches;
		i++;
	}

	// Just prints out the total and average amount of rain calculated from all the months in the file.
	// Average calculated by taking the total inches of rain from all months divided by i, which is the number of months/lines there were.
	cout << "The total amount of rain over these months was " << totalin << " inches." << endl;
	cout << "The average aount of rain over these months was " << (totalin / i) << " inches." << endl;

	inFile.close();
	return 0;
}