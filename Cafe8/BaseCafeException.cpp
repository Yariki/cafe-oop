///////////////////////////////////////////////////////////
//  BaseCafeException.cpp
//  Implementation of the Class BaseCafeException
//  Created on:      20-Nov-2013 11:18:11 PM
///////////////////////////////////////////////////////////

#include "BaseCafeException.h"


BaseCafeException::BaseCafeException(){

}

BaseCafeException::BaseCafeException(const BaseCafeException& inst){
	message_ = inst.message_;
}


BaseCafeException::~BaseCafeException(){

}

BaseCafeException::BaseCafeException(std::string message){
	message_ = message;
}



std::string BaseCafeException::getMessage(){

	return  message_;
}