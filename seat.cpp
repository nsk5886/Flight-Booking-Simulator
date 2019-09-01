#include "pch.h"
#include "seat.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>


firstSeat::firstSeat() {}

double firstSeat::getSeatPrice() {
	return seatPrice;
}

void firstSeat::setSeatPrice(double a) {
	seatPrice = a;
}

businessSeat::businessSeat() {}

double businessSeat::getSeatPrice() {
	return seatPrice;
}

void businessSeat::setSeatPrice(double a) {
	seatPrice = a;
}

economySeat::economySeat() {}

double economySeat::getSeatPrice() {
	return seatPrice;
}

void economySeat::setSeatPrice(double a) {
	seatPrice = a;
}

string firstSeat::getSeatClass() {
	return classType;
}

string businessSeat::getSeatClass() {
	return classType;
}

string economySeat::getSeatClass() {
	return classType;
}

