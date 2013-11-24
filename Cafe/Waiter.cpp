///////////////////////////////////////////////////////////
//  Waiter.cpp
//  Implementation of the Class Waiter
//  Created on:      16-Nov-2013 8:48:19 PM
///////////////////////////////////////////////////////////

#include "Waiter.h"
#include "WaiterCommands.h"

Waiter::~Waiter(){

}

Waiter::Waiter(){

}


void Waiter::setOrder(Order* order){
	if(!order)
		return;
	orders_.push(order);
	observer_->Update(PassOrderToChef,this);
}

Order* Waiter::giveOrderToChef(){
	auto order = orders_.front();
	orders_.pop();
	return order;
}

Dish* Waiter::getDishForClient(){
	return nullptr;
}

void Waiter::approveAlternativeInredientsInClient(Client* client, std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* alterList )
{
	client_ = client;
	tempAlternativeList = alterList;
	observer_->Update(ApproveIgredients,this);
}

std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* Waiter::getIngredientsForApprove()
{
	return tempAlternativeList;
}

std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* Waiter::getApprovedIngerients()
{
	return tempAlternativeList;
}

Client* Waiter::getClient()
{
	return client_;
}

void Waiter::setApprovedIngredients( std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* temp )
{
	tempAlternativeList = temp;
}

void Waiter::getOrderFromClient()
{
	observer_->Update(GetOrderFromClient,this);
}

void Waiter::passDishToClient( Client* client,Dish* dish )
{
	client_ = client;
	dish_ = dish;
	observer_->Update(PassDishToClient,this);
}
