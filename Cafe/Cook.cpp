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

}


Order* Cook::getOrder(){

	return  NULL;
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

}


CookStatus Cook::setStatus(){

	return  CookFree;
}


bool Cook::checkIngridients(){

	return false;
}


void Cook::applyEquipment(){

}


void Cook::makeNextDishFromOrder(){

}