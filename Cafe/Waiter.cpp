///////////////////////////////////////////////////////////
//  Waiter.cpp
//  Implementation of the Class Waiter
//  Created on:      16-Nov-2013 8:48:19 PM
///////////////////////////////////////////////////////////

#include "Waiter.h"


Waiter::~Waiter(){

}

Waiter::Waiter(){

}


void Waiter::addNewClient(Client* client){
	if(!client)
		return;
	clients_.push_back(client);
}


void Waiter::deleteClient(Client* client){
	if(!client)
		return;
	std::remove(clients_.begin(),clients_.end(),client);
}


void Waiter::setOrder(Order* order){
	if(!order)
		return;
	orders_.push(order);
}


Order* Waiter::giveOrderToChef(){
	auto order = orders_.front();
	orders_.pop();
	return order;
}


Order* Waiter::giveOrderToClient(){
	return nullptr;
}