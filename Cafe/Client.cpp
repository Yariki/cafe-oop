///////////////////////////////////////////////////////////
//  Client.cpp
//  Implementation of the Class Client
//  Created on:      16-Nov-2013 8:48:06 PM

///////////////////////////////////////////////////////////

#include "Client.h"
#include <vector>
#include <iostream>

using std::cout;

#define MAX_DISH_COUNT 3



Client::~Client(){
	menu_ = nullptr;
}

Client::Client(double money){
	money_ = money;
	state_ = NotServe;
}

Client::Client(){
	state_ = NotServe;
}

Order* Client::checkMenuAndMakeOrder( Cafe_Menu* menu )
{
	Order* order = new Order();
	order->setClient(this);
	setMenu(menu);
	selectDishes(order);
	setMenu(nullptr);
	state_ = Serve;
	return order;
}

void Client::setMenu( Cafe_Menu* menu )
{
	menu_ = menu;
}

void Client::selectDishes( Order* order )
{
	if(!menu_)
		return;
	std::vector<Dish*> dishes = menu_->getMenu();
	for (int i = 0; i < MAX_DISH_COUNT; i++)
	{
		size_t index = rand() % dishes.size();
		if(index > dishes.size())
			continue;
		Dish* dish = new Dish(*dishes.at(index));
		order->addDish(dish);
	}
}

ClientState Client::getState() const
{
	return state_;
}

void Client::eat( Dish* dish )
{
	if(!dish)
		return;
	printf_s("Client '%s' eat '%s'",this->getFullName(),dish->getName());
	delete dish;
	dish = nullptr;
}

void Client::approveIngredients( std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* temp )
{
	for(auto it = temp->begin(); it != temp->end();++it)
	{
		Dish* tempDish = static_cast<Dish*>(it->first);
		std::vector<std::tuple<IngredientKinds,bool>> tempList = it->second;
		for(size_t i = 0; i < tempList.size();i++)
		{
			auto tempTuple = tempList.at(i);
			bool isApprove = (rand() % 2) > 1 ? true : false;
			std::get<1>(tempTuple) = isApprove;

			printf_s("Client %s %s %s for '%s'",getFullName(),std::get<1>(tempTuple) ? "has approved" : "hasn't approve",
				Ingredient::GetIngredientName(std::get<0>(tempTuple)),tempDish->getName());
		}	
	}
}
