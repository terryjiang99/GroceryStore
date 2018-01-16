#ifndef ORDER_H
#define ORDER_H

#include "Customer.h"
#include "PurchArray.h"
using namespace std;

class Order{
	public:
		// default constructor initializes id and cost to 0
		Order();
		// constructor initializes order object and set customer pointer
		Order(Customer*);
		// calls add function from PurchArray to add a new purchase with prodId
		void addPurch(int);
		// setter for setting total cost of order
		void setCost(float);
		// return order id
		int getId();
		// return order cost
		float getCost();
		// convert each data member to string to outparameter
		void toString(string&);
		// return order's purchArray
		PurchArray& getPurch();
	protected: 
		static int nextOrderId;
		int id;
		float cost;
		Customer* cust;
		PurchArray oPurch;
};

#endif

