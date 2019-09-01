#include "pch.h"
#include "airline.h"
#include "Flight.h"
#include "seat.h"
#include "itinerary.h"
#include "Taxes.h"
#include <string>
#include <vector>
#include <iostream>


using namespace std;

void sortArray(string names[], int size);
int binarySearch(string names[], int size, string value);
void searchTimes(double *Temp, double);


int main()
{
	cout << "Welcome to the Airplane Ticket Booking System!" << endl;
	cout << "Please select an airport you will be flying out of." << endl;
	string airportNames[5] = { "Rochester International Airport (ROC)", "John F. Kennedy International Airport (JFK)",
							"Charlotte Douglas International Airport (CLT)", "Chicago O'Hare International Airport (ORD)",
							 "Baltimore International Aiport (BWI)" };

	string *airportNamesPointer = airportNames;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ". " << airportNamesPointer[i] << endl;
	}

	cout << "Option: ";
	int pickDepartureAirport;
	cin >> pickDepartureAirport;
	string departureAirport;
	Flight flight;

	switch (pickDepartureAirport) {
	case 1: departureAirport = "ROC";
		flight.setDepCity(departureAirport);
		break;
	case 2: departureAirport = "JFK";
		flight.setDepCity(departureAirport);
		break;
	case 3: departureAirport = "CLT";
		flight.setDepCity(departureAirport);
		break;
	case 4: departureAirport = "ORD";
		flight.setDepCity(departureAirport);
		break;
	case 5: departureAirport = "BWI";
		flight.setDepCity(departureAirport);
		break;
	}

	cout << endl << "Please select an airport you will be flying to." << endl;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ". " << airportNamesPointer[i] << endl;
	}

	cout << "Option: ";
	int pickArrivalAirport;
	cin >> pickArrivalAirport;
	string arrivalAirport;

	switch (pickArrivalAirport) {
	case 1: arrivalAirport = "ROC";
		flight.setArrCity(arrivalAirport);
		break;
	case 2: arrivalAirport = "JFK";
		flight.setArrCity(arrivalAirport);
		break;
	case 3: arrivalAirport = "CLT";
		flight.setArrCity(arrivalAirport);
		break;
	case 4: arrivalAirport = "ORD";
		flight.setArrCity(arrivalAirport);
		break;
	case 5: arrivalAirport = "BWI";
		flight.setArrCity(arrivalAirport);
		break;
	}


	cout << endl << "Would you like to purchase a one way ticket or a round trip ticket?" << endl;

	string ticketNames[2] = { "One Way", "Round Trip" };
	string *ticketNamesPointer = ticketNames;

	for (int i = 0; i < 2; i++) {
		cout << i + 1 << ". " << ticketNamesPointer[i] << endl;
	}

	cout << "Option: ";
	int ticketType;
	cin >> ticketType;


	cout << endl << "Please enter date of departure (month/day/year)" << endl;

	string departureDate;
	cin >> departureDate;

	flight.setDepDate(departureDate);

	cout << endl;

	int repeat = 1; // termination condition of while
	int loopNum = 1; // variable to index the number of loops through the while below (1 for one way, 2 for round trip)

	if (ticketType == 2) {
		cout << endl << "Please enter date of return (month/day/year)" << endl;

		string arrivalDate;
		cin >> arrivalDate;
		flight.setArrDate(arrivalDate);

		cout << endl;
	}

	cout << "To continue with the booking process: " << endl;
	cout << "Please enter your first name: ";
	string firstName;
	cin >> firstName;
	cout << "Please enter your last name: ";
	string lastName;
	cin >> lastName;
	cout << endl;

	while (repeat == 1) {
		if (loopNum == 1) {
			cout << "------------------------------------------------------------------------------" << endl;
			cout << "FOR EMBARKING TRIP:" << endl;
		}
		else if (loopNum == 2) {
			flight.setDepCity(arrivalAirport); // swap the airports for the return trip
			flight.setArrCity(departureAirport);
			cout << "------------------------------------------------------------------------------" << endl;
			cout << endl << "FOR RETURNING TRIP:" << endl;
		}
		cout << endl;
		cout << "How would you like to narrow your search?" << endl;
		cout << "<1>" << "Search through airline names." << endl;
		cout << "<2>" << "Browse list of available airlines." << endl;
		cout << "<3>" << "Search departure times." << endl;
		cout << "Option: ";
		int chooseOption;
		cin >> chooseOption;

		if (chooseOption < 1 || chooseOption > 3) {
			cout << "Warning, please enter an option 1-3: ";
			cin >> chooseOption;
		}

		Airline airline;


	Option1:
		if (chooseOption == 1) {
			cout << endl << "Enter airline name: ";

			airline.airlineNames;

		SearchAirline:
			string searchAirline;
			cin >> searchAirline;
			cout << endl;

			sortArray(airline.airlineNames, 8);
			int searchAirlineResult = binarySearch(airline.airlineNames, 8, searchAirline);

			if (searchAirlineResult == -1) {
				cout << "The airline you searched was not found. Please try again." << endl;
				goto SearchAirline;
			}

			else {
				if (searchAirline == "Frontier") {
					Frontier frontier;
					cout << "Times this airline flies out on " << departureDate << ": " << endl;
					frontier.getTimes();
					string airlineChoice = searchAirline;
					airline.setAirline(airlineChoice);
				}

				else if (searchAirline == "Spirit") {
					Spirit spirit;
					cout << "Times this airline flies out on " << departureDate << ": " << endl;
					spirit.getTimes();
					string airlineChoice = searchAirline;
					airline.setAirline(airlineChoice);
				}

				else if (searchAirline == "Allegient") {
					Allegient allegient;
					cout << "Times this airline flies out on " << departureDate << ": " << endl;
					allegient.getTimes();
					string airlineChoice = searchAirline;
					airline.setAirline(airlineChoice);
				}

				else if (searchAirline == "JetBlue") {
					jetBlue jetBlue;
					cout << "Times this airline flies out on " << departureDate << ": " << endl;
					jetBlue.getTimes();
					string airlineChoice = searchAirline;
					airline.setAirline(airlineChoice);
				}

				else if (searchAirline == "American") {
					American American;
					cout << "Times this airline flies out on " << departureDate << ": " << endl;
					American.getTimes();
					string airlineChoice = searchAirline;
					airline.setAirline(airlineChoice);
				}

				else if (searchAirline == "United") {
					United United;
					cout << "Times this airline flies out on " << departureDate << ": " << endl;
					United.getTimes();
					string airlineChoice = searchAirline;
					airline.setAirline(airlineChoice);
				}

				else if (searchAirline == "Southwest") {
					Southwest Southwest;
					cout << "Times this airline flies out on " << departureDate << ": " << endl;
					Southwest.getTimes();
					string airlineChoice = searchAirline;
					airline.setAirline(airlineChoice);
				}

				else if (searchAirline == "Delta") {
					Delta Delta;
					cout << "Times this airline flies out on " << departureDate << ": " << endl;
					Delta.getTimes();
					string airlineChoice = searchAirline;
					airline.setAirline(airlineChoice);
				}
			}
			cout << "Do you want to select this airline?" << " <Y/N>: ";
			char pick;
			cin >> pick;
			if (pick == 'Y') {
				cout << "Please select any of the previous times: ";
				int chooseTime;
				cin >> chooseTime;
				airline.setPickTime(chooseTime);
			}
			if (pick == 'N') {
				goto Option1;
			}
		}

	Option2:
		if (chooseOption == 2) {
			cout << endl << "Airlines available: " << endl;
			airline.printAirlineNames();
			cout << "Please select the desired airline: ";
			int chooseAirline;
			cin >> chooseAirline;

			cout << endl;

			if (chooseAirline == 1) {
				Frontier frontier;
				cout << "Times this airline flies out on " << departureDate << ": " << endl;
				frontier.getTimes();
				string airlineChoice = "Frontier";
				airline.setAirline(airlineChoice);
			}

			else if (chooseAirline == 2) {
				Spirit spirit;
				cout << "Times this airline flies out on " << departureDate << ": " << endl;
				spirit.getTimes();
				string airlineChoice = "Spirit";
				airline.setAirline(airlineChoice);
			}

			else if (chooseAirline == 3) {
				Allegient allegient;
				cout << "Times this airline flies out on " << departureDate << ": " << endl;
				allegient.getTimes();
				string airlineChoice = "Allegient";
				airline.setAirline(airlineChoice);
			}

			else if (chooseAirline == 4) {
				jetBlue jetBlue;
				cout << "Times this airline flies out on " << departureDate << ": " << endl;
				jetBlue.getTimes();
				string airlineChoice = "JetBlue";
				airline.setAirline(airlineChoice);
			}

			else if (chooseAirline == 5) {
				American American;
				cout << "Times this airline flies out on " << departureDate << ": " << endl;
				American.getTimes();
				string airlineChoice = "American";
				airline.setAirline(airlineChoice);
			}

			else if (chooseAirline == 6) {
				United United;
				cout << "Times this airline flies out on " << departureDate << ": " << endl;
				United.getTimes();
				string airlineChoice = "United";
				airline.setAirline(airlineChoice);
			}

			else if (chooseAirline == 7) {
				Southwest Southwest;
				cout << "Times this airline flies out on " << departureDate << ": " << endl;
				Southwest.getTimes();
				string airlineChoice = "Southwest";
				airline.setAirline(airlineChoice);
			}

			else if (chooseAirline == 8) {
				Delta Delta;
				cout << "Times this airline flies out on " << departureDate << ": " << endl;
				Delta.getTimes();
				string airlineChoice = "Delta";
				airline.setAirline(airlineChoice);
			}
			cout << "Do you want to select this airline?" << " <Y/N>: ";
			char pick;
			cin >> pick;
			if (pick == 'Y') {
				cout << "Please select any of the previous times: ";
				int chooseTime;
				cin >> chooseTime;
				airline.setPickTime(chooseTime);
			}
			if (pick == 'N') {
				goto Option2;
			}
		}


		if (chooseOption == 3) {
			double searchedTime;
			double *Temp = airline.times;
			string airlineSelect;

			cout << endl << "Search times (1-24): ";
			cin >> searchedTime;
			if (searchedTime < 1 || searchedTime > 24) {
				cout << "Warning, please enter an hour between 1-24: ";
				cin >> searchedTime;
			}

			cout << "Search Results for airlines flying on: " << departureDate << " at " << searchedTime << ":" << endl;
			searchTimes(Temp, searchedTime);


			cout << endl << "Please select an airline to add that flight to your purchase: ";
			cin >> airlineSelect;
			airline.setAirline(airlineSelect);
			airline.setPickTime(searchedTime);
		}


		int seatClassSelect;
		firstSeat firstSeat;
		businessSeat businessSeat;
		economySeat economySeat;

		cout << endl << "Seating Class Selection:" << endl;
		cout << "1. Economy: $" << economySeat.getSeatPrice() << endl;
		cout << "2. Business: $" << businessSeat.getSeatPrice() << endl;
		cout << "3. First: $" << firstSeat.getSeatPrice() << endl << endl;
		cout << "What seating class would you like to fly: ";
		cin >> seatClassSelect;
	
		if (loopNum == 1) {
			Itinerary itinerary1;

			itinerary1.setFirstName(firstName);
			itinerary1.setLastName(lastName);

			itinerary1.printBoardingPass(airline, flight, seatClassSelect, loopNum);
			itinerary1.printReceipt(airline, flight, seatClassSelect, loopNum);


			if (ticketType == 1) {
				repeat = 0; // exit the while loop if this is a one way trip
			}
		}
		else if (loopNum == 2) {
			Itinerary itinerary2;

			itinerary2.setFirstName(firstName);
			itinerary2.setLastName(lastName);

			itinerary2.printBoardingPass(airline, flight, seatClassSelect, loopNum);
			itinerary2.printReceipt(airline, flight, seatClassSelect, loopNum);
			repeat = 0; // end the loop after round trip boarding pass has been printed
		}
		loopNum++; // restart the while loop if this is a round trip
	} // end while

	cout << endl << endl << "--------------------------------------------------------------------------------------" << endl;
	cout << "	Thank you for using the Airline Ticket Booking System" << endl;
	cout << "	Your Boarding Pass(es) and Receipt(s) can be found in the project folder of your IDE" << endl;
	cout << "	Press any key to end your transaction" << endl;
	cout <<  "--------------------------------------------------------------------------------------" << endl;
	int nothing;
	cin >> nothing; // just wait until user cancels

	return 0;

	} 




/*-------------------------------------------------------------------------------------------------
 Function definitions:
 -------------------------------------------------------------------------------------------------*/
	void sortArray(string names[], int size)
	{
		int startScan, minIndex;
		string minValue;

		for (startScan = 0; startScan < (size - 1); startScan++)
		{
			minIndex = startScan;
			minValue = names[startScan];
			for (int index = startScan + 1; index < size; index++)
			{
				if (names[index] < minValue)
				{
					minValue = names[index];
					minIndex = index;
				}
			}
			names[minIndex] = names[startScan];
			names[startScan] = minValue;
		}
	}



	int binarySearch(string names[], int size, string value)
	{
		int first = 0,             // First array element
			last = size - 1,       // Last array element
			middle,                // Mid point of search
			position = -1;         // Position of search value
		bool found = false;        // Flag

		while (!found && first <= last)
		{
			middle = (first + last) / 2;     // Calculate mid point
			if (names[middle] == value)      // If value is found at mid
			{
				found = true;
				position = middle;
			}
			else if (names[middle] > value)  // If value is in lower half
				last = middle - 1;
			else
				first = middle + 1;           // If value is in upper half
		}
		return position;
	}




void searchTimes(double *Temp, double t) {
    for (int j = 0; j < 5; j++) { 
        if (t == Temp[j]) { 
			cout << "Frontier"<<endl;
        }
    }

	for (int j = 5; j < 10; j++) {
		if (t == Temp[j]) {
			cout << "Spirit" << endl;
		}
	}

	for (int j = 10; j < 15; j++) {
		if (t == Temp[j]) {
			cout << "Allegient" << endl;
		}
	}
   
	for (int j = 15; j < 20; j++) {
		if (t == Temp[j]) {
			cout << "JetBlue" << endl;
		}
	}

	for (int j = 20; j < 25; j++) {
		if (t == Temp[j]) {
			cout << "American" << endl;
		}
	}

	for (int j = 25; j < 30; j++) {
		if (t == Temp[j]) {
			cout << "United" << endl;
		}
	}

	for (int j = 30; j < 35; j++) {
		if (t == Temp[j]) {
			cout << "Southwest" << endl;
		}
	}

	for (int j = 35; j < 40; j++) {
		if (t == Temp[j]) {
			cout << "Delta" << endl;
		}
	}

} 
