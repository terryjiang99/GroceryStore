#include <string>
#include <cstdlib>
#include <iostream>
#include "OrderArray.h"
using namespace std; 

OrderArray::OrderArray() : size(0){
	for(int i = 0; i < MAX_ARR; i++){
		elements[i] = 0;
	}
}

void OrderArray::cleanUp(){
	for(int i = 0; i < MAX_ARR; i++){
		delete elements[i];
	}
}

int OrderArray::getSize(){
	return size;
}

Order* OrderArray::get(int index){
	if (index < 0 || index >= size)
		exit(1);
	return elements[index];
}

void OrderArray::add(Order* order){
	if(size >= MAX_ARR){
		return;
	}
	elements[size++] = order;
}

void OrderArray::toString(string& outStr){
	for(int i = 0; i < size; i++){
		elements[i]->toString(outStr);
	}
}