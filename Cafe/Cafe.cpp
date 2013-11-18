///////////////////////////////////////////////////////////
//  Cafe.cpp
//  Implementation of the Class Cafe
//  Created on:      16-Nov-2013 8:47:59 PM

///////////////////////////////////////////////////////////

#include "Cafe.h"
#define PERSONAL_MAX_COUNT 10


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
	for(size_t index = 0 ; index < waiters_.size();index++){
		auto waiter = waiters_.at(index);
		waiter->Detach(waiterObserver_);
		delete waiter;
		waiter = nullptr;
	}
	waiters_.clear();
	for (size_t index = 0; index < cooks_.size();index++){
		auto cook = cooks_.at(index);
		cook->Detach(cookObserver_);
		delete cook;
		cook = nullptr;
	}
	cooks_.clear();
}

void Cafe::addClient(Client* client){

}


void Cafe::createPersonal(){

}


void Cafe::simulation(){

}


std::string Cafe::generateError(){

	return  NULL;
}


void Cafe::initialize(){
	createChef();
	createKitchen();
	createStoreHouse();
	createWaiters();
	createCooks();
}


void Cafe::createChef(){
	chef_ = new Chef();
	chef_->ChefNotifier::Attach(chefObserver_);
}


void Cafe::createWaiters(){
	char name [50];
	char surname[50];
	for (int i= 0;i < PERSONAL_MAX_COUNT;i++)
	{
		auto waiter = new Waiter();
		sprintf_s(name,"Waiter %d",i);
		sprintf_s(surname,"SurnameW %d",i);
		waiter->setName(name);
		waiter->setSurname(surname);
		waiter->Attach(waiterObserver_);
		waiters_.push_back(waiter);
	}
}


CafeKitchen* Cafe::getKitchen(){
	return  kitchen_;
}

CafeStoreHouse* Cafe::getStoreHouse(){
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
	char name [50];
	char surname[50];
	for(int i= 0;i < PERSONAL_MAX_COUNT;i++){
		auto cook = new Cook();
		sprintf_s(name,"Cook %d",i);
		sprintf_s(surname,"CookS %d",i);
		cook->setName(name);
		cook->setSurname(surname);
		cook->Attach(cookObserver_);
		cooks_.push_back(cook);
	}
}
