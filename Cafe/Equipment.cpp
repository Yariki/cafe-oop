///////////////////////////////////////////////////////////
//  Equipment.cpp
//  Implementation of the Class Equipment
//  Created on:      16-Nov-2013 8:48:13 PM

///////////////////////////////////////////////////////////

#include "Equipment.h"


Equipment::~Equipment(){

}

Equipment::Equipment(EnergyKinds energy, EquipmentKinds kind){

}

Equipment::Equipment(){

}

EquipmentKinds Equipment::getKind(){

	return  ElectricRange;
}


void Equipment::setStatus(EquipmentStatus status){

}


EquipmentStatus Equipment::getStatus(){

	return EquipmentFree;
}


EnergyKinds Equipment::getEnergyKind(){

	return Electricity;
}