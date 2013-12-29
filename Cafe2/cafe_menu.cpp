#include "cafe_menu.h"
#include <algorithm>

Cafe_Menu::Cafe_Menu(void)
{
	printf_s("Cafe_Menu was created...\n");
}


Cafe_Menu::~Cafe_Menu(void)
{
	printf_s("Cafe_Menu was deleted...\n");

	for(auto i = 0; i < snecks_.size();i++)
	{
		delete snecks_.at(i);
	}
	for(auto i = 0; i < snecks_.size();i++)
	{
		delete main_dishes_.at(i);
	}


	snecks_.clear();
	main_dishes_.clear();
}

void Cafe_Menu::addMainDish(Dish* d)
{
	main_dishes_.push_back(d);
}

void Cafe_Menu::addSneck(Dish* d)
{
	snecks_.push_back(d);
}