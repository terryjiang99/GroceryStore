#include <iostream>
#include <sstream>
#include <iomanip>

#include "CoffeeTea.h"

CoffeeTea::CoffeeTea(string n,string s,int u,float p,int d,int m,int y,int l)
: Product(n,s,u,p,d,m,y,l){
	expb = new NonPerishable();
	taxb = new Taxable();
	eDate = computeExpDate();
}
 
CoffeeTea::~CoffeeTea(){}