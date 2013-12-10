////
//  Equipment.h
//  Implementation of the Class Equipment
//  Created on:      16-Nov-2013 8:48:13 PM
///////////////////////////////////////////////////////////

#if !defined(EA_D8F124E9_CDAD_4add_A1DF_4CCD5C37384D__INCLUDED_)
#define EA_D8F124E9_CDAD_4add_A1DF_4CCD5C37384D__INCLUDED_

#include "EquipmentStatus.h"
#include "EnergyKinds.h"
#include "EquipmentKinds.h"
#include <string>


class Equipment 
{

public:
	Equipment(EnergyKinds energy, EquipmentKinds kind);
	Equipment();
	virtual ~Equipment();

	void setStatus(EquipmentStatus status);
	EquipmentStatus getStatus();
	EnergyKinds getEnergyKind();
	EquipmentKinds getKind();
	std::string getName() const;

	//operators
	void *operator new(size_t size);
	void *operator new[](size_t size);
	void operator delete(void* ptr );
	void operator delete[](void* prt);

private:
	EquipmentStatus state_;
	EnergyKinds energy_;
	EquipmentKinds kind_;

};
#endif // !defined(EA_D8F124E9_CDAD_4add_A1DF_4CCD5C37384D__INCLUDED_)
