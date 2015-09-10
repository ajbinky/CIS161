/*
Andrew Behncke
one roll bowling
11/2014
AJBehncke1@dmacc.edu
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x;
	int total = 0;
	int score[10];

	for (int i = 0; i < 10; i++)
	{
		HERE:
		cout << "Enter frame " << i+1 << " ";
		cin >> x;
		if (x < 0 || x > 10)
		{
			cout << "please enter valid number" << endl;
			goto HERE;
		}
		else {
			score[i] = x;
			total += x;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (score[i] == 10)
		{
			total += score[i + 1];
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (score[i] == 10)
		{
			score[i] += score[i + 1];
			total += score[i + 1];
		}
	}

	cout << total << "is the final score" << endl;

	return 0;
}