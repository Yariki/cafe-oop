
#ifndef _BASEEQUIPMENT_H_
#define _BASEEQUIPMENT_H_

#include "icafeobject.h"
#include "EquipmentKinds.h"
#include <string>

class BaseEquipment :
	public ICafeObject
{
public:
	BaseEquipment(void);
	virtual ~BaseEquipment(void);
	EquipmentKinds getKind();
	std::string getName() const;

protected:
	EquipmentKinds kind_;
};

#endif