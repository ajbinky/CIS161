/*
Andrew Behncke
Arithmetic Exceptions
11/2014
AJBinky@gmail.com
*/

// Couldn't quite get the hang of this one.

#include <iostream>
#include <string>

using namespace std;

void selectionSort(string[], int);
void showArray(string[], int);

int main() {
	const int SIZE = 20;

	string name[SIZE] =
	{
		"Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
		"Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
		"Allison, Jeff", "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
		"Moretti, Bella", "Wu, Hong", "Patel, Renee", "Harrison, Rose",
		"Smith, Cathy", "Conroy, Pat", "Kelly, Sean", "Holland, Beth"
	};



	cout << "The unsorted values are" << endl;
	showArray(name, SIZE);

	selectionSort(name, SIZE);

	cout << "The sorted values are" << endl;
	showArray(name, SIZE);

	return 0;
}

void selectionSort(string sortThis[], int size) {
	int startScan, minIndex;
	string minValue;
	for (int i = 0; i < (size - 1); i++) {
		minIndex = i;
		minValue = sortThis[i];
		for (int j = (i + 1); j < size; j++) {
			if (sortThis[j].at(0) < minValue.at(0)) {
				minValue = sortThis[j];
				sortThis[i] = minValue;
			}
		}
	}
}

void showArray(string printThis[], int size) {
	for (int i = 0; i < size; i++) {
		cout << printThis[i] << endl;
	}
}