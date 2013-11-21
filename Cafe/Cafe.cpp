///////////////////////////////////////////////////////////
//  Cafe.cpp
//  Implementation of the Class Cafe
//  Created on:      16-Nov-2013 8:47:59 PM

///////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>

using std::cout;
using std::cin;

#include "Cafe.h"

#define PERSONAL_MAX_COUNT 10

#define DISHES_FILENAME "dishes.txt"
#define NAMES_FILENAME  "names.txt"
#define SURNAME_FILENAME "surnames.txt"


Cafe::Cafe(){
	initialize();
}

Cafe::~Cafe(){
	if(chef_ !=  nullptr){
		chef_->ChefNotifier::Detach(chefObserver_);
		delete chef_;
		chef_ = nullptr;
	}
	if(kitchen_ !=  nullptr){
		kitchen_->Detach(kitchenObserver_);
		delete kitchen_;
		kitchen_ = nullptr;
	}
	if(storehouse_ != nullptr){
		storehouse_->Detach(cafeStoreHouseObserver_);
		delete storehouse_;
		storehouse_ = nullptr;
	}
	for(size_t index = 0 ; index < waiters_->size();index++){
		auto waiter = waiters_->at(index);
		waiter->Detach(waiterObserver_);
		delete waiter;
		waiter = nullptr;
	}
	waiters_->clear();
	delete waiters_;
	for (size_t index = 0; index < cooks_->size();index++){
		auto cook = cooks_->at(index);
		cook->Detach(cookObserver_);
		delete cook;
		cook = nullptr;
	}
	cooks_->clear();
	delete cooks_;
	for(size_t i = 0; i < clients_->size();i++)
	{
		auto client = clients_->at(i);
		delete client;
		client = nullptr;
	}
	clients_->clear();
	delete clients_;

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


void Cafe::simulation(){

}


std::string Cafe::generateError(){

	return  NULL;
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
	chef_->ChefNotifier::Attach(chefObserver_);
	chef_->setName(generateName());
	chef_->setSurname(generateSurname());
}

void Cafe::createWaiters(){
	for (int i= 0;i < PERSONAL_MAX_COUNT;i++)
	{
		auto waiter = new Waiter();
		waiter->setName(generateName());
		waiter->setSurname(generateSurname());
		waiter->Attach(waiterObserver_);
		waiters_->push_back(waiter);
	}
}


CafeKitchen* Cafe::getKitchen() const{
	return  kitchen_;
}

CafeStoreHouse* Cafe::getStoreHouse() const{
	return  storehouse_;
}

void Cafe::createKitchen(){
	kitchen_ = new CafeKitchen(this);
	kitchen_->Attach(kitchenObserver_);
}


void Cafe::createStoreHouse(){
	storehouse_ = new CafeStoreHouse(this);
	storehouse_->Attach(cafeStoreHouseObserver_);
}

void Cafe::createCooks(){
	for(int i= 0;i < PERSONAL_MAX_COUNT;i++){
		auto cook = new Cook();
		cook->setName(generateName());
		cook->setSurname(generateSurname());
		cook->Attach(cookObserver_);
		cooks_->push_back(cook);
	}
}

void Cafe::createObservers()
{
	kitchenObserver_ = new CafeKitchenObserver(this);
	chefObserver_ = new ChefObserver(this);
	cafeStoreHouseObserver_ = new CafeStoreHouseObserver(this);
	cookObserver_ = new CookObserver(this);
	waiterObserver_ = new WaiterObserver(this);
}

Chef* Cafe::getChef() const
{
	return chef_;
}

std::vector<Cook*>* Cafe::getCooks() const
{
	return cooks_;
}

std::vector<Client*>* Cafe::getClients() const
{
	return clients_;
}

std::vector<Waiter*>* Cafe::getWaiters() const
{
	return waiters_;
}

Cafe_Menu* Cafe::getMenu() const
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
		printf_s("Error while reading file %s",filename);
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
	for(int i = 0; i < PERSONAL_MAX_COUNT;i++)
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

