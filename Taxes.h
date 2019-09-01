#pragma once
#include <string>
#include <iostream>

/*--------------------------------------------------------------------------------
Class Tax:
  - base class with several children
  - each child has its own tax percentage or fees
  - the += operator is overloaded to provided a tax total
--------------------------------------------------------------------------------*/
using namespace std;

class Taxes {
public:
	double taxTotal;
	Taxes(int);
	double calculateTaxes(int);
	friend ostream& operator<<(ostream &, const Taxes &);
};