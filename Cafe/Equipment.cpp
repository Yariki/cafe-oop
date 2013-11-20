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