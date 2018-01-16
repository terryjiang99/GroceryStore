#include <iostream>
#include <sstream>
#include <iomanip>

#include "Taxable.h"

Taxable::Taxable(){}

float Taxable::computeTax(float price){
	return price * HST;
}