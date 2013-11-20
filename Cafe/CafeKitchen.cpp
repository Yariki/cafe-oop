///////////////////////////////////////////////////////////
//  CafeKitchen.cpp
//  Implementation of the Class CafeKitchen
//  Created on:      16-Nov-2013 8:48:02 PM

///////////////////////////////////////////////////////////

#include "CafeKitchen.h"
#include <algorithm>

#include "ElectricityException.h"
#include "GasException.h"
#include "FirewoodException.h"

#include <iostream>

using std::cout;
using std::cin;

CafeKitchen::~CafeKitchen(){
	for(auto it = equipments_.begin(); it != equipments_.end();++it){
		delete *it;
		*it = nullptr;
	}
	equipments_.clear();
}

void CafeKitchen::initEquipments(){
	equipments_.push_back(new Equipment(Electricity,ElectricRange));
	equipments_.push_back(new Equipment(Firewood,FirePlace));
	equipments_.push_back(new Equipment(Electricity,ElectricRange));
	equipments_.push_back(new Equipment(Gas,GasRange));
	equipments_.push_back(new Equipment(Gas,GasRange));
	equipments_.push_back(new Equipment(Electricity,ElectricRange));
	equipments_.push_back(new Equipment(Firewood,FirePlace));
}

Equipment* CafeKitchen::getFirstFreeEquipment(){
	auto equip =  dynamic_cast<Equipment*>(*std::find_if(equipments_.begin(),equipments_.end(),
		[](Equipment* equipment) -> bool
	{
		return equipment->getStatus() == EquipmentFree;
	}));
	equip->setStatus(EquipmentBusy);
	return equip;
}


void CafeKitchen::releseEquipment(Equipment* equipmnent){
	if(!equipmnent)
		return;
	equipmnent->setStatus(EquipmentFree);
}

Equipment* CafeKitchen::getFirstFreeAlternativeEquipment(){
	Equipment* equip = nullptr;
	switch	(state_)
	{
	case EletricityDown:
		equip = dynamic_cast<Equipment*>(*std::find_if(equipments_.begin(),equipments_.end(),[](Equipment* eq) -> bool {
			return (eq->getEnergyKind() == Firewood || eq->getEnergyKind() == Gas) && eq->getStatus() == EquipmentFree;
		}));
		break;
	case FireDown:
		equip = dynamic_cast<Equipment*>(*std::find_if(equipments_.begin(),equipments_.end(),[](Equipment* eq) -> bool {
			return (eq->getEnergyKind() == Electricity || eq->getEnergyKind() == Gas) && eq->getStatus() == EquipmentFree;
		}));
		break;
	case GasDown:
		equip = dynamic_cast<Equipment*>(*std::find_if(equipments_.begin(),equipments_.end(),[](Equipment* eq) -> bool {
			return (eq->getEnergyKind() == Firewood || eq->getEnergyKind() == Electricity) && eq->getStatus() == EquipmentFree;
		}));
		break;
	}
	return equip;
}

void CafeKitchen::tryToGenerateAccedent()
{
	try
	{
		auto mode = rand() % 100;
		if(mode > 0 && mode << 10)
		{
			throw new ElectricityException("Electricity is down");
		}
		else if(mode > 10 && mode << 20)
		{
			throw new GasException("Gas is down");
		}
		else if (mode > 20 && mode < 30)
		{
			throw new FirewoodException("Gas is down");
		}
		else
		{
			state_ = Normal;
			std::for_each(equipments_.begin(), equipments_.end(),[](Equipment* eq)
			{
				switch(eq->getStatus())
				{
				case EquipmentInException:
				case EquipmentBroken:
					eq->setStatus(EquipmentFree);
					break;
				}
			});
		}
	}
	catch (ElectricityException* e)
	{
		processException(e,Electricity);
	}
	catch (GasException* e)
	{
		processException(e,Gas);
	}
	catch (FirewoodException* e)
	{
		processException(e,Firewood);
	}
}

void CafeKitchen::processException( BaseCafeException* ex,EnergyKinds energy )
{
	if(!ex)
		return;
	cout << ex->getMessage();
	delete ex;

	for(auto it = equipments_.begin(); it != equipments_.end();++it)
	{
		Equipment* eq = (Equipment*)*it;
		if(eq->getEnergyKind() == energy)
		{
			eq->setStatus(EquipmentBroken);
		}
		else if(eq->getStatus() != EquipmentBusy)
			eq->setStatus(EquipmentFree);
	}

}
