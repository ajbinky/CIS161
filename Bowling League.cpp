// Andrew Behncke
// Bowling League
// AJBehncke1@dmacc.edu

#include <iostream>
#include <string>

// finish stats and do teams

using namespace std;

int main()
{
	int player1[3];
	int stats1[3];
	int player2[3];
	int stats2[3];
	int player3[3];
	int stats3[3];
	cout << "Entar 3 scores for player one, seperated by spaces. (281 200 290)" << endl;
	cin >> player1[0] >> player1[1] >> player1[2];
	cout << "Entar 3 scores for player two, seperated by spaces. (281 200 290)" << endl;
	cin >> player2[0] >> player2[1] >> player2[2];
	cout << "Entar 3 scores for player three, seperated by spaces. (281 200 290)" << endl;
	cin >> player3[0] >> player3[1] >> player3[2];

	stats1[0] = (player1[0] + player1[1] + player1[2]) / 3;

	stats2[0] = (player2[0] + player2[1] + player2[2]) / 3;

	stats3[0] = (player3[0] + player3[1] + player3[2]) / 3;
	
	return 0;
}