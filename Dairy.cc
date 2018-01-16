#include <iostream>
#include <sstream>
#include <iomanip>

#include "Dairy.h"

Dairy::Dairy(string n,string s,int u,float p,int d,int m,int y,int l)
:Product(n,s,u,p,d,m,y,l){
	expb = new Perishable();
	taxb = new NonTaxable();
	eDate = computeExpDate();
}

Dairy::~Dairy(){}