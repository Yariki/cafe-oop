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

class ICafe
{

public:
	ICafe() {

	}

	virtual ~ICafe() {

	}

	virtual Chef* getChef() =0;
	virtual std::vector<Cook*>* getCooks() =0;
	virtual std::vector<Client*>* getClients() =0;
	virtual std::vector<Waiter*>* getWaiters() =0;
	virtual CafeKitchen* getKitchen() =0;
	virtual CafeStoreHouse* getStoreHouse() =0;

};
#endif // !defined(EA_D08F78D6_8325_4fee_AA0E_B3423D022D63__INCLUDED_)
