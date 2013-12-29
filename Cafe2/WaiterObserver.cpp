///////////////////////////////////////////////////////////
//  WaiterObserver.cpp
//  Implementation of the Class WaiterObserver
//  Created on:      16-Nov-2013 9:41:00 PM
///////////////////////////////////////////////////////////

#include "WaiterObserver.h"
#include "WaiterCommands.h"
#include "Client.h"
#include "Chef.h"

WaiterObserver::~WaiterObserver(){
	printf_s("WaiterObserver was deleted...\n");
}

void WaiterObserver::Update( int command, Waiter* obj )
{
	
}
