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

void Person::setName(std::string name){
	name_ = name;
}


const std::string Person::getName(){

	return name_;
}


void Person::setSurname(std::string surname){
	surname_ = surname;
}


std::string Person::getSurname(){

	return surname_;
}


void Person::setSpecialization(Specialization sp){
	specialization_ = sp;
}


Specialization Person::getSpecialization(){
	return  specialization_;
}

std::string Person::getFullName(){
	char fullname [255];
	sprintf_s(fullname,"%s %s",getName(),getSurname());
	return std::string(fullname);
}