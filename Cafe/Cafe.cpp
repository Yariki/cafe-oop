///////////////////////////////////////////////////////////
//  Cafe.cpp
//  Implementation of the Class Cafe
//  Created on:      16-Nov-2013 8:47:59 PM

///////////////////////////////////////////////////////////

#include "Cafe.h"

Cafe::Cafe(){

}

Cafe::~Cafe(){

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

}


void Cafe::createChef(){

}


void Cafe::createWaiters(){

}

CafeKitchen* Cafe::getKitchen()
{
	throw std::exception("The method or operation is not implemented.");
}

CafeStoreHouse* Cafe::getStoreHouse()
{
	throw std::exception("The method or operation is not implemented.");
}


void Cafe::createKitchen(){

}


void Cafe::createStoreHouse(){

}

Chef* Cafe::getChef()
{
	throw std::exception("The method or operation is not implemented.");
}

std::vector<Cook*>* Cafe::getCooks()
{
	throw std::exception("The method or operation is not implemented.");
}

std::vector<Client*>* Cafe::getClients()
{
	throw std::exception("The method or operation is not implemented.");
}

std::vector<Waiter*>* Cafe::getWaiters()
{
	throw std::exception("The method or operation is not implemented.");
}
