///////////////////////////////////////////////////////////
//  BaseCafeException.cpp
//  Implementation of the Class BaseCafeException
//  Created on:      20-Nov-2013 11:18:11 PM
///////////////////////////////////////////////////////////

#include "BaseCafeException.h"


BaseCafeException::BaseCafeException(){
	printf_s("BaseCafeException was created...\n");
}



BaseCafeException::~BaseCafeException(){
	printf_s("BaseCafeException was deleted...\n");
}

BaseCafeException::BaseCafeException(std::string message){
	message_ = message;
}



std::string BaseCafeException::getMessage(){

	return  message_;
}