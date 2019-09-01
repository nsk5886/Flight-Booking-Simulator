#include "pch.h"
#include "Taxes.h"
#include "Seat.h"
#include "itinerary.h"

using namespace std;

Taxes::Taxes(int seatClassSelect) {
	taxTotal = calculateTaxes(seatClassSelect);
}

/*-------------------------------------------------------------------------------------------------------------
Overloaded Output Operator:
	- outputs the total taxes for a ticket by accessing member functions
-------------------------------------------------------------------------------------------------------------*/
ostream& operator<<(ostream &os, const Taxes &taxes) {
	os << taxes.taxTotal;
	return os;
}
/*-------------------------------------------------------------------------------------------------------------
Function calculateTaxes:
	- calculates the tax that should be applied to a ticket
	- the following values are legitimate fees and taxes that apply in the real world
	- total tax % per ticket approximately = 20%
-------------------------------------------------------------------------------------------------------------*/
double Taxes::calculateTaxes(int seatClassSelect) {
	// fees that apply to every ticket
	double flightSegmentTax = 4.20;
	double commercialJetFuelTax = 0.04;
	double EPATax = 0.01;
	double passengerFacilityTax = 4.50;
	double september11Tax = 5.60;
	double APHISPassengerTax = 3.96;
	double taxTotal = flightSegmentTax + commercialJetFuelTax + EPATax + passengerFacilityTax + september11Tax + APHISPassengerTax; // sum of all the fees

	// taxes that apply to the ticket price
	double passengerTicketTax = 0.075;
	double frequentFlyerTax = 0.075;
	double cargoWaybillTax = 0.0625;

	// calculation of total tax
	int tPrice;
	if (seatClassSelect == 1) {
		//tPrice = economyClass.getSeatPrice();
		tPrice = 150;
	}
	else if (seatClassSelect == 2) {
		//tPrice = businessClass.getSeatPrice();
		tPrice = 600;
	}
	else if (seatClassSelect == 3) {
		//tPrice = firstClass.getSeatPrice();
		tPrice = 1300;
	}

	taxTotal = taxTotal + (passengerTicketTax * tPrice);
	taxTotal = taxTotal + (frequentFlyerTax * tPrice);
	taxTotal = taxTotal + (cargoWaybillTax * tPrice);
	return taxTotal;
} // end calculateTaxes
