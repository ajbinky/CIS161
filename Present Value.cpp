/*
Andrew Behncke
Present Value
9/2014
AJBehncke1@dmacc.edu
*/

#include <iostream>
#include <math.h>

using namespace std;

// Prototyping.
double presentValue(double, double, double);

int main()
{
	double F = 10000;
	double r = .00;
	double n;
	int i;
	bool guy = true;

	do // Always does calculation once.
	{
		cout << "Enter future value." << endl;
		cin >> F;
		cout << "Enter annual interest rate. (ie .03)" << endl;
		cin >> r;
		cout << "Enter number of years." << endl;
		cin >> n;

		cout << presentValue(F, r, n) << endl;

		cout << "\nCalculate another? (1. No - 2. Yes)" << endl;
		cin >> i;
		guy = i - 1;
	} while (guy == true); // Just a flag to see if user wants to rerun program.
}


// Function to perform calculation.
double presentValue(double F, double r, double n)
{
	double x = 1 + r;
	x = pow(x, n);
	return F/x;
}