///////////////////////////////////////////////////////////
//  CookObserver.h
//  Implementation of the Class CookObserver
//  Created on:      16-Nov-2013 9:40:56 PM
///////////////////////////////////////////////////////////

#if !defined(EA_F324BC50_166E_4045_BEBD_0F57DAB19ECD__INCLUDED_)
#define EA_F324BC50_166E_4045_BEBD_0F57DAB19ECD__INCLUDED_

#include "ICafeObserver.h"
#include "Cook.h"
#include "Chef.h"
#include "ICafe.h"


struct IngredientPair 
{
	IngredientPair(IngredientKinds source,IngredientKinds target)
	{
		ingredientSource = source;
		ingredientTarget = target;
		isApproved = false;
	}

public:
	IngredientKinds ingredientSource;
	IngredientKinds ingredientTarget;
	bool isApproved;
};


class CookObserver : public ICafeObserver<Cook>
{

public:
	CookObserver(ICafe* cafe) { cafe_ = cafe;}
	virtual ~CookObserver();

	virtual void Update( int command, Cook* obj );

private:
	void InternalCheckIngredients(Cook* const cook);

	void checkIngredientsInStore( std::vector<Dish*>* dishList, CafeStoreHouse* store, std::map<Dish*,std::vector<IngredientPair>> &tempList );

	void initializeListForApproving( std::map<Dish*,std::vector<IngredientPair>> &tempList, std::map<Dish*,std::vector<std::tuple<IngredientKinds,bool>>> &listForApprove );

	void InternalPassDishToWaiter(Cook* const cook);
	void InternalCookInjured(Cook* const cook);
	void InternalApplyEquipment(Cook* const cook);
	void InternalReleaseEquipment(Cook* const cook);
	void InternalSetOrderToCook(Chef* const chef);
	void InternalPassSnakToWaiter( Cook* obj );
private:
	ICafe* cafe_;
};
#endif // !defined(EA_F324BC50_166E_4045_BEBD_0F57DAB19ECD__INCLUDED_)
