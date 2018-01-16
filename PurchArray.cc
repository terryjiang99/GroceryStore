#include <string>
#include <cstdlib>
#include <iostream>
#include "PurchArray.h"
using namespace std; 

PurchArray::PurchArray() : size(0){
	for(int i = 0; i < MAX_ARR; i++){
		elements[i] = 0;
	}
}

PurchArray::~PurchArray(){
	for(int i = 0; i < MAX_ARR; i++){
		delete elements[i];
	}
}

int PurchArray::getSize(){
	return size;
}

Purchase* PurchArray::get(int index){
	if(index < 0 || index >=size){
		exit(1);
	}
	return elements[index];
}

void PurchArray::add(int prodId){
	bool exists = false;
	if(size >= MAX_ARR){
		return;
	}
	for(int i = 0; i < size; i++){
		if(prodId == elements[i]->getId()){
			elements[i]->addUnits();
			exists = true;
		}
	}
	if(!exists){
		Purchase* purch = new Purchase(prodId);
		elements[size++] = purch;
	}
}

void PurchArray::toString(string& outStr){
	for(int i = 0; i < size; i++){
		elements[i]->toString(outStr);
	}
}
