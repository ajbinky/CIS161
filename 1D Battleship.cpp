/*
Andrew Behncke
Battleship
9/2014
AJBehncke1@dmacc.edu
*/


#include <iostream>
#include <time.h>

using namespace std;

void PrintBoard(int[16]);

int main()
{
	// Seeding the rand() thing
	srand(time(0));

	// Variables
	bool complete = false;
	int score1 = 0;
	int score2 = 0;
	int p1[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int p2[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i, x, y;
	int empty = 0;
	int miss = 1;
	int hit = 2;
	int boat = 3;

	// Player enters where they want their 4 space boat
	PrintBoard(p1);
BOAT3:
	cout << "\nWhere would you like your Submarine to start? (1-14)" << endl;
	cin >> i;
	if (i<1 || i > 14)
	{
		cout << "Please enter valid number." << endl;
		goto BOAT3;
	}
	p1[i - 1] = boat;
	p1[i + 0] = boat;
	p1[i + 1] = boat;
	// 3 space boat entered


	system("cls");
	PrintBoard(p1);

	// Player enters where they want their 2 space boat
BOAT2:
	cout << "\nWhere would you like your PT Boat to start? (1-15, can't overlap)" << endl;
	cin >> i;
	if (p1[i-1]==empty && p1[i]==empty)
	{
		p1[i - 1] = boat;
		p1[i + 0] = boat;
	}
	else
	{
		cout << "Please enter valid number.";
		goto BOAT2;
	}
	// 2 space boat entered

	system("cls");
	PrintBoard(p1);

	// Player enters where they want their 2 space boat
BOAT1:
	cout << "\nWhere would you like your Life Raft to start? (1-15, can't overlap)" << endl;
	cin >> i;
	if (i<1 || i > 14)
	{
		cout << "Please enter valid number.";
		goto BOAT1;
	}
	else if (p1[i - 1] == empty)
	{
		p1[i - 1] = boat;
	}
	else
	{
		cout << "Please enter valid number.";
		goto BOAT1;
	}
	// 1 space boat entered

	// Initialize Computer Player Boats
	system("cls");
	PrintBoard(p1);

	i = rand();
	i = i % 13;
	p2[i] = boat;
	p2[i + 1] = boat;
	p2[i + 2] = boat;
	// Computer Player 3 space boat initialized.


	// Should rewrite these so take out the use of x and y variables.
	NEW:
	x = (i + rand()) % 15;
	if (x >= (i - 2) && x <= i + 2)
	{
		goto NEW;
	}
	else
	{
		p2[x] = boat;
		p2[x + 1] = boat;
	 }
	// Computer Player 2 space boat initialized.

	OLD:
	y = (x + rand()) % 15;
	if (p2[y]==3)
	{
		goto OLD;
	}
	else
	{
		p2[y] = boat;
	}
	// Computer Player 1 space boat initialized.


	while (score1 < 6 && score2 < 6)
	{
		system("cls");
		PrintBoard(p1);

	P1Start:
		cout << "Your turn. Enter 1-16." << endl;
		cin >> i;
		i -= 1;
		if (i >= 16 || i <= -1)
		{
			cout << "Enter valid number." << endl;
			goto P1Start;
		}
		else if (p2[i] == hit || p2[i] == miss)
		{
			cout << "You already tried there. Try again." << endl;
			goto P1Start;
		}
		else if (p2[i] == empty)
		{
			cout << "Miss!" << endl;
			p2[i] = miss;
		}
		else if (p2[i] == boat)
		{
			cout << "Hit!" << endl;
			p2[i] = hit;
			score1 += 1;
		}
		// Player 1 is finished with his/her turn.
		if (score1 == 6)
		{
			break;
		}

	CPSTART:
		i = rand() % 16;
		i -= 1;
		if (p1[i] == hit || p1[i] == miss)
		{
			goto CPSTART;
		}
		else if (p1[i] == empty)
		{
			cout << "\nThe Computer Player Missed at " << i+1 << "!" << endl;
			p1[i] = miss;
		}
		else if (p1[i] == boat)
		{
			cout << "\nThe Computer Player Hit at " << i+1 <<"!" << endl;
			p1[i] = hit;
			score2 += 1;
		}
		// CP is done with turn.

		system("PAUSE");

	}

	if (score1 == 6)
	{
		cout << "Winner!!!" << endl;
		PrintBoard(p1);
		PrintBoard(p2);
	}
	else
	{
		cout << "Loser..." << endl;
		PrintBoard(p1);
		PrintBoard(p2);
	}
	

	return 0;
}

void PrintBoard(int p1[16]){

	cout << "123456789*123456     <---Location" << endl;
	cout << p1[0] << p1[1] << p1[2] << p1[3] << p1[4] << p1[5] << p1[6] << p1[7] << p1[8] << p1[9] << p1[10] << p1[11] << p1[12] << p1[13] << p1[14] << p1[15] << "     (3=boat 2=hit 1=miss 0=empty)" << endl;
}