
#ifndef _CAFE_MENU_H_
#define _CAFE_MENU_H_

#include "dish.h"
#include <vector>

class Cafe_Menu
{
public:
	Cafe_Menu(void);        
    virtual ~Cafe_Menu(void);

	void addSneck(Dish* d);
	void addMainDish(Dish* d);

private:
	std::vector<Dish*> snecks_;
	std::vector<Dish*> main_dishes_;
};

#endif