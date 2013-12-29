///////////////////////////////////////////////////////////
//  Cafe.h
//  Implementation of the Class Cafe
//  Created on:      16-Nov-2013 8:47:59 PM
///////////////////////////////////////////////////////////

#if !defined(EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_)
#define EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_

#include <vector>

#include "Cook.h"
#include "Waiter.h"
#include "Client.h"
#include "Chef.h"
#include "cafe_menu.h"
#include "dish.h"
#include "CafeKitchen.h"
#include "CafeStoreHouse.h"
#include "CookObserver.h"
#include "ICafe.h"
#include "WaiterObserver.h"

class Cafe 
{

public:
	Cafe();
	virtual ~Cafe();

};
#endif // !defined(EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_)
