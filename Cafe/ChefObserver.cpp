///////////////////////////////////////////////////////////
//  ChefObserver.cpp
//  Implementation of the Class ChefObserver
//  Created on:      16-Nov-2013 9:40:54 PM
///////////////////////////////////////////////////////////

#include "ChefObserver.h"
#include "ChefCommands.h"

ChefObserver::~ChefObserver(){

}
 
void ChefObserver::Update( int command, Chef* obj )
{
	switch(command)
	{
	case SetOrderToCook:
		InternalSetOrderToCook(obj);
		break;
	}
}

void ChefObserver::InternalSetOrderToCook( Chef* const chef )
{
	Cook* cook = cafe_->getCook();
	if(!cook)
		return;
	cook->setOrder(chef->getOrder());
}
