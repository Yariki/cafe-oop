///////////////////////////////////////////////////////////
//  Client.cpp
//  Implementation of the Class Client
//  Created on:      16-Nov-2013 8:48:06 PM

///////////////////////////////////////////////////////////

#include "Client.h"
#include <vector>
#include <iostream>
#include <utility>

using std::cout;

#define MAX_DISH_COUNT 3



Client::~Client(){
	printf_s("Client was deleted...\n");
}

Client::Client(double money){
	printf_s("Client was created...\n");
}

Client::Client(){
	printf_s("Client was created...\n");
}

Client::Client(const Client& inst){
	printf_s("Client was created (copy ctor)...\n");
}
