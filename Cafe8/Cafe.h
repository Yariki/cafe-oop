///////////////////////////////////////////////////////////
//  Cafe.h
//  Implementation of the Class Cafe
//  Created on:      16-Nov-2013 8:47:59 PM
///////////////////////////////////////////////////////////

#if !defined(EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_)
#define EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_

#include <vector>

#include "Cook.h"
#include "Waiter.h"
#include "Client.h"
#include "Chef.h"
#include "cafe_menu.h"
#include "dish.h"
#include "CafeKitchen.h"
#include "CafeStoreHouse.h"
#include "CookObserver.h"
#include "ICafe.h"
#include "WaiterObserver.h"

class Cafe : public ICafe
{

public:
	Cafe();
	virtual ~Cafe();

	void addClient();
	void generateClients();
	void simulation();
	std::string generateError();
	virtual CafeKitchen* const getKitchen() ;
	virtual CafeStoreHouse* const getStoreHouse() ;

	virtual Chef* const getChef() ;

	virtual std::vector<Cook*>* const getCooks() ;

	virtual std::vector<Client*>* const getClients() ;

	virtual std::vector<Waiter*>* const getWaiters() ;

	virtual Cafe_Menu* const getMenu() ;

	virtual  Client* const getClient() ;

	virtual Cook* const getCook();

	virtual void addOrder( Order* order );

	virtual void deleteOrder( Order* order );

private:
	std::vector<Order*>* orders_;
	std::vector<Cook*>* cooks_;
	std::vector<Client*>* clients_;
	std::vector<Waiter*>* waiters_;
	Chef* chef_;
	Cafe_Menu* menu_;
	CafeKitchen* kitchen_;
	CafeStoreHouse* storehouse_;

	std::vector<std::string> names_;
	std::vector<std::string> surnames_;
	std::vector<std::string> dishes_;
	
	void initialize();
	void createChef();
	void createWaiters();
	void createKitchen();
	void createStoreHouse();
	void createCooks();
	void createMenu();
	void readFiles();
	void readFile(std::string filename, std::vector<std::string>* list);
	std::string generateName();
	std::string generateSurname();
	
	void createObservers();
	void deleteObservers();

private:
	void generateClientForProcessing();
	void processNewClient();
	bool isNotServedClientPresent();

	void deleteCooks();

	void deleteWaiters();

	void deleteStoreHouse();

	void deleteKitchen();

	void deleteChef();

	void deleteAndClearClients();

	void deleteOrders();

	friend class WaiterObserver;
	friend class CookObserver;

	CookObserver* cookObserver_;
	WaiterObserver* waiterObserver_;

};
#endif // !defined(EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_)
