///////////////////////////////////////////////////////////
//  Cafe.h
//  Implementation of the Class Cafe
//  Created on:      16-Nov-2013 8:47:59 PM
///////////////////////////////////////////////////////////

#if !defined(EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_)
#define EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_

#include "ICafeObject.h"
#include "Cook.h"
#include "Waiter.h"
#include "Client.h"
#include "Chef.h"

class Cafe : public ICafeObject
{

public:
	virtual ~Cafe();
	Cook *m_Cook;
	Waiter *m_Waiter;
	Client *m_Client;
	Chef *m_Chef;

	void Cafe();
	void Cafe();
	void addClient(Client* client);
	void createPersonal();
	void simulation();
	std::string generateError();
	CafeKitchen* getKitchen();
	CafeStoreHouse* getStoreHouse();

private:
	vector<Cook*> cooks_;
	vector<Client*> clients_;
	vector<Waiter*> waiters_;
	Chef* chef_;
	vector<Dish*> menu_;
	CafeKitchen* kitchen_;
	CafeStoreHouse* storehouse_;

	void initialize();
	void createChef();
	void createWaiters();
	void createKitchen();
	void createStoreHouse();

};
#endif // !defined(EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_)
