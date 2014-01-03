///////////////////////////////////////////////////////////
//  Client.h
//  Implementation of the Class Client
//  Created on:      16-Nov-2013 8:48:06 PM
///////////////////////////////////////////////////////////

#if !defined(EA_6AAAD847_88C7_4058_9A28_3112673EA0B3__INCLUDED_)
#define EA_6AAAD847_88C7_4058_9A28_3112673EA0B3__INCLUDED_

#include <map>
#include <string>
#include <vector>
#include <tuple>
#include "Person.h"
#include "order.h"
#include "cafe_menu.h"
#include "ClientState.h"
#include "Types.h"

class Client
{

public:
	Client();
	Client(double money);
	virtual ~Client();
	
	Order* checkMenuAndMakeOrder(Cafe_Menu* menu);
	void setState(ClientState state);
	ClientState getState() const;
	void eat(Dish* dish);
	void approveIngredients(std::map<Dish*,ApprovedItem>* temp,Cafe_Menu* menu);
	void payBill(double cost);

	void setName(std::string name);
	const std::string getName();
	void setSurname(std::string surname);
	std::string getSurname();
	void setSpecialization(Specialization sp);
	Specialization getSpecialization();
	std::string getFullName();
	double getMoney() const {return money_;}

private:
	void setMenu(Cafe_Menu* menu);
	void selectDishes(Order* order);
	void withdrawMoney(double sum);

private:
	double money_;
	ClientState state_;
	Cafe_Menu* menu_;
	std::string name_;
	Specialization specialization_;
	std::string surname_;

};
#endif // !defined(EA_6AAAD847_88C7_4058_9A28_3112673EA0B3__INCLUDED_)
