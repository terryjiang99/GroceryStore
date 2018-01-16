#include <iostream>
#include <sstream>
#include <iomanip>
#include "Purchase.h"

Purchase::Purchase(){
	id = 0;
	numUnits = 0;
}

Purchase::Purchase(int i){
	id = i;
	numUnits = 1;
}

int Purchase::getId(){
	return id;
}

int Purchase::getUnits(){
	return numUnits;
}

void Purchase::addUnits(){
	numUnits += 1;
}

void Purchase::toString(string& outStr){
	ostringstream str;
	str << "\r\n" << setw(33) << id
	<< setw(7) << numUnits;
	outStr += string(str.str());
}