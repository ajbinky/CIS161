/*
Andy Behncke
Kinetic Energy
03/2014
AJBehncke1@dmacc.edu
*/

#include <iostream>
#include <string>

using namespace std;

double kineticEnergy(int, int);

int main()
{
	// Declaring variables for mass and velocity.
	int m, v;

	// Simply getting user input for mass and velocity.
	cout << "What is the mass of the object? (in KG)" << endl;
	cin >> m;
	cout << "What is the velocity of the object? (in M/S)" << endl;
	cin >> v;

	// Passes the mass and velocity into the function kineticEnergy() and prints the results in a readable format.
	cout << "The kinetic energy of this object is : " << kineticEnergy(m, v) << " Joules" << endl;
}

// Simple function to calculate the Kinetic Energy of an object, give its mass and velocity as parameters. Returns "KE".
double kineticEnergy(int m, int v)
{
	double KE = .5 * m * v * v;
	return KE;
}