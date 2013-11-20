///////////////////////////////////////////////////////////
//  Cafe.h
//  Implementation of the Class Cafe
//  Created on:      16-Nov-2013 8:47:59 PM
///////////////////////////////////////////////////////////

#if !defined(EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_)
#define EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_

#include <vector>

#include "ICafeObject.h"
#include "Cook.h"
#include "Waiter.h"
#include "Client.h"
#include "Chef.h"
#include "cafe_menu.h"
#include "dish.h"
#include "CafeKitchen.h"
#include "CafeKitchenObserver.h"
#include "CafeStoreHouseObserver.h"
#include "ChefObserver.h"
#include "CookObserver.h"
#include "ICafe.h"
#include "WaiterObserver.h"

class CafeStoreHouse;

class Cafe : public ICafeObject, public ICafe
{

public:
	Cafe();
	virtual ~Cafe();

	void addClient();
	void generateClients();
	void simulation();
	std::string generateError();
	CafeKitchen* getKitchen() const;
	CafeStoreHouse* getStoreHouse() const;

private:
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

	virtual Chef* getChef() const;

	virtual std::vector<Cook*>* getCooks() const;

	virtual std::vector<Client*>* getClients() const;

	virtual std::vector<Waiter*>* getWaiters() const;

	virtual Cafe_Menu* getMenu() const;

	friend class CafeKitchenObserver;
	friend class ChefObserver;
	friend class CafeStoreHouseObserver;
	friend class WaiterObserver;
	friend class CookObserver;

	CafeKitchenObserver* kitchenObserver_;
	ChefObserver* chefObserver_;
	CafeStoreHouseObserver* cafeStoreHouseObserver_;
	CookObserver* cookObserver_;
	WaiterObserver* waiterObserver_;

};
#endif // !defined(EA_4E452A2C_C852_48b5_81F5_3BA9DA99E8F3__INCLUDED_)
