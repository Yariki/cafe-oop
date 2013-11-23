///////////////////////////////////////////////////////////
//  BaseIngredient.cpp
//  Implementation of the Class BaseIngredient
//  Created on:      16-Nov-2013 8:47:45 PM

///////////////////////////////////////////////////////////

#include "BaseIngredient.h"


BaseIngredient::BaseIngredient(int type){
	type_ = (IngredientKinds)type;
}

BaseIngredient::~BaseIngredient(){

}


IngredientKinds BaseIngredient::getIngredient(){
	return type_;
}

std::string BaseIngredient::getIngridientName()
{
	return InternalGetIngredientName(type_);	
}

std::string BaseIngredient::GetIngredientName( IngredientKinds kind )
{
	return InternalGetIngredientName(kind);
}

std::string BaseIngredient::InternalGetIngredientName( IngredientKinds kind )
{
	switch(kind)
	{
	case Meat: return std::string("Meat");
	case Salt: return std::string("Salt");
	case Peper: return std::string("Peper");
	case Rice: return std::string("Rice");
	case Flour: return std::string("Flour");
	case Chicken: return std::string("Chicken");
	case Fish: return std::string("Fish");
	case Sauce: return std::string("Sauce");
	case Tomato: return std::string("Tomato");
	case Potatoes : return std::string("Potatoes");
	}
	return std::string("None");
}
