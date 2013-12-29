#include "dish.h"
#include "Ingredient.h"

#define MAX_COUNT_INGRIDIENTS 4

Dish::Dish(void)
{
	printf_s("Dish was created...\n");
}


Dish::~Dish(void)
{
	printf_s("Dish was deleted...\n");
}

