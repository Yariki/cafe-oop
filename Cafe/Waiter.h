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


class Client;
class Dish;

class Waiter : public Person, public ICafeNotifier<ICafeObserver<Waiter>>
{

public:
	Waiter();
	virtual ~Waiter();

	void getOrderFromClientAndPassToChef();
	void setOrder(Order* order);
	void approveAlternativeInredientsInClient(Client* client, std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* alterList);
	void setApprovedIngredients(std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* temp);
	std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* getIngredientsForApprove();
	std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* getApprovedIngerients();
	void passDishToClient(Client* client,Dish* dish);


	Client* getClient();
	Order* giveOrderToChef();
	Dish* getDishForClient();

	virtual void Notify( int command );

private:
	std::vector<Order*>* orders_;
	std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>>* tempAlternativeList;
	Client* client_;
	Dish* dish_;

};
#endif // !defined(EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_)
