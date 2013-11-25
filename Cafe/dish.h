
#ifndef _DISH_H_
#define _DISH_H_

#include <string>
#include <map>
#include <string>
#include "Ingredient.h"

class Dish 
{
public:
	Dish(void);
    Dish(std::string name, double cost = 0);
    virtual ~Dish(void);

    void setName(std::string name);
    std::string getName() const;
    void setCost(double cost);
    double getCost() const;
	std::map<Ingredient*,double>* getIngridients() ;
	friend bool operator==(const Dish& left, const Dish& right)
    {
		if(left.getCost() == right.getCost() && left.getName() == right.getName()) return true; 
		else return false;
    }

private:
	void generateIngridients();

private:
	std::string name_;
    double cost_;
	std::map<Ingredient*,double> ingridients_;
};

#endif