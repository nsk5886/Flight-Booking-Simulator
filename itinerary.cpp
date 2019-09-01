#include "pch.h"
#include "itinerary.h"
#include "Taxes.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


Itinerary::Itinerary() {}

/*-------------------------------------------------------------------------------------------------------------
Function printBoardingPass:
	- arguments: an airline class object, a flight class object, a seating class specifier, a ticket type specifier
	- accesses members of Airline and Flight to write information to an external fule
	- prints the Boarding Pass to a text file
-------------------------------------------------------------------------------------------------------------*/
void Itinerary::printBoardingPass(Airline &airlineDummy, Flight &flightDummy, int seatClass, int ticketType) {
	airline = airlineDummy;
	flight = flightDummy;
	string temp; 
	int strSize;
	
	if (ticketType == 1) {
		outFile.open("BoardingPass_Embarking.txt");
	}
	else if (ticketType == 2) {
		outFile.open("BoardingPass_Returning.txt");
	}
	
	outFile << "--------------------------------------------------" << endl;
	outFile << "|                 BOARDING PASS                   ";
	outFile << "|" << endl;
	outFile << "| Airline: ";
	outFile << airline.getAirline();
	temp = airline.getAirline();
	strSize = size(temp);
	for (int i = 0; i < 50 - (11 + strSize); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Passenger Name: ";
	outFile << firstName << " " << lastName;
	temp = firstName;
	strSize = size(temp);
	temp = lastName;
	strSize = strSize + 1 + size(temp);
	for (int i = 0; i < 50 - (18 + strSize); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Flight Number: ";
	generateFlightNumber();
	for (int i = 0; i < 50 - (23); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Departing From: " << setw(1) << flight.getDepCity();
	temp = flight.getDepCity();
	strSize = size(temp);
	for (int i = 0; i < 50 - (18 + strSize); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	if (airline.getPickTime() < 10) {
		outFile << "| Departure Time: " << setw(2) << "0" << airline.getPickTime() << ":" << "00";
		for (int i = 0; i < 50 - (24); i++) {
			outFile << " ";
		}
		outFile << "|" << endl;
	}
	else if (airline.getPickTime() >= 10) {
		outFile << "| Depature Time: " << setw(2) << airline.getPickTime() << ":" << "00";
		for (int i = 0; i < 50 - (23); i++) {
			outFile << " ";
		}
		outFile << "|" << endl;
	}
	outFile << "| Arriving At: " << setw(1) << flight.getArrCity();
	temp = flight.getArrCity();
	strSize = size(temp);
	for (int i = 0; i < 50 - (15 + strSize); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Arrival Time: ";
	arrivalTime(flight.getDepCity(), flight.getArrCity(), airline.getPickTime());
	for (int i = 0; i < 50 - (20); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Gate: ";
	generateGateNumber();
	for (int i = 0; i < 50 - (11); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Seat: ";
	generateSeatNumber(seatClass);
	for (int i = 0; i < 50 - (11); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "--------------------------------------------------" << endl;
	outFile.close();
} // end function printBoardingClass

/*-------------------------------------------------------------------------------------------------------------
Function printReceipt:
	- arguments: an airline class object, a flight class object, a seating class specifier, a ticket type specifier
	- accesses members of Airline and Flight to write information to an external fule
	- prints the Receipt to a text file
-------------------------------------------------------------------------------------------------------------*/
void Itinerary::printReceipt(Airline &airlineDummy, Flight &flightDummy, int seatClass, int ticketType) {
	airline = airlineDummy;
	flight = flightDummy;
	string temp; 
	int strSize;
	
	if (ticketType == 1) {
		outFile.open("Receipt_Embarking.txt");
	}
	else if (ticketType == 2) {
		outFile.open("Receipt_Returning.txt");
	}
	
	outFile << "-----------------------------------------" << endl;
	outFile << "|               Receipt                 |" << endl;
	outFile << "| " << airline.getAirline();
	temp = airline.getAirline();
	strSize = size(temp);
	for (int i = 0; i < 40 - (strSize + 2); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Customer Name: ";
	outFile << firstName << " " << lastName;
	temp = firstName;
	strSize = size(temp);
	temp = lastName;
	strSize = strSize + 1 + size(temp);
	for (int i = 0; i < 40 - (17 + strSize); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Flight Number: ";
	generateFlightNumber();
	for (int i = 0; i < 40 - (23); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Departing From: " << setw(1) << flight.getDepCity();
	temp = flight.getDepCity();
	strSize = size(temp);
	for (int i = 0; i < 40 - (18 + strSize); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Arriving At: " << setw(1) << flight.getArrCity();
	temp = flight.getArrCity();
	strSize = size(temp);
	for (int i = 0; i < 40 - (15 + strSize); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "| Departure Date: " << setw(1) << flight.getDepDate();
	temp = flight.getDepDate();
	strSize = size(temp);
	for (int i = 0; i < 40 - (15 + strSize); i++) {
		outFile << " ";
	}
	if (ticketType == 2) {
		outFile << "|" << endl;
		outFile << "| Arrival Date: " << setw(1) << flight.getArrDate();
		temp = flight.getArrDate();
		strSize = size(temp);
		for (int i = 0; i < 40 - (15 + strSize); i++) {
			outFile << " ";
		}
	}
	outFile << "|" << endl;
	if (seatClass == 1) {
		outFile << "| Seat Class: " << setw(1) << economyClass.getSeatClass();
		temp = economyClass.getSeatClass();
		}
	else if (seatClass == 2) {
		outFile << "| Seat Class: " << setw(1) << businessClass.getSeatClass();
		temp = businessClass.getSeatClass();
	}
	else if (seatClass == 3) {
		outFile << "| Seat Class: " << setw(1) << firstClass.getSeatClass();
		temp = firstClass.getSeatClass();
	}

	strSize = size(temp);
	for (int i = 0; i < 40 - (strSize + 14); i++) {
		outFile << " ";
	}

	outFile << "|" << endl;
	int tPrice = 0;
	if (seatClass == 1) {
		tPrice = economyClass.getSeatPrice();
	}
	else if (seatClass == 2) {
		tPrice = businessClass.getSeatPrice();
	}
	else if (seatClass == 3){
		tPrice = firstClass.getSeatPrice();
	}
	outFile << "|                                       |" << endl;
	outFile << "|                                       |" << endl;
	outFile << "| SUBTOTAL: $" << tPrice;
	if (seatClass == 1 || seatClass == 2) {
		for (int i = 0; i < 40 - (16); i++) {
			outFile << " ";
		}
	}
	else if (seatClass == 3) {
		for (int i = 0; i < 40 - (17); i++) {
			outFile << " ";
		}
	}
	outFile << "|" << endl;

	Taxes taxes(seatClass); // create the taxes object to calculate aned output total taxes

	outFile << "| TAX: $" << taxes; // envoke the overloaded ostream operator
	for (int i = 0; i < 40 - (14); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;

	double taxPrice = taxes.calculateTaxes(seatClass); // get the calculated tax based on seating class selection
	outFile << "| TOTAL: $" << (tPrice + taxPrice);
	for (int i = 0; i < 40 - (16); i++) {
		outFile << " ";
	}
	outFile << "|" << endl;
	outFile << "|           Have a nice day! :)         |" << endl;
	outFile << "-----------------------------------------" << endl;
	outFile.close();
} // end function printReciept

void Itinerary::arrivalTime(string departureAirport, string arrivalAirport, double time) {
	if (departureAirport == "ROC" && arrivalAirport == "JFK") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":0" << flightDuration[0];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":0" << flightDuration[0];
		}
	}
	else if (departureAirport == "JFK" && arrivalAirport == "ROC") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":0" << flightDuration[0];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":0" << flightDuration[0];
		}
	}
	else if (departureAirport == "ROC" && arrivalAirport == "CLT") {

		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[1];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[1];
		}
	}
	else if (departureAirport == "CLT" && arrivalAirport == "ROC") {

		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[1];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[1];
		}
	}
	else if (departureAirport == "ROC" && arrivalAirport == "ORD") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[2];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[2];
		}
	}
	else if (departureAirport == "ORD" && arrivalAirport == "ROC") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" <<  flightDurationPointer[2];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[2];
		}
	}
	else if (departureAirport == "ROC" && arrivalAirport == "BWI") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[3];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[3];
		}
	}
	else if (departureAirport == "BWI" && arrivalAirport == "ROC") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[3];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[3];
		}
	}
	else if (departureAirport == "JFK" && arrivalAirport == "CLT") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[4];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[4];
		}
	}
	else if (departureAirport == "CLT" && arrivalAirport == "JFK") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[4];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[4];
		}
	}
	else if (departureAirport == "JFK" && arrivalAirport == "ORD") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[5];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[5];
		}
	}
	else if (departureAirport == "ORD" && arrivalAirport == "JFK") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[5];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[5];
		}
	}
	else if (departureAirport == "JFK" && arrivalAirport == "BWI") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[6];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[6];
		}
	}
	else if (departureAirport == "BWI" && arrivalAirport == "JFK") {
	if (time < 9) {
		outFile << "0" << time + 1 << ":" << flightDurationPointer[6];
	}
	else if (time >= 9) {
		outFile << time + 1 << ":" << flightDurationPointer[6];
	}
	}
	else if (departureAirport == "CLT" && arrivalAirport == "ORD") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[7];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[7];
		}
	}
	else if (departureAirport == "ORD" && arrivalAirport == "CLT") {
	if (time < 9) {
		outFile << "0" << time + 1 << ":" << flightDurationPointer[7];
	}
	else if (time >= 9) {
		outFile << time + 1 << ":" << flightDurationPointer[7];
	}
	}
	else if (departureAirport == "CLT" && arrivalAirport == "BWI") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[8];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[8];
		}
	}
	else if (departureAirport == "BWI" && arrivalAirport == "CLT") {
	if (time < 9) {
		outFile << "0" << time + 1 << ":" << flightDurationPointer[8];
	}
	else if (time >= 9) {
		outFile << time + 1 << ":" << flightDurationPointer[8];
	}
	}
	else if (departureAirport == "ORD" && arrivalAirport == "BWI") {
		if (time < 9) {
			outFile << "0" << time + 1 << ":" << flightDurationPointer[9];
		}
		else if (time >= 9) {
			outFile << time + 1 << ":" << flightDurationPointer[9];
		}
	}
	else if (departureAirport == "BWI" && arrivalAirport == "ORD") {
	if (time < 10) {
		outFile << "0" << time + 1 << ":" << "0" << flightDurationPointer[9];
	}
	else if (time >= 10) {
		outFile << time + 1 << ":" << flightDurationPointer[9];
	}
	}
}

void Itinerary::generateFlightNumber() {
	srand(time(NULL));
	const char arrayLetters[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
								   'H', 'I', 'J', 'K', 'L', 'M', 'N',
								   'O', 'P', 'Q', 'R', 'S', 'T', 'U',
								   'V', 'W', 'X', 'Y', 'Z' };
	int RandIndex1 = rand() % 26;
	int RandIndex2 = rand() % 26;
	int RandIndex3 = rand() % 26;
	int x = rand() % 900 + 100;
	outFile << arrayLetters[RandIndex1] << arrayLetters[RandIndex2] << arrayLetters[RandIndex3] << x;
}

void Itinerary::generateGateNumber() {
	srand(time(NULL));
	const char arrayLetters[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
								   'H', 'I', 'J', 'K', 'L', 'M', 'N',
								   'O', 'P', 'Q', 'R', 'S', 'T', 'U',
								   'V', 'W', 'X', 'Y', 'Z' };
	int RandIndex = rand() % 26;
	int x = rand() % 99 + 1;
	outFile << arrayLetters[RandIndex] << x;
}

/*-------------------------------------------------------------------------------------------------------------
Function generateSeatNumber:
	- generates a random seat number depending on the user's class selection
	- function takes an argument of type int specifying the class selected
	- the seat classes are ordered sequentially from the front of the plane to the back
-------------------------------------------------------------------------------------------------------------*/
void Itinerary::generateSeatNumber(int classSelect) {
	srand(time(NULL));

	if (classSelect == 3) { // first class seats
	const char arrayLetters[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	int RandIndex = rand() % 6;
	int randSeat = rand() % 5 + 1;
	outFile << randSeat << arrayLetters[RandIndex];
	}
	else if (classSelect == 2) { // business class seats
		const char arrayLetters[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
		int RandIndex = rand() % 6;
		int randSeat = rand() % 15 + 6;
		outFile << randSeat << arrayLetters[RandIndex];
	}
	else if (classSelect == 1) { // economy class seats
		const char arrayLetters[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
		int RandIndex = rand() % 6;
		int randSeat = rand() % 30 + 21;
		outFile << randSeat << arrayLetters[RandIndex];
	}
}

void Itinerary::setFirstName(string dummy) {
	firstName = dummy;
}

string Itinerary::getFirstName() {
	return firstName;
}

void Itinerary::setLastName(string dummy) {
	lastName = dummy;
}

string Itinerary::getLastName() {
	return lastName;
}


	
