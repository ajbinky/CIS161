/*
Andy Behncke
DMACC Vidbox
04/2014
AJBehncke1@dmacc.edu
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void Rent_Return();
int Return();
void Rent();
void Admin();
void Summary();
void Withdrawal();
void Close_Down();

int go = 1;
int DVD;
int Money;
int ID;

int main()
{
	ifstream inFile;
	inFile.open("dayin00.dat");
	inFile >> DVD;
	inFile >> Money;
	inFile.close();

	while (go != 0)
	{
		here:
		cout << "Please input your ID." << endl;
		cin >> ID;

		if ((ID > 9999 && ID < 100000) && ID != 99959)
		{
			Rent_Return();
		}
		else if (ID < 10000 || ID > 99999)
		{
			cout << "Please enter valid ID." << endl;
			goto here;
		}
		else if (ID = 99959)
		{
			Admin();
		}
	}
	return 0;
}

void Rent_Return()
{
	int Choice = 0;
	cout << "Would you like to rent or return movies? (1 = rent 2 = return)" << endl;
	cin >> Choice;
	switch (Choice)
	{
	case 1: Rent();
		break;
	case 2: Return();
		break;
	default: cout << "Please enter valid number." << endl;
		Rent_Return();
	}
	return;
}

int Return()
{
	int returns = 0;
	cout << "How many DVDs will be returned?" << endl;
	cin >> returns;
	DVD += returns;
	cout << "Thank you for using our vidbox!" << endl;
	return returns;

	ofstream outFile;
	outFile.open("current11.dat");
	outFile << returns << "DVDs returned." << endl;
	outFile.close();
}

void Rent()
{
	double total;
	// double calc;
	double tax = 1.07, discount = 1.35;
	int freetop10, freenew, freestandard;
	int top10, newmovies, standard;
	cout << "How many Top 10 movies would you like?" << endl;
	cin >> top10;
	cout << "How many new movies would you like?" << endl;
	cin >> newmovies;
	cout << "How many standard movies would you like?" << endl;
	cin >> standard;

	
	freetop10 = top10 / 3;
	freenew = newmovies / 3;
	freestandard = standard / 3;

	total = (((top10 - freetop10) * 4.99) + ((newmovies - freenew) * 3.99) + ((standard - freestandard) * 2.99)) * tax;
	if (ID > 89999 && ID < 100000)
	{
		total *= discount;
	}

	cout << "Your total for " << top10 + newmovies + standard << " DVDs is $";
	cout << setprecision(2) << fixed << total << endl;
	cout << "Thanks for using this vidbox!" << endl;
	Money += total;
	DVD -= top10 + newmovies + standard;

	ofstream outFile;
	outFile.open("current11.dat");
	outFile << top10 + newmovies + standard << " DVDs rented and $" << Money << " added." << endl;
	outFile.close();
}

void Admin()
{
	int choice = 0;

	there:
	cout << "Press 1 for Summary, 2 for Withdrawal, 3 for Close Down." << endl;
	cin >> choice;
		switch (choice)
		{
		case 1: {Summary();
			break; }
		case 2: {Withdrawal();
			break; }
		case 3: {Close_Down();
			break; }
		default: {cout << "Please enter valid number." << endl;
			goto there; }
		}
	return;
}

void Summary()
{
	cout << "Current DVDs: " << DVD << endl;
	cout << "Current Money: " << Money << endl;
}

void Withdrawal()
{
	int Withdraw;

	cout << "How much would you like to take out?" << endl;
	cin >> Withdraw;
	Money -= Withdraw;
}

void Close_Down()
{
	ofstream outFile;
	outFile.open("dayout99.dat");
	outFile << DVD << " DVDs currently in unit." << endl;
	outFile << "$" << Money << " Money currently in unit." << endl;
	go = 0;
	return;
}