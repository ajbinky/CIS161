//Edwin Capel
//Assignment1-Battleship
//9/15/2014
//ercapel@dmacc.edu

//A battleship game with only a single 16 row, you have three boats the submarine- 3 spaces , pt-boat- 2 space and
//a life raft 1 spacce

#include <iostream>
#include <iomanip>

using namespace std;

//main fucntion
int main(){


	//user variables
	int submarine1, submarine2, submarine3, comsubmarine1, comsubmarine2, comsubmarine3;
	int	ptboat1, ptboat2, comptboat1, comptboat2, liferaft1, comliferaft1, user;

	//random fuction so that the computer doesnt random the same set of number all the time
	srand(time(NULL));

	//menu
	cout << "******BATTLE SHIP****** !" << endl;
	cout << " " << endl;
	//user key in location

	//ask user for subamrine initial location
	cout << "Where would you like to place your submarine : ";
	cin >> submarine1;
	
	//check value bound within board range
	while (submarine1 >= 17||submarine1<=0){
		cout << "Re- enter value : Where would you like to place your submarine : ";
		cin >> submarine1;
	}

	//place the rest of the parts of the subamrine
	submarine2 = submarine1 + 1;
	submarine3 = submarine1 + 2;

	//ask user for pt boat initial location
	cout << "Where would you like to place your pt boat : ";
	cin >> ptboat1;
	while (ptboat1 == submarine1 || ptboat1 == submarine2 || ptboat1 == submarine3 || ptboat1 >= 17||ptboat1<=0){

		cout << "Re - enter value : Where would you like to place your pt boat : ";
		cin >> ptboat1;

	}

	//place the rest of pt boat
	ptboat2 = ptboat1 + 1;

	//ask user for life raft location
	cout << "Where would you like to placce your life raft : ";
	cin >> liferaft1;
	while (liferaft1 == submarine1 || liferaft1 == submarine2 || liferaft1 == submarine3 || liferaft1 == ptboat1 || liferaft1 == ptboat2 || liferaft1 >= 17||liferaft1<=0){
		cout << "Re - enter value : Where would you like to placce your life raft : ";
		cin >> liferaft1;
	}
	//computer boat locations

	//submarine location
	comsubmarine1 = rand() % 16 + 1;
	while (comsubmarine1 >= 17||comsubmarine1<=0){
		comsubmarine1 = rand() % 16 + 1;
	}
	comsubmarine2 = comsubmarine1 + 1;
	comsubmarine3 = comsubmarine1 + 2;

	//pt boat location
	comptboat1 = rand() % 16 + 1;
	comptboat2 = comptboat1 + 1;
	while (comptboat1 == comsubmarine1 || comptboat1 == comsubmarine2 || comptboat1 == comsubmarine3 || comptboat1 >= 17 || comptboat2 == comsubmarine1 || comptboat2 == comsubmarine2 || comptboat2 == comsubmarine3 || comptboat2 >= 17||comptboat2<=0){

		comptboat1 = rand() % 16 + 1;
		comptboat2 = comptboat1 + 1;

	}

	//life raft location
	comliferaft1 = rand() % 16 + 1;
	while (comliferaft1 == comsubmarine1 || comliferaft1 == comsubmarine2 || comliferaft1 == comsubmarine3 || comliferaft1 == comptboat1 || comliferaft1 == comptboat2 || comliferaft1 >= 17||comliferaft1<=0){
		comliferaft1 = rand() % 16 + 1;
	}
	cout << " " << endl;

	//game statistiv variable
	int win = 0;
	int userSubHit1 = 0, userSubHit2 = 0, userSubHit3 = 0, comSubHit1 = 0, comSubHit2 = 0, comSubHit3 = 0;
	int userPtHit1 = 0, userPtHit2 = 0, comPtHit1 = 0, comPtHit2 = 0;
	int userLifeHit = 0, comLifeHit = 0;
	int userSubSunk = 0, userPtSunk = 0, userLifeSunk = 0, comSubSunk = 0, comPtSunk = 0, comLifeSunk = 0;

	//game begins
	cout << "LET THE GAME BEGIN !" << endl;
	do{
		//user turn
		cout << "Your Turn : ";
		cin >> user;
		while (user >= 17||user<=0){
			cout << "Error : Your Turn : ";
			cin >> user;
		}
		if (user == comsubmarine1 || user == comsubmarine2 || user == comsubmarine3 || user == comptboat1 || user == comptboat2 || user == comliferaft1){
			cout << "hit! @ " << user << endl;
		}
		else{
			cout << "FAIL - no hit" << endl;
		}

		//to keep track of part of boat hit
		if (user == comsubmarine1){
			userSubHit1 = 1;
		}
		else if (user == comsubmarine2){
			userSubHit2 = 1;
		}
		else if (user == comsubmarine3){
			userSubHit3 = 1;
		}
		else if (user == comptboat1){
			userPtHit1 = 1;
		}
		else if (user == comptboat2){
			userPtHit2 = 1;
		}
		else if (user == comliferaft1){
			userLifeHit = 1;
		}

		if (userSubHit1 == 1 && userSubHit2 == 1 && userSubHit3 == 1){
			userSubSunk = 1;
			cout << "User Has Sunked the Computers Submarine !" << endl;
		}
		if (userPtHit1 == 1 && userPtHit2 == 1){
			userPtSunk = 1;
			cout << "User Has Sunked the Computers Pt Boat !" << endl;
		}
		if (userLifeHit == 1){
			userLifeSunk = 1;
			cout << "User Has Sunked the Computers Life Raft" << endl;
		}
		//check if all submarines have sunk
		if (userSubSunk == 1 && userPtSunk == 1 && userLifeSunk == 1){
			cout << " " << endl;
			cout << "CONGRATULATION - YOU HAVE WON!" << endl;
			cout << " " << endl;
			cout << "computer's boat lacations " << comsubmarine1 << " " << comsubmarine2 << " " << comsubmarine3 << " " << comptboat1 << " " << comptboat2 << " " << comliferaft1 << endl;
			cout << " " << endl;
			return win = 1;
		}
		cout << " " << endl;

		//computer's turn
		int com = rand() % 16 + 1;
		cout << "Computer's Turn : " << com << endl;
		while (user >= 17||user<=0){
			int com = rand() % 16 + 1;
			cout << "Computer's Turn : " << com << endl;
		}
		if (com == submarine1 || com == submarine2 || com == submarine3 || com == ptboat1 || com == ptboat2 || com == liferaft1){
			cout << "Computer Hit ! @" << com << endl;
		}
		else{
			cout << "FAIL - no hit" << endl;
		}

		//to keep track of part of boat hit
		if (com == submarine1){
			comSubHit1 = 1;
		}
		else if (com == submarine2){
			comSubHit2 = 1;
		}
		else if (com == submarine3){
			comSubHit3 = 1;
		}
		else if (com == ptboat1){
			comPtHit1 = 1;
		}
		else if (com == ptboat2){
			comPtHit2 = 1;
		}
		else if (com == liferaft1){
			comLifeHit = 1;
		}

		//computer
		if (comSubHit1 == 1 && comSubHit2 == 1 && comSubHit3 == 1){
			comSubSunk = 1;
			cout << "The Computer Has Sunked the User's Submarine !" << endl;
		}
		if (comPtHit1 == 1 && comPtHit2 == 1){
			comPtSunk = 1;
			cout << "The Computer Has Sunked the User's Pt Boat" << endl;
		}
		if (comLifeHit == 1){
			comLifeSunk = 1;
			cout << "The Computer Has Sunked the User's Life Raft" << endl;
		}
		//check if all submarines have sunken
		if (comSubSunk == 1 && comPtSunk == 1 && comLifeSunk == 1){
			cout << " " << endl;
			cout << "SORRY - YOU LOST! PLEASE TRY AGAIN" << endl;
			cout << " " << endl;
			cout << "computer's boat lacations " << comsubmarine1 << " " << comsubmarine2 << " " << comsubmarine3 << " " << comptboat1 << " " << comptboat2 << " " << comliferaft1 << endl;
			cout << " " << endl;
			return win = 1;
		}

		cout << " " << endl;
	} while (win != 1);

return 0;
}