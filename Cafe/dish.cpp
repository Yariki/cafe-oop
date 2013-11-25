#include "dish.h"
#include "Ingredient.h"

#define MAX_COUNT_INGRIDIENTS 4

Dish::Dish(void)
{
        name_ = "default";
        cost_ = 0;
		generateIngridients();
}


Dish::~Dish(void)
{
	for(auto it = ingridients_.begin(); it != ingridients_.end();++it){
		delete it->first;
	}
	ingridients_.clear();
}

Dish::Dish(std::string name, double cost)
{
        name_ = name;
        cost_ = (cost > 0) ? cost : 0;
		generateIngridients();
}

void Dish::setName(std::string name)
{
        name_ = name;
}

std::string Dish::getName() const
{
        return name_;
}

void Dish::setCost(double cost)
{
        if(cost > 0) cost_ = cost;        
}

double Dish::getCost() const
{
        return cost_;
}

void Dish::generateIngridients()
{
	for(int i = 0; i < MAX_COUNT_INGRIDIENTS;i++)
	{
		auto ingridientType = rand() % 10;
		auto ingridient = new Ingredient(ingridientType);
		ingridients_.insert(std::pair<Ingredient*,double>(ingridient,rand()  % 30));
	}
}

std::map<Ingredient*,double>* Dish::getIngridients()
{
	return &ingridients_;
}
