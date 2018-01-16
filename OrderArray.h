#ifndef ORDERARRAY_H
#define ORDERARRAY_H

#include "defs.h"
#include "Order.h"

class OrderArray {
	public:
		// constructor initializes size and array of pointers to 0
		OrderArray();
		// cleanUp deletes order objects in the array, called from OrderServer
		void cleanUp();
		// add new order into array
		void add(Order*);
		// return size of array
		int getSize();
		// return an order at an index in the array
        Order* get(int);
		// loop through array convert each order to string
		void toString(string&);
	private:
		Order* elements[MAX_ARR];
		int size;
};

#endif
