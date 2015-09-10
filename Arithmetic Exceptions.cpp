/*
Andrew Behncke
Arithmetic Exceptions
11/2014
AJBinky@gmail.com
*/
#include <iostream>

using namespace std;

int squareRoot(int);


class SqrtException {
private:
	int a;
public:
	SqrtException(int a) {
		this->a = a;
	}
	int getArgument() {
		return a;
	}
};

int main() {
	
	
	for (int i = 0; i < 4; i++) {
		try {
			int num;
			int sqrt;
			cout << "Enter a number: ";
			cin >> num;
			sqrt = squareRoot(num);
			cout << "The integer square root is: " << sqrt << endl;
		}
		catch (SqrtException x) {
			int badArg = x.getArgument();
			cout << badArg << " does not have an integer square root." << endl;
		}
	};

}

int squareRoot(int num) {
	int i = 0;
	while (i * i < num) {
		i++;
	}
	if (i * i == num) return i;
	throw SqrtException(num);
}