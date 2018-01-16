#include <iostream>
#include <sstream>
#include <iomanip>

#include "Perishable.h"

Perishable::Perishable(){}

Date Perishable::computeExpDate(Date& mDate, int lifespan){
	return mDate + lifespan;
}