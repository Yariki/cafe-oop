///////////////////////////////////////////////////////////
//  Client.cpp
//  Implementation of the Class Client
//  Created on:      16-Nov-2013 8:48:06 PM

///////////////////////////////////////////////////////////

#include "Client.h"
#include <vector>
#include <iostream>
#include <utility>

using std::cout;

#define MAX_DISH_COUNT 3



Client::~Client(){
	menu_ = nullptr;
}

Client::Client(double money){
	money_ = money;
	state_ = New;
}

Client::Client(){
	state_ = New;
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
	printf_s("Client '%s' eat '%s'\n",this->getFullName().c_str(),dish->getName().c_str());
	delete dish;
	dish = nullptr;
}

void Client::approveIngredients( std::map<Dish*,ApprovedItem>* temp, Cafe_Menu* menu)
{
	auto dishes = menu->getMenu();
	int index = -1;
	std::vector<Dish*> indexes;
	for(auto it = temp->begin(); it != temp->end();++it)
	{
		index++;
		Dish* tempDish = static_cast<Dish*>(it->first);
		std::vector<std::tuple<IngredientKinds,bool>> tempList = it->second.ApproveIgredients;
		bool isApprove = (rand() % 100) > 50 ? true : false;
		if(isApprove)
		{
			printf_s("Client %s  has approved changes for %s\n",getFullName().c_str(),tempDish->getName().c_str());
			for(size_t i = 0; i < tempList.size();i++)
			{
				auto tempTuple = tempList.at(i);
				std::get<1>(tempTuple) = true;
			}
		}
		else
		{
			size_t index = rand() % dishes.size();
			if(index > dishes.size())
				continue;
			Dish* dish = new Dish(*dishes.at(index));
			it->second.AlternativeDish = dish;
			it->second.ApproveIgredients.clear();
			printf_s("Client %s  hasn't approved changes for %s\n",getFullName().c_str(),tempDish->getName().c_str());
			printf_s("Client %s  has chosen new dish %s\n",getFullName().c_str(),dish->getName().c_str());
			
		}
	}
}

void Client::setState( ClientState state )
{
	state_ = state;
}

void Client::payBill( double cost )
{
	money_ -= cost;
	printf_s("Client %s paid - %lf of gold\n",getFullName().c_str(),cost);
}
