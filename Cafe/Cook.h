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
#include "CookNotifier.h"
#include "IngredientKinds.h"
#include "BaseEquipment.h"

class Cook : public Person, public CookNotifier
{

public:
	Cook();
	virtual ~Cook();

	virtual void setOrder(Order* order);
	virtual Order* getOrder();
	virtual Dish* getSnack();
	virtual void cook();
	virtual bool intitializeCookOrder();

	// get list for cheking ingredients
	virtual std::vector<Dish*>* getDishesIngredientsForCheking();
	// return from cheking
	virtual void setCheckedIngredients(std::vector<Dish*>* checkedList);
	virtual Dish* getReadyDish();
	virtual BaseEquipment* getEquipment();


	void setStatus(CookStatus status);
	CookStatus getStatus();

	virtual void applyEquipment( BaseEquipment* equipment);
	
protected:
	virtual void  makeDishList();
	virtual Dish* makeNextDishFromOrder();
	virtual void clearDishList();

protected:
	BaseEquipment* equipment_;
	CookStatus state_;
	Order* currentOrder_;
	std::vector<Dish*> dishList_;
	Dish* readyDish_;

};
#endif // !defined(EA_34D39089_90A1_4167_8AC2_0F99A7019000__INCLUDED_)
