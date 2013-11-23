///////////////////////////////////////////////////////////
//  BaseIngredient.h
//  Implementation of the Class BaseIngredient
//  Created on:      16-Nov-2013 8:47:45 PM
///////////////////////////////////////////////////////////

#if !defined(EA_8C373447_336B_4cf8_94FE_BE6E8C33AAD0__INCLUDED_)
#define EA_8C373447_336B_4cf8_94FE_BE6E8C33AAD0__INCLUDED_

#include "IngredientKinds.h"
#include "ICafeObject.h"
#include <string>

class BaseIngredient : public ICafeObject
{

public:
	BaseIngredient(int type);
	virtual ~BaseIngredient();

	virtual IngredientKinds getIngredient();
	virtual std::string getIngridientName();
	
	static std::string GetIngredientName(IngredientKinds kind);

private:
	static std::string InternalGetIngredientName(IngredientKinds kind);

private:

	IngredientKinds type_;

};
#endif // !defined(EA_8C373447_336B_4cf8_94FE_BE6E8C33AAD0__INCLUDED_)
