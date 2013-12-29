///////////////////////////////////////////////////////////
//  CookObserver.cpp
//  Implementation of the Class CookObserver
//  Created on:      16-Nov-2013 9:40:56 PM
///////////////////////////////////////////////////////////

#include <algorithm>
#include <vector>
#include "CookObserver.h"
#include "CookCommands.h"
#include "Ingredient.h"
#include "CafeStoreHouse.h"
#include "order.h"
#include "Waiter.h"
#include "Equipment.h"
#include "EquipmentStatus.h"
#include "CafeKitchen.h"
#include "dish.h"
#include "cafe_menu.h"
#include "Client.h"
#include "Types.h"


CookObserver::CookObserver(ICafe* cafe){
	cafe_ = cafe;
	
}


CookObserver::~CookObserver(){
	
}