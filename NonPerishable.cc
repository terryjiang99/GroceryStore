#include <iostream>
#include <sstream>
#include <iomanip>

#include "NonPerishable.h"

NonPerishable::NonPerishable(){}

Date NonPerishable::computeExpDate(Date& mDate, int ls){
	return mDate + DLS;
}
