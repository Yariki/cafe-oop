///////////////////////////////////////////////////////////
//  Waiter.h
//  Implementation of the Class Waiter
//  Created on:      16-Nov-2013 8:48:19 PM
///////////////////////////////////////////////////////////

#if !defined(EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_)
#define EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_

#include "Person.h"
#include "order.h"
#include <map>
#include <vector>
#include <tuple>
#include <queue>
#include "IngredientKinds.h"
#include "ICafeNotifier.h"
#include "ICafeObserver.h"
#include "Types.h"
#include <string>


class Client;
class Dish;

class Waiter 
{

public:
	Waiter();
	virtual ~Waiter();

	void getOrderFromClientAndPassToChef();
	void setOrder(Order* order);
	void approveAlternativeInredientsInClient(Client* client, std::map<Dish*,ApprovedItem>* alterList);
	void setApprovedIngredients(std::map<Dish*,ApprovedItem>* temp);
	std::map<Dish*,ApprovedItem>* getIngredientsForApprove();
	std::map<Dish*,ApprovedItem>* getApprovedIngerients();
	void passDishToClient(Client* client,Dish* dish);
	void processBillFromClient(Order* order);


	void setName(std::string name);
	const std::string getName();
	void setSurname(std::string surname);
	std::string getSurname();
	void setSpecialization(Specialization sp);
	Specialization getSpecialization();
	std::string getFullName();

	Client* getClient();
	Order* giveOrderToChef();
	Dish* getDishForClient();
	Order* getCurrentOrder();

	//virtual void Notify( int command );

private:
	std::vector<Order*>* orders_;
	std::map<Dish*,ApprovedItem>* tempAlternativeList;
	Client* client_;
	Dish* dish_;
	Order* currentorder_;
	std::string name_;
	Specialization specialization_;
	std::string surname_;

};
#endif // !defined(EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_)
