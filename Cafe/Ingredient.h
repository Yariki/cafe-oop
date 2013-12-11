///////////////////////////////////////////////////////////
//  Ingredient.h
//  Implementation of the Class Ingredient
//  Created on:      16-Nov-2013 8:48:15 PM
///////////////////////////////////////////////////////////

#if !defined(EA_45CA5CE2_32A2_4539_A844_1C6BF42A4DB9__INCLUDED_)
#define EA_45CA5CE2_32A2_4539_A844_1C6BF42A4DB9__INCLUDED_

#include "IngredientKinds.h"
#include <string>

class Ingredient 
{

public:
	Ingredient(int type);
	virtual ~Ingredient();

	virtual IngredientKinds getIngredient() const;
	virtual std::string getIngridientName() const;

	static std::string GetIngredientName(IngredientKinds kind);

	//operators
	void *operator new(size_t size);
	void *operator new[](size_t size);
	void operator delete(void* ptr );
	void operator delete[](void* prt);

private:
	static std::string InternalGetIngredientName(IngredientKinds kind);

private:

	IngredientKinds type_;


};
#endif // !defined(EA_45CA5CE2_32A2_4539_A844_1C6BF42A4DB9__INCLUDED_)
