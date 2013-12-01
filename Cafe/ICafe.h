///////////////////////////////////////////////////////////
//  ICafe.h
//  Implementation of the Interface ICafe
//  Created on:      17-Nov-2013 11:49:00 AM
///////////////////////////////////////////////////////////

#if !defined(EA_D08F78D6_8325_4fee_AA0E_B3423D022D63__INCLUDED_)
#define EA_D08F78D6_8325_4fee_AA0E_B3423D022D63__INCLUDED_

#include <vector>

class Chef;
class Cook;
class Client;
class Waiter;
class CafeKitchen;
class CafeStoreHouse;
class Cafe_Menu;

class ICafe
{

public:
	ICafe() {

	}

	virtual ~ICafe() {

	}

	virtual Chef* const getChef()  =0;
	virtual std::vector<Cook*>* const  getCooks()  =0;
	virtual std::vector<Client*>* const getClients() =0;
	virtual std::vector<Waiter*>* const getWaiters() =0;
	virtual CafeKitchen* const getKitchen() =0;
	virtual CafeStoreHouse* const getStoreHouse() =0;
	virtual Cafe_Menu* const getMenu() = 0;
	virtual Client* const getClient() = 0;
	virtual Cook* const getCook() = 0;
	virtual void addOrder(Order* order) = 0;
	virtual void deleteOrder(Order* order) = 0;

};
#endif // !defined(EA_D08F78D6_8325_4fee_AA0E_B3423D022D63__INCLUDED_)
