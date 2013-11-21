///////////////////////////////////////////////////////////
//  Cook.cpp
//  Implementation of the Class Cook
//  Created on:      16-Nov-2013 8:48:08 PM

///////////////////////////////////////////////////////////

#include "Cook.h"


Cook::~Cook(){

}

Cook::Cook(){

}

void Cook::setOrder(Order* order){
	if(!order)
		dishlist_.push(order);
}


Order* Cook::getOrder(){
	auto order = dishlist_.front();
	dishlist_.pop();
	return  order;
}


Dish* Cook::getSnack(){

	return  NULL;
}


void Cook::cook(){

}


bool Cook::intitializeCookOrder(){

	return false;
}


std::vector<Ingredient*>* Cook::getAlternativeIngredientsList(){

	return  NULL;
}


void Cook::setStatus(CookStatus status){
	state_ = status;
}


CookStatus Cook::setStatus(){

	return  state_;
}


bool Cook::checkIngridients(){

	return false;
}


void Cook::applyEquipment(){

}


void Cook::makeNextDishFromOrder(){

}