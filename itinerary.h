#pragma once
#include "Flight.h"
#include "airline.h"
#include "seat.h"
#include <fstream>


class Itinerary {
private:
	ofstream outFile;
	Airline airline;
	Flight flight;
	string firstName;
	string lastName;
	double flightDuration[10] = { 1, 45, 39, 3, 41, 49, 50, 50, 15, 35 };
	double *flightDurationPointer = flightDuration;
	
public:
	firstSeat firstClass;
	businessSeat businessClass;
	economySeat economyClass;
	Itinerary();
	void setFirstName(string);
	string getFirstName();
	void setLastName(string);
	string getLastName();
	void arrivalTime(string, string, double);
	void generateFlightNumber();
	void generateGateNumber();
	void generateSeatNumber(int);
	void printBoardingPass(Airline &, Flight &, int, int);
	void printReceipt(Airline &, Flight &, int, int);
};

