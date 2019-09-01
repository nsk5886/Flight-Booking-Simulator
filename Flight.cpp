#include "pch.h"
#include "Flight.h"
#include <fstream>
#include <stdlib.h>
#include <ctime>

Flight::Flight() {}


void Flight::setDepCity(string a) {
	departureCity = a;
}


string Flight::getDepCity() {
	return departureCity;
}


void Flight::setArrCity(string a) {
	arrivalCity = a;
}


string Flight::getArrCity() {
	return arrivalCity;
}


void Flight::setDepDate(string a) {
	departureDate = a;
}


string Flight::getDepDate() {
	return departureDate;
}


void Flight::setArrDate(string a) {
	arrivalDate = a;
}


string Flight::getArrDate() {
	return arrivalDate;
}


