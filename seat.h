#pragma once
#include <iostream>
#include <string>

using namespace std;

class Seat {
public:
	virtual double getSeatPrice() = 0;
	virtual void setSeatPrice(double) = 0;
	virtual string getSeatClass() = 0;
};


class firstSeat: public Seat {
private:
	double seatPrice = 1300;
	string classType = "First";
public:
	firstSeat();
	double getSeatPrice();
	void setSeatPrice(double);
	string getSeatClass();
};

class businessSeat: public Seat {
private:
	double seatPrice = 600;
	string classType = "Business";
public:
	businessSeat();
	double getSeatPrice();
	void setSeatPrice(double);
	string getSeatClass();
};


class economySeat: public Seat {
private:
	double seatPrice = 150;
	string classType = "Economy";
public:
	economySeat();
	double getSeatPrice();
	void setSeatPrice(double);
	string getSeatClass();
};

