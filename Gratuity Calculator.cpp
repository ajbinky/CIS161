/*
Andrew Behncke
Gratuity Calculator
10/2014
AJBehncke1@dmacc.edu
*/

#include <iostream>
#include <string>

using namespace std;

// Prototyping.
class Tips
{
private:
	double taxRate;

public:
	Tips(double x)
	{
		taxRate = x;
	}
	Tips()
	{
		taxRate = 0.065;
	}
	double computeTip(double totalBill, double tipRate)
	{
		double meal = totalBill - (totalBill*taxRate);
		return meal * tipRate;
	}
};

int main()
{
	int i=0;
	double y;
	Tips(.035);
	while (i != -1)
	{
		cout << "Enter total bill, and tip rate seperated by one space (120 .2)" << endl;
		cout << "Or enter -1 to quit" << endl;
		cin >> i >> y;
		cout << "The tip amount is " << tip().computeTip(i, y) << endl;

	}
	return 0;
}