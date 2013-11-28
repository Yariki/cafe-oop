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
	if(order)
		orders_.push(order);
}

Order* Chef::getOrder()
{
	Order* temp = orders_.front();
	orders_.pop();
	return temp;
}

void Chef::passOrderToCook()
{
	Notify(SetOrderToCook);
}

int Chef::getOrdersCount() const
{
	return orders_.size();
}
