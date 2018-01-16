#include <iostream>
#include <sstream>
#include <iomanip>

#include "Bakery.h"

Bakery::Bakery(string n,string s,int u,float p,int d,int m,int y,int l)
: Product(n,s,u,p,d,m,y,l){
	expb = new Perishable();
	taxb = new Taxable();
	eDate = computeExpDate();
}

Bakery::~Bakery(){}