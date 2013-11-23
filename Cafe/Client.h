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

class Client : public Person
{

public:
	Client();
	Client(double money);
	virtual ~Client();
	
	Order* checkMenuAndMakeOrder(Cafe_Menu* menu);
	ClientState getState() const;
	void eat(Dish* dish);
	void approveIngredients(std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* temp);

private:
	void setMenu(Cafe_Menu* menu);
	void selectDishes(Order* order);

private:
	double money_;
	ClientState state_;
	Cafe_Menu* menu_;

};
#endif // !defined(EA_6AAAD847_88C7_4058_9A28_3112673EA0B3__INCLUDED_)
