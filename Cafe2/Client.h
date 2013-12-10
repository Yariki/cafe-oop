///////////////////////////////////////////////////////////
//  Client.h
//  Implementation of the Class Client
//  Created on:      16-Nov-2013 8:48:06 PM
///////////////////////////////////////////////////////////

#if !defined(EA_6AAAD847_88C7_4058_9A28_3112673EA0B3__INCLUDED_)
#define EA_6AAAD847_88C7_4058_9A28_3112673EA0B3__INCLUDED_

#include <map>
#include <vector>
#include <tuple>
#include "Person.h"
#include "order.h"
#include "cafe_menu.h"
#include "ClientState.h"
#include "Types.h"

class Client : public Person
{

public:
	Client();
	Client(double money);
	virtual ~Client();
	
};
#endif // !defined(EA_6AAAD847_88C7_4058_9A28_3112673EA0B3__INCLUDED_)
