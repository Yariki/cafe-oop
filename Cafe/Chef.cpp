///////////////////////////////////////////////////////////
//  Chef.cpp
//  Implementation of the Class Chef
//  Created on:      16-Nov-2013 8:48:05 PM

///////////////////////////////////////////////////////////

#include "Chef.h"
#include "CookCommands.h"
#include "ICafeNotifier.h"

Chef::~Chef(){

}

Chef::Chef(){

}

void Chef::setOrder( Order* order )
{
	currentOrder_ = order;
	this->observer_->Update(SetOrderToCook,this);
}
