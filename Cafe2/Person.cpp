///////////////////////////////////////////////////////////
//  Person.cpp
//  Implementation of the Class Person
//  Created on:      13-Nov-2013 1:27:52 AM
//  Original author: Yariki
///////////////////////////////////////////////////////////

#include "Person.h"


Person::~Person(){

}

Person::Person(){

}


Person::Person(std::string name, std::string surname, Specialization specialization)
	:name_(name),surname_(surname)
{
	specialization_ = specialization;
}

