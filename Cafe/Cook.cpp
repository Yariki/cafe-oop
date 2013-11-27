///////////////////////////////////////////////////////////
//  Cook.cpp
//  Implementation of the Class Cook
//  Created on:      16-Nov-2013 8:48:08 PM

///////////////////////////////////////////////////////////

#include "Cook.h"
#include <tuple>
#include "CookCommands.h"
#include "Waiter.h"


Cook::~Cook(){

}

Cook::Cook(){
	equipment_ = nullptr;
	state_ = CookFree;
	currentOrder_ = nullptr;
	readyDish_ = nullptr;
}

void Cook::setOrder(Order* order){
	if(!order)
		return;
	currentOrder_ = order;
	currentOrder_->setCook(this);
	makeDishList();
	Notify(CheckIngridients);
	intitializeCookOrder();
}


Order* Cook::getOrder(){
	return currentOrder_;
}


Dish* Cook::getSnack(){

	return  NULL;
}


void Cook::cook(){
	readyDish_ = makeNextDishFromOrder();
	if(readyDish_)
	{
		printf_s("Cook %s pass ready dish '%s' to %s",getFullName(),readyDish_->getName(),currentOrder_->getWaiter()->getFullName());
		Notify(PassDishToWaiter);
	}
	else
	{
		printf_s("Cook %s finished working...",getFullName());
		Notify(ReleaseEquipment);
		applyEquipment(nullptr);
		state_ = CookFree;
		currentOrder_ = nullptr;
		clearDishList();
	}
}

bool Cook::intitializeCookOrder(){

	printf_s("Cook %s started his work...",getFullName());
	state_ = CookBusy;
	Notify(ApplyEquipment);
	if(equipment_)
		printf_s("Cook %s use % for cooking",getFullName(),equipment_->getName());
	return true;
}

void Cook::setStatus(CookStatus status){
	state_ = status;
}


CookStatus Cook::getStatus(){

	return  state_;
}

void Cook::applyEquipment(Equipment* equipment){
	equipment_ = equipment;
}


Dish* Cook::makeNextDishFromOrder(){
	if(dishList_.empty())
	{
		return nullptr;
	}
	Dish* temp = dishList_.front();
	dishList_.erase(dishList_.begin());
	return temp;
}

std::vector<Dish*>* Cook::getDishesIngredientsForCheking()
{
	std::vector<Dish*>* dishes = new std::vector<Dish*>();
	for(auto it = currentOrder_->getOrder()->begin(); it != currentOrder_->getOrder()->begin();++it){
		Dish* d = new Dish(**it);
		dishes->push_back(d);
	}
	return dishes;
}

void Cook::setCheckedIngredients( std::vector<Dish*>* checkedList )
{
	if(!checkedList)
	{
		printf_s("Cook %s says that:'All ingredients are enough'...",getFullName());
		return;
	}

	for(size_t i = 0; i < checkedList->size();i++){
		Dish* dish = checkedList->at(i);
		if(!dish)
			continue;
		Dish* d = (Dish*)(*std::find_if<>(dishList_.begin(),dishList_.end(),[dish](Dish* temp) -> bool {
			return temp->getName() == dish->getName();
		}));
		if(!d)
			continue;
		for(auto it = d->getIngridients()->begin(); it != d->getIngridients()->end();++it){
			delete it->first;
		}
		d->getIngridients()->clear();
		for (auto it = dish->getIngridients()->begin();it != dish->getIngridients()->end();++it)
		{
			d->getIngridients()->insert(std::pair<Ingredient*,double>(it->first,it->second));
		}
	}
}

void Cook::makeDishList()
{
	for(int i =0 ; i < currentOrder_->getOrder()->size();i++){
		Dish* dish = currentOrder_->getOrder()->at(i);
		dishList_.push_back(dish);
	}
}

Equipment* Cook::getEquipment()
{
	return equipment_;
}

void Cook::clearDishList()
{
	if(dishList_.empty())
		return;
	for(auto it = dishList_.begin();it != dishList_.end();++it){
		delete *it;
	}
	dishList_.clear();
}

Dish* Cook::getReadyDish()
{
	return readyDish_;
}

void Cook::Notify( int command )
{
	if(!observer_)
		return;
	observer_->Update(command,this);
}

