#include <iostream>
#include <sstream>
#include <iomanip>

#include "MiscGoods.h"

MiscGoods::MiscGoods(string n,string s,int u,float p,int d,int m,int y,int l)
: Product(n,s,u,p,d,m,y,l){
	expb = new NonPerishable();
	taxb = new NonTaxable();
	eDate = computeExpDate();
}

MiscGoods::~MiscGoods(){}
/*float MiscGoods::computeTax(){}
void MiscGoods::computeExpDate(){}*/