/*
Andrew Behncke
Arithmetic Exceptions
11/2014
AJBinky@gmail.com
*/
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

int mode(int[], int);

int main() {
	const int size = 30;
	int response[size];
	srand(time(0));

	for (int i = 0; i < size; i++) {
		response[i] = rand() % 10;
	}

	for (int i = 0; i < size; i++) {
		cout << response[i] << " ";
	}
	
	sort(response, response + size);

	cout << endl << mode(response, size) << endl;

	return 0;
}

int mode(int num[], int size) {

	int counter = 1;
	int max = 0;
	int mode = num[0];
	for (int i = 0; i < size - 1; i++)
	{
		if (num[i] == num[i + 1])
		{
			counter++;
			if (counter > max)
			{
				max = counter;
				mode = num[i];
			}
		}
		else
			counter = 1;
	}
	return mode;
}