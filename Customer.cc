/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include <sstream>
#include <iomanip>

#include "Customer.h"

int Customer::nextCustId = 2001;

Customer::Customer(string n){ 
	id     = nextCustId++;
	name   = n;
	points = 0;
}

int    Customer::getId()     { return id;     }
string Customer::getName()   { return name;   }
int    Customer::getPoints() { return points; }

PurchArray& Customer::getPurchases(){
	return purchases;
}

void Customer::addPurch(int id){
	purchases.add(id);
}

void Customer::addPoints(int& lpoints){
	points += lpoints;
}

void Customer::toString(string& outStr){
	ostringstream str;
	str << id << setw(12)
	<< name << setw(8)
	<< points << endl;
	string purch;
	purchases.toString(purch);

	outStr += string(str.str());
	outStr += purch;
}