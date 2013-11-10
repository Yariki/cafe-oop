#include "dish.h"


Dish::Dish(void)
{
        name_ = "default";
        cost_ = 0;
}


Dish::~Dish(void)
{
}

Dish::Dish(std::string name, double cost)
{
        name_ = name;
        cost_ = (cost > 0) ? cost : 0;
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