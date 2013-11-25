///////////////////////////////////////////////////////////
//  CafeKitchen.h
//  Implementation of the Class CafeKitchen
//  Created on:      16-Nov-2013 8:48:02 PM
///////////////////////////////////////////////////////////

#if !defined(EA_7A9FB63C_938C_4cd2_A53B_52E927EF750B__INCLUDED_)
#define EA_7A9FB63C_938C_4cd2_A53B_52E927EF750B__INCLUDED_

#include "CafeRoom.h"
#include "Equipment.h"
#include <vector>

class BaseCafeException;

class CafeKitchen : public CafeRoom
{

	

public:
	enum KitchenState { Normal = 0, EletricityDown,GasDown,FireDown};

	CafeKitchen(Cafe* cafe) : CafeRoom(cafe){}
	virtual ~CafeKitchen();
	Equipment* getFirstFreeEquipment();
	void releseEquipment(Equipment* equipmnent);
	Equipment* getFirstFreeAlternativeEquipment();
	void tryToGenerateAccedent();
	KitchenState getState();



	static std::string getKitchenStateName(KitchenState state);

private:
	std::vector<Equipment*> equipments_;
	KitchenState state_;

private:
	void initEquipments();
	void processException(BaseCafeException* ex,EnergyKinds energy);

};
#endif // !defined(EA_7A9FB63C_938C_4cd2_A53B_52E927EF750B__INCLUDED_)
