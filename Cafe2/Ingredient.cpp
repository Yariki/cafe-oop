///////////////////////////////////////////////////////////
//  Ingredient.cpp
//  Implementation of the Class Ingredient
//  Created on:      16-Nov-2013 8:48:15 PM
///////////////////////////////////////////////////////////

#include "Ingredient.h"


Ingredient::Ingredient(int type)
{
	printf_s("Ingredient was created...\n");
}

Ingredient::Ingredient(const Ingredient& inst){
	printf_s("Ingredient was created (copy ctor)...\n");
}



Ingredient::~Ingredient(){
	printf_s("Ingredient was deleted...\n");
}
