///////////////////////////////////////////////////////////
//  Waiter.cpp
//  Implementation of the Class Waiter
//  Created on:      16-Nov-2013 8:48:19 PM
///////////////////////////////////////////////////////////

#include "Waiter.h"
#include "WaiterCommands.h"

Waiter::~Waiter(){
	for(size_t i = 0; i< orders_->size();i++)
	{
		delete orders_->at(i);
	}
	orders_->clear();
	delete orders_;
}

Waiter::Waiter(){
	orders_ = new std::vector<Order*>();
	tempAlternativeList = nullptr;
	client_ = nullptr;
	dish_ = nullptr;
}


void Waiter::setOrder(Order* order){
	if(!order)
		return;
	orders_->push_back(order);
	order->setWaiter(this);
	//Notify(PassOrderToChef);
}

Order* Waiter::giveOrderToChef(){
	auto order = orders_->front();
	orders_->erase(orders_->begin());
	return order;
}

Dish* Waiter::getDishForClient(){
	return dish_;
}

void Waiter::approveAlternativeInredientsInClient(Client* client, std::map<Dish*,ApprovedItem>* alterList )
{
	client_ = client;
	tempAlternativeList = alterList;
	//Notify(ApproveIgredients);
}

std::map<Dish*,ApprovedItem>* Waiter::getIngredientsForApprove()
{
	return tempAlternativeList;
}

std::map<Dish*,ApprovedItem>* Waiter::getApprovedIngerients()
{
	return tempAlternativeList;
}

Client* Waiter::getClient()
{
	return client_;
}

void Waiter::setApprovedIngredients( std::map<Dish*,ApprovedItem>* temp )
{
	tempAlternativeList = temp;
}

void Waiter::getOrderFromClientAndPassToChef()
{
	//Notify(GetOrderFromClient);
}

void Waiter::passDishToClient( Client* client,Dish* dish )
{
	client_ = client;
	dish_ = dish;
	//Notify(PassDishToClient);
}
//
//void Waiter::Notify( int command )
//{
//	if(!observer_)
//		return;
//	observer_->Update(command,this);
//}

void Waiter::processBillFromClient( Order* order )
{
	currentorder_ = order;
	//Notify(ProcessBill);
}

Order* Waiter::getCurrentOrder()
{
	return currentorder_;
}
