///////////////////////////////////////////////////////////
//  Chef.cpp
//  Implementation of the Class Chef
//  Created on:      16-Nov-2013 8:48:05 PM

///////////////////////////////////////////////////////////

#include "Chef.h"
#include "CookCommands.h"
#include "ICafeNotifier.h"

Chef::~Chef(){
	printf_s("Chef was created...\n");
}

Chef::Chef(){
	printf_s("Chef was deleted...\n");
}
