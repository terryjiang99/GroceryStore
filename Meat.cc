#include <iostream>
#include <sstream>
#include <iomanip>

#include "Meat.h"

Meat::Meat(string n,string s,int u,float p,int d,int m,int y,int l)
: Product(n,s,u,p,d,m,y,l){
	expb = new Perishable();
	taxb = new NonTaxable();
	eDate = computeExpDate();
}

Meat::~Meat(){}