#pragma once
#include <iostream>
#include <string>

using namespace std;

class Flight {
private:
	string departureCity;
	string arrivalCity;
	string departureDate;
	string arrivalDate;
	
public:
	Flight();
	void setDepCity(string);
	string getDepCity();
	void setArrCity(string);
	string getArrCity();
	void setDepDate(string);
	string getDepDate();
	void setArrDate(string);
	string getArrDate();
};

