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
	double x;
	double sumo[3][7];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			HERE:
			cout << "Enter weight of sumo " << i+1 << " for day " << j+1 << ". ";
			cin >> x;
			if (x < 150 || x > 999)
			{
				goto HERE;
			}
			else {
				sumo[i][j] = x;
			}
		}
	}

	double avg1 = 0;
	double avg2 = 0;
	double avg3 = 0;

	for (int i = 0; i < 7; i++)
	{
		avg1 += sumo[0][i];
	}
	avg1 = avg1 / 7;

	for (int i = 0; i < 7; i++)
	{
		avg2 += sumo[1][i];
	}
	avg2 = avg2 / 7;

	for (int i = 0; i < 7; i++)
	{
		avg3 += sumo[2][i];
	}
	avg3 = avg3 / 7;

	cout << "average for sumo 1: " << avg1;
	cout << "average for sumo 2: " << avg2;
	cout << "average for sumo 3: " << avg3;

	return 0;
}