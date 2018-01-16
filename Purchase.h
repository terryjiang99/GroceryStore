#ifndef PURCHASE_H
#define PURCHASE_H

using namespace std;


class Purchase{
	public:
		// default constructor initializes data members to 0
		Purchase();
		// constructor initializes id and numUnits to 1
		Purchase(int);
		// return purchase id
		int getId();
		// return purchased units
		int getUnits();
		// increment numUnits by 1 (prod purch feature)
		void addUnits();
		// convert data members to string to outparam
		void toString(string&);
	
	protected: 
		int id;
		int numUnits;
};

#endif

