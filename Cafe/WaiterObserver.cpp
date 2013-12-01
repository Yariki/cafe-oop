///////////////////////////////////////////////////////////
//  WaiterObserver.cpp
//  Implementation of the Class WaiterObserver
//  Created on:      16-Nov-2013 9:41:00 PM
///////////////////////////////////////////////////////////

#include "WaiterObserver.h"
#include "WaiterCommands.h"
#include "Client.h"
#include "Chef.h"

WaiterObserver::~WaiterObserver(){

}

void WaiterObserver::Update( int command, Waiter* obj )
{
	switch (command)
	{
	case GetOrderFromClient:
		InternalGetOrderFromClient(obj);
		break;
	case ApproveIgredients:
		InternalApproveIngredientsFromClient(obj);
		break;
	case PassDishToClient:
		InternalPassDishToClient(obj);
		break;
	case PassOrderToChef:
		InternalPassOrderToChef(obj);
		break;
	case ProcessBill:
		InternalProcessBill(obj);
		break;
	}
}

void WaiterObserver::InternalGetOrderFromClient(Waiter* waiter)
{
	Client* client = cafe_->getClient();
	Cafe_Menu* menu = cafe_->getMenu();
	Order* order = client->checkMenuAndMakeOrder(menu);
	waiter->setOrder(order);
	cafe_->addOrder(order);
}

void WaiterObserver::InternalApproveIngredientsFromClient(Waiter* waiter)
{
	auto listApprove = waiter->getIngredientsForApprove();
	auto client = waiter->getClient();
	if(!client)
		return;
	client->approveIngredients(listApprove);
	waiter->setApprovedIngredients(listApprove);
}

void WaiterObserver::InternalPassDishToClient(Waiter*  waiter)
{
	waiter->getClient()->eat(waiter->getDishForClient());
}

void WaiterObserver::InternalPassOrderToChef(Waiter*  waiter)
{
	Order* order = waiter->giveOrderToChef();
	Chef* chef = cafe_->getChef();
	if(!chef)
		return;
	chef->setOrder(order);
}

void WaiterObserver::InternalProcessBill( Waiter* waiter )
{
	Order* order = waiter->getCurrentOrder();
	double cost = order->getTotalCost();
	order->getClient()->payBill(cost);
	cafe_->deleteOrder(order);
}
