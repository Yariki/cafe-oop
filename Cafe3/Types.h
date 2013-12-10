
#ifndef _TYPES_H_
#define _TYPES_H_


#include <vector>
#include <tuple>
#include "IngredientKinds.h"

class Dish;



struct ApprovedItem
{
public:
	ApprovedItem()
	{
		AlternativeDish = nullptr;
	}
	ApprovedItem(Dish* dish)
	{
		AlternativeDish = dish;
	}
	virtual ~ApprovedItem()
	{
		AlternativeDish = nullptr;
	}


	Dish* AlternativeDish;
	std::vector<std::tuple<IngredientKinds,bool>>  ApproveIgredients;
};



#endif