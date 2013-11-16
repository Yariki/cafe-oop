///////////////////////////////////////////////////////////
//  CafeStoreHouse.h
//  Implementation of the Class CafeStoreHouse
//  Created on:      16-Nov-2013 8:48:04 PM
///////////////////////////////////////////////////////////

#if !defined(EA_B16CA53E_298A_45cc_89A8_3B2713E15635__INCLUDED_)
#define EA_B16CA53E_298A_45cc_89A8_3B2713E15635__INCLUDED_

#include "IngredientKinds.h"
#include "CafeRoom.h"
#include "Ingredient.h"

class CafeStoreHouse : public CafeRoom
{

public:
	virtual ~CafeStoreHouse();
	Ingredient *m_Ingredient;

	void CafeStoreHouse(Cafe* cafe);
	virtual void CafeStoreHouse();
	vector<Ingredient*> getIngredients();
	bool isEnoughIngredient(IngredientKinds type);

private:
	map<Ingredient*,double> ingredients_;

	void initIngredient();

};
#endif // !defined(EA_B16CA53E_298A_45cc_89A8_3B2713E15635__INCLUDED_)
