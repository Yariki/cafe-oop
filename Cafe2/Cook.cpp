///////////////////////////////////////////////////////////
//  Cook.cpp
//  Implementation of the Class Cook
//  Created on:      16-Nov-2013 8:48:08 PM

///////////////////////////////////////////////////////////

#include "Cook.h"
#include <tuple>
#include "CookCommands.h"
#include "Waiter.h"


Cook::~Cook(){
	printf_s("Cook was deleted...\n");
}

Cook::Cook(){
	printf_s("Cook was created...\n");
}
