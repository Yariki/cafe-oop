///////////////////////////////////////////////////////////
//  CafeStoreHouse.cpp
//  Implementation of the Class CafeStoreHouse
//  Created on:      16-Nov-2013 8:48:04 PM
///////////////////////////////////////////////////////////

#include "CafeStoreHouse.h"
#include <algorithm>

#define  MAX_COUNT_INGRIDIENT 1000

CafeStoreHouse::~CafeStoreHouse(){
	for(auto it = ingredients_.begin(); it != ingredients_.end();++it)
	{
		delete it->first;
	}
	ingredients_.clear();
	listIngridients_->clear();
	delete listIngridients_;
}


void CafeStoreHouse::initIngredient(){
	ingredients_.insert(std::pair<Ingredient*,double>(new Ingredient(Meat),rand() % MAX_COUNT_INGRIDIENT));
	ingredients_.insert(std::pair<Ingredient*,double>(new Ingredient(Salt),rand() % MAX_COUNT_INGRIDIENT));
	ingredients_.insert(std::pair<Ingredient*,double>(new Ingredient(Peper),rand() % MAX_COUNT_INGRIDIENT));
	ingredients_.insert(std::pair<Ingredient*,double>(new Ingredient(Rice),rand() % MAX_COUNT_INGRIDIENT));
	ingredients_.insert(std::pair<Ingredient*,double>(new Ingredient(Flour),rand() % MAX_COUNT_INGRIDIENT));
	ingredients_.insert(std::pair<Ingredient*,double>(new Ingredient(Chicken),rand() % MAX_COUNT_INGRIDIENT));
	ingredients_.insert(std::pair<Ingredient*,double>(new Ingredient(Fish),rand() % MAX_COUNT_INGRIDIENT));
	ingredients_.insert(std::pair<Ingredient*,double>(new Ingredient(Sauce),rand() % MAX_COUNT_INGRIDIENT));
	ingredients_.insert(std::pair<Ingredient*,double>(new Ingredient(Tomato),rand() % MAX_COUNT_INGRIDIENT));
	ingredients_.insert(std::pair<Ingredient*,double>(new Ingredient(Potatoes),rand() % MAX_COUNT_INGRIDIENT));
	listIngridients_ =   new std::vector<Ingredient*>();
	for(auto it = ingredients_.begin(); it != ingredients_.end();++it)
	{
		listIngridients_->push_back(it->first);
	}
}


std::vector<Ingredient*>* CafeStoreHouse::getIngredients() const {
	return listIngridients_;
}

bool CafeStoreHouse::isEnoughIngredient(IngredientKinds type, double count) {
	
	bool result = false;
	for(auto it = ingredients_.begin();it != ingredients_.end();++it)
	{
		Ingredient* ing = it->first;
		if(ing->getIngredient() == type &&  isRequiredCountLessThenExistingCount(count, it->second))
		{
			result = true;
			break;
		}
	}
	return result;
}

void CafeStoreHouse::takeIngridient( IngredientKinds type, double count ){
	for (auto it = ingredients_.begin(); it != ingredients_.end();++it)
	{
		if(it->first->getIngredient() != type)
			continue;
		ingredients_[it->first] -= count;
	}
}

IngredientKinds CafeStoreHouse::getAlternativeIngredientFor( IngredientKinds kind )
{
	IngredientKinds tempKind = Meat;
	while(true)
	{
		size_t index = rand() % ingredients_.size();
		Ingredient* tempIngredient = nullptr;
		int count = 0;
		for(auto it = ingredients_.begin(); it != ingredients_.end();++it)
		{
			tempIngredient = it->first;
			if(count == index) break;
			count++;
		}
		if(tempIngredient && tempIngredient->getIngredient() != kind)
		{
			tempKind = tempIngredient->getIngredient();
			break;
		}
	}
	return tempKind;
}


bool CafeStoreHouse::isRequiredCountLessThenExistingCount( double& required, double& existing )
{
	return required < existing;
}
