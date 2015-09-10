/*
Andrew Behncke
Monkey Business
10/2014
AJBehncke1@dmacc.edu
*/

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

// Prototyping.
void monkeyInput();

int main()
{
	monkeyInput();
	return 0;
}


// I don't know why I made the entire thing a function instead of doing it in main or breaking it up more.
void monkeyInput()
{
	int average;
	double total = 0;
	double low = 0;
	double high = 0;
	int table[3][7];
	for (int i = 0; i < 3; i++)		// Nested for loop to fill all elements of the array.
	{
		int x = i;
		for (int i = 0; i < 7; i++)
		{
			int y = i;
			cout << "How many pounds did monkey " << x+1 << " eat on day " << y+1 << endl;
			cin >> table[x][y];

		}
	}
	system("cls");

	for (int i = 0; i < 3; i++)		// Nested for loop to add up all the elements of the array.
	{
		int x = i;
		for (int i = 0; i < 7; i++)
		{
			int y = i;
			total = total + table[x][y];
		}
	}
	average = total / 21;		// Calculates Average.
	low = table[0][0]; // This makes it so the logic for "lowest value" works.

	for (int i = 0; i < 3; i++) // Nested for loop to get the highest and lowest value of the array.
	{
		int x = i;
		for (int i = 0; i < 7; i++)
		{
			int y = i;
			if (table[x][y] < low)
			{
				low = table[x][y];
			}
			else if (table[x][y] > high)
			{
				high = table[x][y];
			}
		}
	}

	// Prints out the required information.
	cout << "The average amount of food eaten is " << average << " pounds of food." << endl;
	cout << "The lowest amount eaten on a certain day is " << low << " pounds of food." << endl;
	cout << "The highest amount eaten on a certain day is " << high << " pounds of food." << endl;
}