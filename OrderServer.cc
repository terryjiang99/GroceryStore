#include <iostream>
#include <sstream>
#include <iomanip>
#include "OrderServer.h"
using namespace std;

OrderServer::~OrderServer(){
	orders.cleanUp();
}

void OrderServer::update(Order* order){
	orders.add(order);
}

void OrderServer::retrieve(OrderArray& arr){
	//arr = orders;
	for(int i = 0; i < orders.getSize(); i++){
		arr.add(orders.get(i));
	}
}