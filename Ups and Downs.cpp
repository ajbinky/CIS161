/*
Andrew Behncke
Ups and Downs
10/2014
AJBehncke1@dmacc.edu
*/

#include <iostream>
#include <Windows.h>

using namespace std;

// Prototyping.
void displayUp(int z);
void displayDown(int z);

int main()
{

	// Loop that displays the two words
	for (int i = 0; i < 24; i++)
	{
		system("cls");
		displayUp(24 - i);		// These arguments are the Y
		displayDown(i + 1);		// coordinates for the screen location coordinate.
		Sleep(1000);
	}
	system("cls");
	return 0;
}


// Function to display "UP" at specified coordinate.
void displayUp(int z)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = 35;
	position.Y = z;
	SetConsoleCursorPosition(screen, position);
	cout << "UP" << endl;
}

// Function to display "DOWN" at specified coordinate.
void displayDown(int z)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = 41;
	position.Y = z;
	SetConsoleCursorPosition(screen, position);
	cout << "DOWN" << endl;
}