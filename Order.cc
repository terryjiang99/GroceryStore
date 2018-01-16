#include <iostream>
#include <sstream>
#include <iomanip>
#include "Order.h"

int Order::nextOrderId = 8001;

Order::Order(){
	id = 0;
	cost = 0;
}

Order::Order(Customer* cust){
	id = nextOrderId++;
	cost = 0;
	this->cust = cust;
}

void Order::addPurch(int id){
	oPurch.add(id);
}

void Order::setCost(float amount){
	cost = amount;
}

int Order::getId(){
	return id;
}

float Order::getCost(){
	return cost;
}

PurchArray& Order::getPurch(){
	return oPurch;
}

void Order::toString(string& outStr){
	ostringstream str;
	string purch;
	oPurch.toString(purch);
	str << id << setw(4)
	<< "$" << cost << setw(10)
	<< cust->getName();
	outStr += string(str.str());
	outStr += purch;
}