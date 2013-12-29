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
}

Cafe::~Cafe(){
	printf_s("Cafe dtor was called...\n");
}
