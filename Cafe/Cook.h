///////////////////////////////////////////////////////////
//  Cook.h
//  Implementation of the Class Cook
//  Created on:      16-Nov-2013 8:48:07 PM
///////////////////////////////////////////////////////////

#if !defined(EA_34D39089_90A1_4167_8AC2_0F99A7019000__INCLUDED_)
#define EA_34D39089_90A1_4167_8AC2_0F99A7019000__INCLUDED_

#include <queue>
#include "order.h"
#include <vector>
#include "CookStatus.h"
#include "Person.h"
#include "order.h"
#include "dish.h"
#include "Ingredient.h"

class Cook : public Person
{

public:
	Cook();
	virtual ~Cook();

	void setOrder(Order* order);
	Order* getOrder();
	Dish* getSnack();
	virtual void cook();
	bool intitializeCookOrder();
	std::vector<Ingredient*>* getAlternativeIngredientsList();
	void setStatus(CookStatus status);
	CookStatus setStatus();

protected:
	virtual bool checkIngridients();
	virtual void applyEquipment();
	virtual void makeNextDishFromOrder();

private:
	std::queue<Order*> dishlist_;
	CookStatus state_;

};
#endif // !defined(EA_34D39089_90A1_4167_8AC2_0F99A7019000__INCLUDED_)
