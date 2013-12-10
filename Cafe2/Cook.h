///////////////////////////////////////////////////////////
//  Cook.h
//  Implementation of the Class Cook
//  Created on:      16-Nov-2013 8:48:07 PM
///////////////////////////////////////////////////////////

#if !defined(EA_34D39089_90A1_4167_8AC2_0F99A7019000__INCLUDED_)
#define EA_34D39089_90A1_4167_8AC2_0F99A7019000__INCLUDED_

#include <tuple>
#include <queue>
#include "order.h"
#include <vector>
#include "CookStatus.h"
#include "Person.h"
#include "order.h"
#include "dish.h"
#include "Ingredient.h"
#include "IngredientKinds.h"
#include "Equipment.h"
#include "ICafeNotifier.h"
#include "ICafeObserver.h"

class Cook 
{

public:
	Cook();
	virtual ~Cook();


};
#endif // !defined(EA_34D39089_90A1_4167_8AC2_0F99A7019000__INCLUDED_)
