#pragma once
#include <string>
#include <iostream>


using namespace std;

class Airline {
public:
	int pickTime;
	string airline;
	string airlineNames[8] = { "Frontier", "Spirit", "Allegient", "JetBlue", "American", "United", "Southwest", "Delta"};
	double times[40] = {1, 9, 17, 8, 15,
						2, 10, 18, 7, 13,
						3, 11, 19, 6, 11,
						4, 12, 20, 5, 9,
						5, 13, 21, 4, 10,
						6, 14, 22, 3, 12,
						7, 15, 23, 2, 14,
						8, 16, 24, 1, 18};
	double *timesPointer = times;
	string *airlinePointer = airlineNames;
	virtual void getTimes(); 
	void printAirlineNames();
	string getAirlineNames(int a);
	void setAirline(string);
	string getAirline();
	void setPickTime(int);
	int getPickTime();

};

class Allegient : public Airline {
public:
	Allegient();
	virtual void getTimes();
};

class American : public Airline {
public:
	American(); 
	virtual void getTimes();
};

class Delta : public Airline {
public:
	Delta();
	virtual void getTimes();
};

class Frontier : public Airline {
public:
	Frontier(); 
	virtual void getTimes();
};

class jetBlue : public Airline {
public:
	jetBlue();
	virtual void getTimes();
};

class Southwest : public Airline {
public:
	Southwest(); 
	virtual void getTimes();
};

class Spirit : public Airline {
public:
	Spirit(); 
	virtual void getTimes();
};

class United : public Airline {
public:
	United();
	virtual void getTimes();
};

