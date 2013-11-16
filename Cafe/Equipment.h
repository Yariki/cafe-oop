///////////////////////////////////////////////////////////
//  Equipment.h
//  Implementation of the Class Equipment
//  Created on:      16-Nov-2013 8:48:13 PM
///////////////////////////////////////////////////////////

#if !defined(EA_D8F124E9_CDAD_4add_A1DF_4CCD5C37384D__INCLUDED_)
#define EA_D8F124E9_CDAD_4add_A1DF_4CCD5C37384D__INCLUDED_

#include "EquipmentKinds.h"
#include "EquipmentStatus.h"
#include "EnergyKinds.h"
#include "ICafeObject.h"

class Equipment : public ICafeObject
{

public:
	Equipment(EnergyKinds energy, EquipmentKinds kind);
	Equipment();
	virtual ~Equipment();

	EquipmentKinds getKind();
	void setStatus(EquipmentStatus status);
	EquipmentStatus getStatus();
	EnergyKinds getEnergyKind();

private:
	EquipmentKinds kind_;
	EquipmentStatus state_;
	EnergyKinds enegry_;

};
#endif // !defined(EA_D8F124E9_CDAD_4add_A1DF_4CCD5C37384D__INCLUDED_)
