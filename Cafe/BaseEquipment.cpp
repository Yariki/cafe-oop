#include "BaseEquipment.h"


BaseEquipment::BaseEquipment(void)
{
}


BaseEquipment::~BaseEquipment(void)
{
}

EquipmentKinds BaseEquipment::getKind(){

	return  kind_;
}

std::string BaseEquipment::getName() const
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


