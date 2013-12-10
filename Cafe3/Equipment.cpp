///////////////////////////////////////////////////////////
//  Equipment.cpp
//  Implementation of the Class Equipment
//  Created on:      16-Nov-2013 8:48:13 PM

///////////////////////////////////////////////////////////

#include "Equipment.h"


Equipment::~Equipment(){

}

Equipment::Equipment(EnergyKinds energy, EquipmentKinds kind){
	kind_ = kind;
	energy_ = energy;
	state_ = EquipmentFree;
}

Equipment::Equipment(){
	
}

void Equipment::setStatus(EquipmentStatus status){
	state_ = status;
}

EquipmentStatus Equipment::getStatus(){

	return state_;
}

EnergyKinds Equipment::getEnergyKind(){

	return energy_;
}

EquipmentKinds Equipment::getKind(){

	return  kind_;
}

std::string Equipment::getName() const
{
	switch(kind_)
	{
	case ElectricRange:
		return std::string("Electric Range");
	case FirePlace:
		return std::string("Fire Place");
	case GasRange:
		return std::string("Gas Range");
	}
	return std::string("None");
}

void *Equipment::operator new(size_t size){
	printf_s("Allocation new 'Equipment'...\n");
	void* ptr = nullptr;
	ptr = malloc(size);
	if(!ptr){
		std::bad_alloc ex;
		throw ex;
	}
	return ptr;
}

void *Equipment::operator new[](size_t size){
	printf_s("Allocation new array of 'Equipment'...\n");
	void* ptr = nullptr;
	ptr = malloc(size);
	if(!ptr){
		std::bad_alloc ex;
		throw ex;
	}
	return ptr;
}

void Equipment::operator delete(void* ptr){
	printf_s("Deallocation 'Equipment'...\n");
	free(ptr);
}

void Equipment::operator delete[](void* ptr){
	printf_s("Deallocation array of 'Equipment'...\n");
	free(ptr);
}


