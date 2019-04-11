// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

struct Point {
	int posX = 0;
	int posY = 0;
};

struct Ship {
	Point ship_center;
	vector <Point> ship_location;
	int num_hit = 0;
	bool is_equal(int bombX, int bombY);
	void cal_location();

};
bool Ship::is_equal(int bombX, int bombY) {   // target hit
	bool targetHit = false;
	for (int i = 0; i < ship_location.size(); i++) {
		if (ship_location[i].posX == bombX && ship_location[i].posY == bombY) {
			targetHit = true;
		}

	}
	return targetHit;
}

void Ship::cal_location() {
	Point p1, p2, p3, p4, p5, p6, p7, p8, p9;
	p1.posX = ship_center.posX ;
	p1.posY = ship_center.posY ;
	ship_location.push_back(p1);
	p2.posX = ship_center.posX - 1;
	p2.posY = ship_center.posY - 1;
	ship_location.push_back(p2);
	p3.posX = ship_center.posX + 1;
	p3.posY = ship_center.posY + 1;
	ship_location.push_back(p3);
	p4.posX = ship_center.posX - 2;
	p4.posY = ship_center.posY - 2;
	ship_location.push_back(p4);
	p5.posX = ship_center.posX + 2;
	p5.posY = ship_center.posY + 2;
	ship_location.push_back(p5);
	p6.posX = ship_center.posX - 3;
	p6.posY = ship_center.posY - 3;
	ship_location.push_back(p6);
	p7.posX = ship_center.posX + 3;
	p7.posY = ship_center.posY + 3;
	ship_location.push_back(p7);
	p8.posX = ship_center.posX - 4;
	p8.posY = ship_center.posY - 4;
	ship_location.push_back(p8);
	p9.posX = ship_center.posX + 4;
	p9.posY = ship_center.posY + 4;
	ship_location.push_back(p9);



}

void battle_ship() {
	Ship s1; // s1 is now ship. s1.variable to assign data to variable in Ship

	cout << "Enter ship location; \n";
	cout << "X location: ";
	cin >> s1.ship_center.posX;
	cout << "Y location: ";
	cin >> s1.ship_center.posY;
	s1.cal_location();


	int bX, bY;
	int miss = 0;

	bool game_over = false;

	while (!game_over) {

		cout << "Enter bomb location: \n";
		cout << "Enter X location to bomb: \n";
		cin >> bX;
		cout << "Enter Y location to bomb: \n";
		cin >> bY;


		for (int i = 3; i >= s1.num_hit; i++)


			if (s1.is_equal(bX, bY)) {
				s1.num_hit++;
				cout << "Direct hit! ";
				cout << "You have " << s1.num_hit << " hits" << endl;
				break;
			}

			else {
				cout << "You miss. \n";
				miss++;
				cout << "You have missed " << miss << " times." << endl;
				break;
			}

		if (s1.num_hit == 3) {

			cout << "Your battleship has been sunk. " << endl;
			game_over = true;
			break;
		}


	}
}

int main()
{
	
	cout << "Battleship!" << endl;

	battle_ship();
	char user_input;
	bool game_over = true;
	
	cout << "Game over!" << endl;
	cout << "Do you want to play again (Y/N) ?" << endl;
	cin >> user_input;
	
 while (game_over) {

		if (user_input == 'y' || user_input == 'Y')
		{
			battle_ship();

		}

		else {
			cout << "Goodbye! ";
			break;
		}

	}
	

	return 0;
}

