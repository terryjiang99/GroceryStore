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

#include "Product.h"

int Product::nextProdId = 5001;

Product::Product(string n,string s,int u,float p,int d,int m,int y,int l){ 
	id    = nextProdId++;
	name  = n;
	size  = s;
	units = (u >= 0) ? u : 0;
	price = (p >= 0) ? p : 0;
	lifespan = l;
	mDate.setDate(d,m,y);
}

Product::~Product(){
	delete taxb;
	delete expb;
}

int    Product::getId()    { return id;    }
string Product::getName()  { return name;  }
string Product::getSize()  { return size;  }
int    Product::getUnits() { return units; }
float  Product::getPrice() { return price; }
Date&   Product::geteDate() { return eDate; }

float Product::computeTax(){
	return taxb->computeTax(price);
}

Date Product::computeExpDate(){
	return expb->computeExpDate(mDate,lifespan);
}

void Product::decreaseUnits(){
	units -= 1;
}

void Product::increaseUnits(int newUnits){
	units += newUnits;
}

void Product::toString(string& outStr){
	ostringstream str;
	string d;
	eDate.toString(d);
	str << id
	<< setw(40) << name
	<< setw(14) << size
	<< setw(6) << units
	<< setw(5) << "$"<< price << "   " << d;
	outStr += string(str.str()) + "\r\n";
}