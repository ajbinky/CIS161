/*
Andrew Behncke
Rate of Inflation
9/2014
AJBehncke1@dmacc.edu
*/

#include <iostream>

using namespace std;

// Prototyping.
double Rate(double, double);

int main()
{
	double current = 1000;
	double ROE = .00;
	const int years = 10;

	// Simple number checking for the rate.
	while (ROE < .01 || ROE > .15)
	{
		cout << "Enter rate of inflation (between .01 and .15)" << endl;
		cin >> ROE;
	}
	
	// Display 10 numbers.
	for (int i = 0; i < 10; i++)
	{
		cout << Rate(ROE, current) << endl;
		current = Rate(ROE, current);
	}

}

// Function for calculating.
double Rate(double x, double y)
{
	return ( 1 / (1 + x) ) * y;
}