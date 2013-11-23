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

	void setOrder(Order* order);
	Order* getOrder();
	Dish* getSnack();
	virtual void cook();
	bool intitializeCookOrder();

	// get list for cheking ingredients
	std::vector<Dish*>* getDishesIngredientsForCheking();
	// return from cheking
	void setCheckedIngredients(std::vector<Dish*>* checkedList);
	Dish* getReadyDish();
	BaseEquipment* getEquipment();


	void setStatus(CookStatus status);
	CookStatus getStatus();

	virtual void applyEquipment( BaseEquipment* equipment);
	

private:
	void  makeDishList();
	Dish* makeNextDishFromOrder();
	void clearDishList();

private:
	BaseEquipment* equipment_;
	CookStatus state_;
	Order* currentOrder_;
	std::vector<Dish*> dishList_;
	Dish* readyDish_;

};
#endif // !defined(EA_34D39089_90A1_4167_8AC2_0F99A7019000__INCLUDED_)
