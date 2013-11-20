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