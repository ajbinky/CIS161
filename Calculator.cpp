/*
Andy Behncke
Program A (Calculator)
3/13/14
AJBehncke1@dmacc.edu
*/
#include <iostream>
#include <string>
using namespace std;

// Mathematical functions
double add(double x, double y)
{
	return x + y;
}

double subtract(double x, double y)
{
	return x - y;
}

double multiply(double x, double y)
{
	return x * y;
}

double divide(double x, double y)
{
	return x / y;
}

int perc(int x, int y)
{
	return x % y;
}


// Getting user input and looping and stuff.
int main()
{
	double x = 0, y = 0;
	char funct = 0;
	cout << "Enter a simple mathematical statement, such as \"3 - 13\"" << endl;
	cout << "Valid operations are (= - * / %)" << endl;
	cout << "Make sure there is a space between each number and the symbol." << endl;
	cout << "Enter \"0 0 0\" to stop." << endl; // Couldn't figure out a better way to accomplish this.
	do
	{
		cin >> x >> funct >> y;
		switch (funct)
		{
		case 43:
			cout << x << " + " << y << " = " << add(x, y) << endl;
			break;
		case 45:
			cout << x << " - " << y << " = " << subtract(x, y) << endl;
			break;
		case 42:
			cout << x << " * " << y << " = " << multiply(x, y) << endl;
			break;
		case 47:
			cout << x << " / " << y << " = " << divide(x, y) << endl;
			break;
		case 37:
			cout << x << " % " << y << " = " << perc(x, y) << endl;
			break;
		default:
			break;
		}; 
	} while (!(x == 0 && funct == 48 && y == 0));


	return 0;
}