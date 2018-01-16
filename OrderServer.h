#ifndef ORDERSERVER_H
#define ORDERSERVER_H

#include "OrderArray.h"

class OrderServer{
	public: 
		// destructor calls cleanUp from orderArray to deallocate orders
		~OrderServer();
		// adds an order into the array, calls add(order*) from orderArray
		void update(Order*);
		// copy orderArray and return in outparam 
		void retrieve(OrderArray&);
	private:
		OrderArray orders;
};

#endif