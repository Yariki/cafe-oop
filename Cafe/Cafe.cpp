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
	initialize();
}

Cafe::~Cafe(){
	deleteChef();

	deleteKitchen();

	deleteStoreHouse();

	deleteWaiters();

	deleteCooks();

	deleteAndClearClients();
	deleteOrders();

	names_.clear();
	surnames_.clear();
	dishes_.clear();
}

void Cafe::addClient(){
	std::string name;
	std::string surname;
	printf_s("Please, enter client name: ");
	std::cin >> name;
	printf_s("Please, enter client surname: ");
	std::cin >> surname;
	auto client = new Client(rand() % 1000);
	client->setName(name);
	client->setSurname(surname);
	clients_->push_back(client);
}


void Cafe::simulation()
{
	if(!clients_->size())
	{
		printf_s("Clients is empty\n");
		return;
	}
	CafeTimer timer;
	timer.start();
	int ellapsed = 0.0;
	while( ( ellapsed = (int)timer.getEllapsed())  < 120 )
	{
		int temp = rand() % 10;
		if(temp > 5)
		{
			Sleep(SECONDS_SLEEP_IN_MS);
			generateClientForProcessing();
			printf_s("System time is %dh:%dm (%ds)\n",ellapsed / 60, ellapsed % 60,ellapsed);
		}
		else if(temp > 0 && temp < 5)
		{
			if(isNotServedClientPresent())
			{
				processNewClient();
			}
			if(getChef() != nullptr && getChef()->getOrdersCount() > 0)
			{
				getChef()->passOrderToCook();
			}
			for(size_t i = 0;i < cooks_->size(); i++)
			{
				auto cook = cooks_->at(i);
				if(!cook)
					continue;

				switch (cook->getStatus())
				{
				case CookSneck:
					cook->passSneck();
					break;
				case CookBusy:
					cook->cook();
						break;
				}
			}
			if(getChef() != nullptr)
			{
				switch (getChef()->getStatus())
				{
					case CookBusy:
						getChef()->cook();
						break;
					case CookSneck:
						getChef()->passSneck();
				}
			}
		}
	}
}


std::string Cafe::generateError(){

	return  NULL;
}


void Cafe::initialize(){
	cooks_ = new std::vector<Cook*>();
	clients_ = new std::vector<Client*>();
	waiters_ = new std::vector<Waiter*>();
	orders_ = new std::vector<Order*>();
	readFiles();
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
	chef_->Attach(cookObserver_);
	chef_->setName(generateName());
	chef_->setSurname(generateSurname());
}

void Cafe::createWaiters(){
	for (int i= 0;i < WAITERS_MAX_COUNT;i++)
	{
		auto waiter = new Waiter();
		waiter->setName(generateName());
		waiter->setSurname(generateSurname());
		waiter->Attach(waiterObserver_);
		waiters_->push_back(waiter);
	}
}


CafeKitchen* const Cafe::getKitchen() {
	return  kitchen_;
}

CafeStoreHouse* const Cafe::getStoreHouse() {
	return  storehouse_;
}

void Cafe::createKitchen(){
	kitchen_ = new CafeKitchen(this);
}


void Cafe::createStoreHouse(){
	storehouse_ = new CafeStoreHouse(this);
}

void Cafe::createCooks(){
	for(int i= 0;i < COOK_MAX_COUNT;i++){
		auto cook = new Cook();
		cook->setName(generateName());
		cook->setSurname(generateSurname());
		cook->Attach(cookObserver_);
		cooks_->push_back(cook);
	}
}

void Cafe::createObservers()
{
	cookObserver_ = new CookObserver(this);
	waiterObserver_ = new WaiterObserver(this);
}

Chef* const Cafe::getChef() {
	return chef_;
}

std::vector<Cook*>* const Cafe::getCooks() 
{
	return cooks_;
}

std::vector<Client*>* const Cafe::getClients() 
{
	return clients_;
}

std::vector<Waiter*>* const Cafe::getWaiters() 
{
	return waiters_;
}

Cafe_Menu* const Cafe::getMenu() 
{
	return menu_;
}

void Cafe::readFiles()
{
	readFile(NAMES_FILENAME,&names_);
	readFile(SURNAME_FILENAME,&surnames_);
	readFile(DISHES_FILENAME,&dishes_);
}

void Cafe::readFile(std::string filename, std::vector<std::string>* list)
{
	std::ifstream nameFile(filename);
	if(!nameFile)
	{
		printf_s("Error while reading file %s\n",filename.c_str());
		throw new std::exception(filename.c_str());
	}
	for (;!(nameFile.eof());)
	{
		std::string val;
		nameFile >> val;
		list->push_back(val);
	}
}

void Cafe::generateClients()
{
	if(clients_->size())
		deleteAndClearClients();
	for(int i = 0; i < CLIENT_MAX_COUNT;i++)
	{
		auto client = new Client(rand() % 1000);
		client->setName(generateName());
		client->setSurname(generateSurname());
		clients_->push_back(client);
	}
}

std::string Cafe::generateName()
{
	return names_.empty() ? std::string() : names_.at(rand() % names_.size());
}

std::string Cafe::generateSurname()
{
	return surnames_.empty() ? std::string() : surnames_.at(rand() % surnames_.size());
}

void Cafe::createMenu()
{
	menu_ = new Cafe_Menu();
	for (size_t i = 0; i < dishes_.size();i++)
	{
		auto dish = new Dish(dishes_.at(i), rand() % 125);
		if(i % 2)
			menu_->addMainDish(dish);	
		else
			menu_->addSneck(dish);
	}
}

Client* const Cafe::getClient()
{
	Client* client = nullptr;
	for(auto it = clients_->begin(); it != clients_->end();++it)
	{
		client = *it;
		if(client->getState() == NotServe)
			break;
		client = nullptr;
	}

	return client;
}

Cook* const Cafe::getCook()
{
	Cook* cook = nullptr;
	for(auto it = cooks_->begin(); it != cooks_->end();++it)
	{
		if((*it)->getStatus() != CookFree)
			continue;
		cook = static_cast<Cook*>(*it);
		break;
	}
	return cook;
}

void Cafe::generateClientForProcessing()
{
	for(size_t i = 0; i < clients_->size();i++)
	{
		if(clients_->at(i)->getState() == New)
		{
			Client* cl = clients_->at(i);
			cl->setState(NotServe);
			printf_s("New client - %s\n",cl->getFullName().c_str());
			break;
		}
	}
}

void Cafe::processNewClient(  )
{
	Waiter* waiter = waiters_->at(rand()% waiters_->size());
	if(!waiter)
		return;
	getKitchen()->tryToGenerateAccedent();
	waiter->getOrderFromClientAndPassToChef();
}

bool Cafe::isNotServedClientPresent()
{
	return getClient() != nullptr;
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
		chef_->Detach(cookObserver_);
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
		waiter->Detach(waiterObserver_);
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
		cook->Detach(cookObserver_);
		delete cook;
		cook = nullptr;
	}
	cooks_->clear();
	delete cooks_;
}

void Cafe::deleteOrders()
{
	if(!orders_->empty())
	{
		for(size_t i = 0 ; i < orders_->size();i++)
		{
			delete orders_->at(i);
		}
	}
	orders_->clear();
	delete orders_;
	orders_ = nullptr;
}


void Cafe::addOrder( Order* order )
{
	if(!order)
		return;
	orders_->push_back(order);
}

void Cafe::deleteOrder( Order* order )
{
	if(!order)
		return;
	auto it = std::find_if(orders_->begin(), orders_->end(),[&order](Order* temp)->bool{
		return temp == order;
	});
	orders_->erase(it);
	delete order;
}

