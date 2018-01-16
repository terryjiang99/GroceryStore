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
#include "Store.h"

Store::~Store(){
	list<Customer*>::iterator itr;
	for(itr = customers.begin(); itr != customers.end(); ++itr){
		delete *itr;
	}
}

ProdList* Store::getStock()     { return &stock; }

list<Customer*>& Store::getCustomers() { return customers; }

void Store::addProd(Product* prod){
	stock.add(prod);
}

void Store::addCust(Customer* cust){
	customers.push_back(cust);
}

Customer* Store::findCust(int custId){
	list<Customer*>::iterator itr;
	for(itr = customers.begin(); itr != customers.end(); ++itr){
		if(custId == (*(itr))->getId()){
			return *itr;
		}
	}
	return NULL;
}

Product* Store::findProd(int prodId){
	return stock.findProduct(prodId);
}

void Store::removeProd(Product* prod){
	stock.remove(prod);
}

void Store::reorg(){
	stock.reorg();
}