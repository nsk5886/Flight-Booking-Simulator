#include "pch.h"
#include "airline.h"

using namespace std;

Frontier::Frontier() {}

Spirit::Spirit() {}

Allegient::Allegient() {}

jetBlue::jetBlue() {}

American::American() {}

United::United() {}

Southwest::Southwest() {}

Delta::Delta() {}


void Airline::printAirlineNames() {
	for (int i = 0; i < 8; i++) {
		cout << i+1 << ". " << airlinePointer[i] << endl;;
	}
}

void Airline::getTimes() {
	for (int i = 0; i < 40; i++) {
		cout << timesPointer[i] << endl;
	}
}

void Frontier::getTimes() {
	for (int i = 0; i < 5; i++) {
		cout << timesPointer[i] << endl;
	}
}

void Spirit::getTimes() {
		for (int i = 5; i < 10; i++) {
			cout << timesPointer[i] << endl;
		}
	}

void Allegient::getTimes() {
	for (int i = 10; i < 15; i++) {
		cout << timesPointer[i] << endl;
	}
}

void jetBlue::getTimes() {
	for (int i = 15; i < 20; i++) {
		cout << timesPointer[i] << endl;
	}
}

void American::getTimes() {
	for (int i = 20; i < 25; i++) {
		cout << timesPointer[i] << endl;
	}
}

void United::getTimes() {
	for (int i = 25; i < 30; i++) {
		cout << timesPointer[i] << endl;
	}
}

void Southwest::getTimes() {
	for (int i = 30; i < 35; i++) {
		cout << timesPointer[i] << endl;
	}
}

void Delta::getTimes() {
	for (int i = 35; i < 40; i++) {
		cout << timesPointer[i] << endl;
	}
}

string Airline::getAirlineNames(int a) {
	string dummy;
	if (a == 1) {
		dummy= airlinePointer[0];
	}
	else if (a == 2) {
		dummy= airlinePointer[1];
	}
	else if (a == 3) {
		dummy= airlinePointer[2];
	}
	else if (a == 4) {
		dummy= airlinePointer[3];
	}
	else if (a == 5) {
		dummy= airlinePointer[4];
	}
	else if (a == 6) {
		dummy= airlinePointer[5];
	}
	else if (a == 7) {
		dummy= airlinePointer[6];
	}
	else if (a == 8) {
		dummy= airlinePointer[7];
	}
	return dummy;
}

void Airline::setAirline(string a) {
	airline = a;
}

string Airline::getAirline() {
	return airline;
}

void Airline::setPickTime(int dummy) {
	pickTime = dummy;
}

int Airline::getPickTime() {
	return pickTime;
}

