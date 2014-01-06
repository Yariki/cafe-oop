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
	/*std::string name;
	std::string surname;
	printf_s("Please, enter client name: ");
	std::cin >> name;
	printf_s("Please, enter client surname: ");
	std::cin >> surname;
	auto client = new Client(rand() % 1000);
	client->setName(name);
	client->setSurname(surname);
	clients_->push_back(client);*/
}


void Cafe::simulation()
{
	printf_s("simulation\n");
	printf_s("Show waiters => (will use custom iterator for ArrayContainer and will use getters for showing name of waiter)\n");
	for(ArrayContainer<Waiter*>::array_iterator i = waiters_.begin(); i != waiters_.end();i++)
	{
		auto waiter = (Waiter*)(*i);
		printf_s("Waiter - %s\nFirst name: %s\nLast name:  %s\n",waiter->getFullName().c_str(), waiter->getName().c_str(),waiter->getSurname().c_str());
	}
	printf_s("Show cooks => (will use custom iterator for ArrayContainer and will use getters for showing name of cook)\n");
	for(ArrayContainer<Cook*>::array_iterator i = cooks_.begin(); i != cooks_.end();i++)
	{
		auto cook = (Cook*)(*i);
		printf_s("Cook - %s\nFirst name: %s\nLast name:  %s\n",cook->getFullName().c_str(), cook->getName().c_str(),cook->getSurname().c_str());
	}
	printf_s("Show clients => (will use custom iterator for ArrayContainer and will use getters for showing name (money) of client)\n");
	for(ArrayContainer<Client*>::array_iterator i = clients_.begin(); i != clients_.end();i++)
	{
		auto client = (Client*)(*i);
		printf_s("Client - %s ($%f)\nFirst name: %s\nLast name:  %s\n",client->getFullName().c_str(), client->getMoney(), client->getName().c_str(),client->getSurname().c_str());
	}
};


std::string Cafe::generateError(){

	return  NULL;
}


void Cafe::initialize(){
	cooks_ =  ArrayContainer<Cook*>(COOK_MAX_COUNT);
	clients_ = ArrayContainer<Client*>(CLIENT_MAX_COUNT);
	waiters_ = ArrayContainer<Waiter*>(WAITERS_MAX_COUNT);
	orders_ = new std::vector<Order*>();
	readFiles();
	createObservers();
	createChef();
	createKitchen();
	createStoreHouse();
	createWaiters();
	createCooks();
	createMenu();
	generateClients();
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

void Cafe::createChef(){
	chef_ = new Chef();
	//chef_->Attach(cookObserver_);
	chef_->setName(generateName());
	chef_->setSurname(generateSurname());
}

void Cafe::createWaiters(){
	for (int i= 0;i < WAITERS_MAX_COUNT;i++)
	{
		auto waiter = new Waiter();
		waiter->setName(generateName());
		waiter->setSurname(generateSurname());
		//waiter->Attach(waiterObserver_);
		waiters_[i] = waiter;
	}
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
		//cook->Attach(cookObserver_);
		cooks_[i] = cook;
	}
}

void Cafe::createObservers()
{
	cookObserver_ = new CookObserver(this);
	waiterObserver_ = new WaiterObserver(this);
}

void Cafe::generateClients()
{
	for(int i = 0; i < CLIENT_MAX_COUNT;i++)
	{
		auto client = new Client(rand() % 1000);
		client->setName(generateName());
		client->setSurname(generateSurname());
		clients_[i] = client;
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

void Cafe::generateClientForProcessing()
{
	
}

void Cafe::processNewClient(  )
{
}

bool Cafe::isNotServedClientPresent()
{
	return false; //getClient() != nullptr;
}

void Cafe::deleteAndClearClients()
{
	for(int i = 0; i < clients_.size();i++)
	{
		Client* client = clients_[i];
		delete client;
	}
}

void Cafe::deleteChef()
{
	if(chef_ !=  nullptr){
		//chef_->Detach(cookObserver_);
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
	for(int index = 0 ; index < waiters_.size();index++){
		auto waiter = waiters_[index];
		delete waiter;
		waiter = nullptr;
	}
}

void Cafe::deleteCooks()
{
	for (int index = 0; index < cooks_.size();index++){
		auto cook = cooks_[index];
		delete cook;
		cook = nullptr;
	}
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
