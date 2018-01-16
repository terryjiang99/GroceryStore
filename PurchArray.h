#ifndef PURCHARRAY_H
#define PURCHARRAY_H

#include "defs.h"
#include "Purchase.h"

class PurchArray {
	public:
		// constructor initializes size and array of pointers to 0
		PurchArray();
		// destructor deletes purchase objects in arrays from customer and order
		~PurchArray();
		// check if ID is in array and increment units, or add new purchase if not
		void add(int);
		// return a purchase at an index in the array
		Purchase* get(int);
		// return size of array
		int getSize();
		// loop through array and convert each purchase to string
		void toString(string&);

	private:
		Purchase* elements[MAX_ARR];
		int size;
};

#endif
