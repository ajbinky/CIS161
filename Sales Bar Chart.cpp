/*
Andy Behncke
Program name here
03/2014
AJBehncke1@dmacc.edu
*/

#include <iostream>
#include <string>

using namespace std;

// Function prototyping.
void stars(int x);

int main()
{

	int sales[3];

	// This for loop prompts user for the sales of each store.
	// Performs the number check asked for. (sales must be greater than or equal to 0.)
	// If (sales < 0) it goes to the label "here" which I conveniently placed before the last operation
	//		so it just prompts the user again for a valid input.
	for (int i = 0; i < 3; i++)
	{
	here:
		cout << "Enter today's sales for store " << i + 1 << ":" << endl;
		cin >> sales[i];
		if (sales[i] < 0)
		{
			cout << "Please input number greater than 0" << endl;
			goto here;
		}
	}


	// Prints out some boring stuff.
	cout << "    DAILY SALES" << endl;
	cout << "  (each * = $100)" << endl;


	// for loop that prints "store 'i': " and the correct number of stars.
	// Stars calculated from sales[i] / 100, as per requested. Passed through stars().
	for (int i = 0; i < 3; i++)
	{
		int numstar = sales[i] / 100;
		cout << "Store " << i + 1 << ":";
		stars(numstar);
	}

	return 0;
}


// Simple function to print x number of stars one after another.
void stars(int x)
{
	for (int z = 0; z < x; z++)
	{
		cout << "*";
	}
	cout << endl;
}