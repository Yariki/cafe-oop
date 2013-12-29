///////////////////////////////////////////////////////////
//  CafeKitchen.h
//  Implementation of the Class CafeKitchen
//  Created on:      16-Nov-2013 8:48:02 PM
///////////////////////////////////////////////////////////

#if !defined(EA_7A9FB63C_938C_4cd2_A53B_52E927EF750B__INCLUDED_)
#define EA_7A9FB63C_938C_4cd2_A53B_52E927EF750B__INCLUDED_

#include "CafeRoom.h"
#include "Equipment.h"
#include <vector>


class BaseCafeException;

class CafeKitchen
{

	

public:
	enum KitchenState { Normal = 0, EletricityDown,GasDown,FireDown};

	CafeKitchen() ;
	virtual ~CafeKitchen();
};
#endif // !defined(EA_7A9FB63C_938C_4cd2_A53B_52E927EF750B__INCLUDED_)
