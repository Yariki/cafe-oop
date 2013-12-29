///////////////////////////////////////////////////////////
//  Waiter.h
//  Implementation of the Class Waiter
//  Created on:      16-Nov-2013 8:48:19 PM
///////////////////////////////////////////////////////////

#if !defined(EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_)
#define EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_

#include "Person.h"
#include "order.h"
#include <map>
#include <vector>
#include <tuple>
#include <queue>
#include "IngredientKinds.h"
#include "ICafeNotifier.h"
#include "ICafeObserver.h"
#include "Types.h"


class Client;
class Dish;

class Waiter
{

public:
	Waiter();
	virtual ~Waiter();

};
#endif // !defined(EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_)
