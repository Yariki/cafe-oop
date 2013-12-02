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
	prepareForCooking();
}


Order* Cook::getOrder(){
	return currentOrder_;
}


void Cook::passSneck(){

	Notify(PassSneckToWaiter);
	state_ = CookBusy;
}


void Cook::cook(){
	readyDish_ = makeNextDishFromOrder();
	if(readyDish_)
	{
		printf_s("Cook %s pass ready dish '%s' to %s\n",getFullName().c_str(),readyDish_->getName().c_str(),currentOrder_->getWaiter()->getFullName().c_str());
		Notify(PassDishToWaiter);
	}
	else
	{
		printf_s("Cook %s finished working...\n",getFullName().c_str());
		Notify(ReleaseEquipment);
		printf_s("The equipment '%s' has been released...\n",equipment_->getName().c_str());
		applyEquipment(nullptr);
		Notify(FinishedWork);
		state_ = CookFree;
		currentOrder_ = nullptr;
		clearDishList();
	}
}

bool Cook::intitializeCookOrder(){

	printf_s("Cook %s started his work...\n",getFullName().c_str());
	state_ = CookSneck;
	Notify(ApplyEquipment);
	if(equipment_)
		printf_s("Cook %s use %s for cooking\n",getFullName().c_str(),equipment_->getName().c_str());
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
	for(size_t i = 0; i <  currentOrder_->getOrder()->size();i++){
		Dish* d = new Dish(*currentOrder_->getOrder()->at(i));
		dishes->push_back(d);
	}
	return dishes;
}

void Cook::setCheckedIngredients( std::vector<std::tuple<Dish*,Dish*>>* checkedList )
{
	if(!checkedList)
	{
		printf_s("Cook %s says that:'All ingredients are enough'...\n",getFullName().c_str());
		return;
	}

	for(size_t i = 0; i < checkedList->size();i++){
		auto tup = checkedList->at(i);
		Dish* dish = std::get<0>(tup);
		Dish* altDish = std::get<1>(tup);
		if(!dish)
			continue;
		Dish* d = nullptr;
		std::vector<Dish*>::iterator iter;
		for(auto it = dishList_.begin();it != dishList_.end();++it)
		{
			if((*it)->getName() == dish->getName())
			{
				iter = it;
				d = *it;
				break;
			}
		}

		if(altDish)
		{
			dishList_.erase(iter);
			dishList_.push_back(altDish);
			continue;
		}
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
	for(size_t i =0 ; i < currentOrder_->getOrder()->size();i++){
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

void Cook::prepareForCooking()
{
	makeDishList();
	Notify(CheckIngridients);
	intitializeCookOrder();

}

