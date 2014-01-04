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
		if(it->first)
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

Dish::Dish(const Dish& dish)
{
	name_ = dish.getName();
	cost_ = dish.getCost();
	auto ingList = dish.getIngridients();
	for(auto it = ingList->begin(); it != ingList->end();++it)
	{
		auto temp = it->first;
		auto ing = new Ingredient(temp->getIngredient());
		ingridients_.insert(std::pair<Ingredient*,double>(ing,rand() % 30));
	}
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

std::map<Ingredient*,double>* Dish::getIngridients() const
{
	return (std::map<Ingredient*,double>* const)&ingridients_;
}


void *Dish::operator new(size_t size){
	printf_s("Allocation new 'Dish'...\n");
	void* ptr = nullptr;
	ptr = malloc(size);
	if (!ptr){
		std::bad_alloc ex;
		throw ex;
	}
	return ptr;
}

void *Dish::operator new[](size_t size){
	printf_s("Allocation new array of 'Dish'...\n");
	void* ptr = nullptr;
	ptr = malloc(size);
	if (!ptr){
		std::bad_alloc ex;
		throw ex;
	}
	return ptr;
}

void Dish::operator delete(void* ptr){
	printf_s("Deallocation 'Dish'...\n");
	free(ptr);
}

void Dish::operator delete[](void* ptr){
	printf_s("Deallocation array of 'Dish'...\n");
	free(ptr);
}




