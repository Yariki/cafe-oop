///////////////////////////////////////////////////////////
//  CafeKitchen.h
//  Implementation of the Class CafeKitchen
//  Created on:      16-Nov-2013 8:48:02 PM
///////////////////////////////////////////////////////////

#if !defined(EA_7A9FB63C_938C_4cd2_A53B_52E927EF750B__INCLUDED_)
#define EA_7A9FB63C_938C_4cd2_A53B_52E927EF750B__INCLUDED_

#include "CafeRoom.h"
#include "Equipment.h"

class CafeKitchen : public CafeRoom
{

public:
	CafeKitchen();
	virtual ~CafeKitchen();
	Equipment *m_Equipment;

	Equipment* getFirstFreeEquipment();
	void generarteException();
	void releseEquipment(Equipment* equipmnent);
	Equipment* getFirstFreeAlternativeEquipment();

private:
	vector<Equipment*> equipments_;

	void initEquipments();

};
#endif // !defined(EA_7A9FB63C_938C_4cd2_A53B_52E927EF750B__INCLUDED_)
