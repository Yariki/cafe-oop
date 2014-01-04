///////////////////////////////////////////////////////////
//  Ingredient.cpp
//  Implementation of the Class Ingredient
//  Created on:      16-Nov-2013 8:48:15 PM
///////////////////////////////////////////////////////////

#include "Ingredient.h"


Ingredient::Ingredient(int type)
{
	type_ = (IngredientKinds)type;
}



Ingredient::~Ingredient(){

}

IngredientKinds Ingredient::getIngredient()const{
	return type_;
}

std::string Ingredient::getIngridientName() const
{
	return InternalGetIngredientName(type_);	
}

std::string Ingredient::GetIngredientName( IngredientKinds kind )
{
	return InternalGetIngredientName(kind);
}

std::string Ingredient::InternalGetIngredientName( IngredientKinds kind )
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


void *Ingredient::operator new(size_t size){
	printf_s("Allocation new 'Ingredient'...\n");
	void* ptr = nullptr;
	ptr = malloc(size);
	if(!ptr){
		std::bad_alloc ex;
		throw ex;
	}
	return ptr;
}

void *Ingredient::operator new[](size_t size){
	printf_s("Allocation new array of 'Ingredient'...\n");
	void* ptr = nullptr;
	ptr = malloc(size);
	if(!ptr){
		std::bad_alloc ex;
		throw ex;
	}
	return ptr;
}

void Ingredient::operator delete(void* ptr){
	printf_s("Deallocation 'Ingredient'...\n");
	free(ptr);
}

void Ingredient::operator delete[](void* ptr){
	printf_s("Deallocation array of 'Ingredient'...\n");
	free(ptr);
}