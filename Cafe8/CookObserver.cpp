///////////////////////////////////////////////////////////
//  CookObserver.cpp
//  Implementation of the Class CookObserver
//  Created on:      16-Nov-2013 9:40:56 PM
///////////////////////////////////////////////////////////

#include <algorithm>
#include <vector>
#include "CookObserver.h"
#include "CookCommands.h"
#include "Ingredient.h"
#include "CafeStoreHouse.h"
#include "order.h"
#include "Waiter.h"
#include "Equipment.h"
#include "EquipmentStatus.h"
#include "CafeKitchen.h"
#include "dish.h"
#include "cafe_menu.h"
#include "Client.h"
#include "Types.h"


CookObserver::~CookObserver(){

}

void CookObserver::Update( int command, Cook* obj )
{
	switch(command)
	{
	case CheckIngridients:
		InternalCheckIngredients(obj);
		break;
	case PassDishToWaiter:
		InternalPassDishToWaiter(obj);
		break;
	case CookInjured:
		InternalCookInjured(obj);
		break;
	case ApplyEquipment:
		InternalApplyEquipment(obj);
		break;
	case ReleaseEquipment:
		InternalReleaseEquipment(obj);
		break;
	case SetOrderToCook:
		InternalSetOrderToCook((Chef*)obj);
		break;
	case  PassSneckToWaiter:
		InternalPassSnakToWaiter(obj);
		break;
	case FinishedWork:
		InternalFinishedWork(obj);
		break;
	}
}

void CookObserver::InternalCheckIngredients( Cook* const cook )
{
	/*std::vector<Dish*>* dishList = cook->getDishesIngredientsForCheking();
	CafeStoreHouse* store = cafe_->getStoreHouse();
	if(!store)
	return;
	std::map<Dish*,std::vector<IngredientPair>> tempList;
	checkIngredientsInStore(dishList, store, tempList);

	if(tempList.empty())
	{
	cook->setCheckedIngredients(nullptr);
	}
	else
	{

	std::map<Dish*,ApprovedItem> listForApprove;
	initializeListForApproving(tempList, listForApprove);
	Order* order = cook->getOrder();
	Waiter* waiter = order->getWaiter();
	waiter->approveAlternativeInredientsInClient(order->getClient(),&listForApprove);
	auto approvedList = waiter->getApprovedIngerients();
	std::vector<std::tuple<Dish*,Dish*>> listDishesWithApproved;
	for (auto it = approvedList->begin(); it != approvedList->end();++it)
	{
	Dish* dish = it->first;

	if(!it->second.ApproveIgredients.size())
	{
	listDishesWithApproved.push_back(std::tuple<Dish*,Dish*>(dish,it->second.AlternativeDish));
	continue;
	}
	for(size_t i = 0; i < it->second.ApproveIgredients.size();i++)
	{
	auto tup = it->second.ApproveIgredients.at(i);
	IngredientKinds k = std::get<0>(tup);
	bool approved = std::get<1>(tup);

	std::vector<IngredientPair>* list = &tempList[dish];
	auto iter = std::find_if(list->begin(),list->end(),[&k](IngredientPair& pair) ->  bool {
	return pair.ingredientTarget == k;
	});
	IngredientPair p = (*iter);

	Ingredient* key = nullptr;
	for(auto it = dish->getIngridients()->begin();it != dish->getIngridients()->end();++it)
	{
	if(it->first->getIngredient() == p.ingredientSource)
	{
	key = it->first;
	break;
	}
	}
	list->erase(iter);
	dish->getIngridients()->erase(key);
	delete key;

	if(approved)
	dish->getIngridients()->insert(std::pair<Ingredient*,double>(new Ingredient(p.ingredientTarget),rand() % 10));
	}
	listDishesWithApproved.push_back(std::tuple<Dish*,Dish*>(dish,nullptr));
	}
	cook->setCheckedIngredients(&listDishesWithApproved);
	}*/
}

void CookObserver::InternalPassDishToWaiter( Cook* const cook )
{
	Waiter* waiter = cook->getOrder()->getWaiter();
	waiter->passDishToClient(cook->getOrder()->getClient(),cook->getReadyDish());
}

void CookObserver::InternalCookInjured( Cook* const cook )
{
}

void CookObserver::InternalApplyEquipment( Cook* const cook )
{
	/*Equipment* eq = nullptr;
	printf_s("Kitchen has %s\n",CafeKitchen::getKitchenStateName(cafe_->getKitchen()->getState()).c_str());
	if(cafe_->getKitchen()->getState() == CafeKitchen::Normal)
	{
		eq = cafe_->getKitchen()->getFirstFreeEquipment();
	}
	else
		eq = cafe_->getKitchen()->getFirstFreeAlternativeEquipment();
	cook->applyEquipment(eq);*/
}

void CookObserver::InternalReleaseEquipment( Cook* const cook )
{
	/*auto eq = cook->getEquipment();
	cafe_->getKitchen()->releseEquipment((Equipment*)eq);*/

}

void CookObserver::initializeListForApproving( std::map<Dish*,std::vector<IngredientPair>> &tempList, std::map<Dish*,ApprovedItem> &listForApprove )
{
	for (auto it = tempList.begin();it != tempList.end();++it)
	{
		std::pair<Dish*,ApprovedItem> pairApp;
		Dish* dish = it->first;
		pairApp.first = dish;
		pairApp.second = ApprovedItem(nullptr);
		for(auto itIng = it->second.begin(); itIng != it->second.end();++itIng)
		{
			IngredientPair p = (IngredientPair)(*itIng);
			pairApp.second.ApproveIgredients.push_back(std::tuple<IngredientKinds,bool>(p.ingredientTarget,p.isApproved));
		}
		listForApprove.insert(pairApp);
	}
}

void CookObserver::checkIngredientsInStore( std::vector<Dish*>* dishList, CafeStoreHouse* store, std::map<Dish*,std::vector<IngredientPair>> &tempList )
{
	// pass all dishes;
	for(auto it = dishList->begin();it != dishList->end();++it)
	{
		Dish* tempDish = static_cast<Dish*>(*it);
		std::pair<Dish*,std::vector<IngredientPair>> tempPair;
		tempPair.first = tempDish;
		bool shouldAdd = false;
		// pass all ingredients check if is enough
		for(auto itIng = tempDish->getIngridients()->begin();itIng != tempDish->getIngridients()->end();++itIng)
		{
			Ingredient* tempIng = static_cast<Ingredient*>(itIng->first);
			double count = itIng->second;
			if(store->isEnoughIngredient(tempIng->getIngredient(),count))
			{
				store->takeIngridient(tempIng->getIngredient(),count);
				printf_s("Get ingredient '%s' - %lf\n",tempIng->getIngridientName().c_str(),count);
			}
			else
			{
				auto target = store->getAlternativeIngredientFor(tempIng->getIngredient());
				tempPair.second.push_back(IngredientPair(tempIng->getIngredient(),target));
				shouldAdd = true;
			}
		}
		if(shouldAdd)
			tempList.insert(tempPair);
	}
}

void CookObserver::InternalSetOrderToCook( Chef* const chef )
{
	/*Cook* cook = cafe_->getCook();
	if(!cook)
	{
		printf_s("All cooks are busy... Clients should wait...\n");
		Chef* chef = cafe_->getChef();
		if(chef->getStatus() == CookFree && chef->getOrdersCount() > 0)
		{
			printf_s("Chef %s is free. So he will cook next order in queue...\n",chef->getFullName().c_str());
			chef->prepareNextOrder();
		}
		return;
	}
		
	cook->setOrder(chef->getOrderForCook());*/
}

void CookObserver::InternalPassSnakToWaiter( Cook* obj )
{
	/*Cafe_Menu* menu = cafe_->getMenu();
	Dish* sneck = new Dish(*menu->getSneckList()->at(rand() % menu->getSneckList()->size()));
	Client* cl = obj->getOrder()->getClient();
	printf_s("Cook %s pass to %s sneck '%s' from restaurant... \n",obj->getFullName().c_str(),cl->getFullName().c_str(),sneck->getName().c_str());
	obj->getOrder()->getWaiter()->passDishToClient(cl,sneck);*/
}

void CookObserver::InternalFinishedWork( Cook* obj )
{
	Order* order = obj->getOrder();
	Waiter* waiter = order->getWaiter();
	waiter->processBillFromClient(order);
}