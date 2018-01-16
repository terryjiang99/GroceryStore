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

#include <string>
#include <cstdlib>

using namespace std;

#include "ProdList.h"

ProdList::ProdList() : head(0){
}

ProdList::~ProdList(){
	Node* currNode = head;
	Node* nextNode;

	while (currNode != NULL) {
		nextNode = currNode->next;
		delete currNode->data;
		delete currNode;
		currNode = nextNode;
	}
}

void ProdList::add(Product* prod){
	Node* newProdNode;
	Node* currNode = head;
	Node* prevNode = NULL;

	newProdNode = new Node;
	newProdNode->data = prod;
	newProdNode->next = NULL;
	newProdNode->prev = NULL;

	while(currNode != NULL){
		if(currNode->data->geteDate() > newProdNode->data->geteDate()){
			break;
		}
		prevNode = currNode;
		currNode = currNode->next;
	}
	if(prevNode == NULL){ // add to front
		head = newProdNode;
	}
	else{
		prevNode->next = newProdNode;
	}
	newProdNode->prev = prevNode;
	newProdNode->next = currNode;

}

void ProdList::remove(Product* prod){
	Node* currNode = head;
	Node* nextNode = NULL;
	Node* prevNode = NULL;

	while(currNode != NULL){
		if(prod->getId() == currNode->data->getId()){
			break;
		}
		prevNode = currNode;
		currNode = currNode->next;
		nextNode = currNode->next;
	}
	if(prevNode == NULL){
		head = currNode->next;
	}
	else if(currNode->next == NULL){
		prevNode->next = NULL;
	}
	else{
		prevNode->next = currNode->next;
		currNode->next->prev = prevNode;
	}
	delete currNode->data;
	delete currNode;
}

void ProdList::reorg(){
	Node* currNode = head;
	Node* nextNode = currNode->next;
	int index = 0;
	while(currNode != NULL){
		currNode = currNode ->next;
		index++;
	}
	currNode = head;
	for(int i = 0; i < index; i++){
		while(currNode->next != NULL){
			if(currNode->data->geteDate() > nextNode->data->geteDate()){
				Product* tmp = currNode->data;
				currNode->data = nextNode->data;
				nextNode->data = tmp;
			}
			currNode = nextNode;
			nextNode = currNode->next;
			if(nextNode == NULL)
				break;
		}
		currNode = head;
		nextNode = currNode->next;
	}

}

Product* ProdList::findProduct(int id){
	Node* currNode = head;
	Node* prevNode = NULL;

	while(currNode != NULL){
		if(currNode->data->getId() == id){
			return currNode->data;
		}
		prevNode = currNode;
		currNode = currNode->next;
	}
	return NULL;
}

void ProdList::toString(string& outStr){
	for(Node* currNode = head; 
		currNode != NULL; 
		currNode = currNode->next){

		currNode->data->toString(outStr);
	}
}

