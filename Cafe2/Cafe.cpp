///////////////////////////////////////////////////////////
//  Cafe.cpp
//  Implementation of the Class Cafe
//  Created on:      16-Nov-2013 8:47:59 PM

///////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <windows.h>
#include "CafeTimer.h"

using std::cout;
using std::cin;

#include "Cafe.h"

#define CLIENT_MAX_COUNT 20
#define COOK_MAX_COUNT 3
#define WAITERS_MAX_COUNT 5
#define SECONDS_SLEEP_IN_MS 2000

#define DISHES_FILENAME "dishes.txt"
#define NAMES_FILENAME  "names.txt"
#define SURNAME_FILENAME "surnames.txt"


Cafe::Cafe(){
	printf_s("Cafe ctor was called...\n");
	initialize();
}

Cafe::~Cafe(){
	printf_s("Cafe dtor was called...\n");
	deleteChef();

	deleteKitchen();

	deleteStoreHouse();

	deleteWaiters();

	deleteCooks();

	deleteAndClearClients();
	delete menu_;
	delete cookObserver_;
	delete waiterObserver_;
}

void Cafe::simulation()
{
	printf_s("simulation...\n");
}

void Cafe::initialize(){
	cooks_ = new std::vector<Cook*>();
	clients_ = new std::vector<Client*>();
	waiters_ = new std::vector<Waiter*>();
	createObservers();
	createChef();
	createKitchen();
	createStoreHouse();
	createWaiters();
	createCooks();
	createMenu();
}

void Cafe::createChef(){
	chef_ = new Chef();
}

void Cafe::createWaiters(){
	for (int i= 0;i < WAITERS_MAX_COUNT;i++)
	{
		auto waiter = new Waiter();
		waiters_->push_back(waiter);
	}
}

void Cafe::createKitchen(){
	kitchen_ = new CafeKitchen();
}


void Cafe::createStoreHouse(){
	storehouse_ = new CafeStoreHouse();
}

void Cafe::createCooks(){
	for(int i= 0;i < COOK_MAX_COUNT;i++){
		auto cook = new Cook();
		cooks_->push_back(cook);
	}
}

void Cafe::createObservers()
{
	cookObserver_ = new CookObserver(nullptr);
	waiterObserver_ = new WaiterObserver(nullptr);
}

void Cafe::generateClients()
{
	if(clients_->size())
		deleteAndClearClients();
	for(int i = 0; i < CLIENT_MAX_COUNT;i++)
	{
		auto client = new Client(rand() % 1000);
		clients_->push_back(client);
	}
}

void Cafe::createMenu()
{
	menu_ = new Cafe_Menu();
	for (size_t i = 0; i < 10;i++)
	{
		auto dish = new Dish();
		if(i % 2)
			menu_->addMainDish(dish);	
		else
			menu_->addSneck(dish);
	}
}

void Cafe::deleteAndClearClients()
{
	for(size_t i = 0; i < clients_->size();i++)
	{
		auto client = clients_->at(i);
		delete client;
		client = nullptr;
	}
	clients_->clear();
	delete clients_;
}

void Cafe::deleteChef()
{
	if(chef_ !=  nullptr){
		delete chef_;
		chef_ = nullptr;
	}
}

void Cafe::deleteKitchen()
{
	if(kitchen_ !=  nullptr){
		delete kitchen_;
		kitchen_ = nullptr;
	}
}

void Cafe::deleteStoreHouse()
{
	if(storehouse_ != nullptr){
		delete storehouse_;
		storehouse_ = nullptr;
	}
}

void Cafe::deleteWaiters()
{
	for(size_t index = 0 ; index < waiters_->size();index++){
		auto waiter = waiters_->at(index);
		delete waiter;
		waiter = nullptr;
	}
	waiters_->clear();
	delete waiters_;
}

void Cafe::deleteCooks()
{
	for (size_t index = 0; index < cooks_->size();index++){
		auto cook = cooks_->at(index);
		delete cook;
		cook = nullptr;
	}
	cooks_->clear();
	delete cooks_;
}
