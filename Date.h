#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date{
	public:
		// constructor initialize data members; default: 0
		Date(int=0, int=0, int=0);
		// set date with int month year
		void setDate(int, int, int);
		// overload += operator, convert to date to days and add days
		Date& operator+=(int);
		// overload + operator, call += operator
		Date operator+(int);
		// overload > operator, compare date by convert to days
		bool operator>(Date&);
		// convert each data member to string in outparam
		void toString(string&);
		// overloaded setDate function, takes numDays
		void setDate(int);

	private:
		int day;
		int month;
		int year;
		// convert Date to total number days
		int convertToDays();

};

#endif
