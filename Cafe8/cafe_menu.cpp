#include "cafe_menu.h"
#include <algorithm>

Cafe_Menu::Cafe_Menu(void)
{
}


Cafe_Menu::~Cafe_Menu(void)
{
    snecks_.clear();
    main_dishes_.clear();
}

void Cafe_Menu::addMainDish(Dish* d)
{
	main_dishes_.push_back(d);
}

void Cafe_Menu::deleteMainDish(Dish* d)
{
	main_dishes_.erase(std::find(main_dishes_.begin(), main_dishes_.end(), d));
}

void Cafe_Menu::addSneck(Dish* d)
{
	snecks_.push_back(d);
}

void Cafe_Menu::deleteSneck(Dish* d)
{
	snecks_.erase(std::find(snecks_.begin(), snecks_.end(), d));
}

std::vector<Dish*> Cafe_Menu::getMenu()  const 
{
	std::vector<Dish*> menu;
	menu.insert(menu.end(), snecks_.begin(), snecks_.end());
	menu.insert(menu.end(), main_dishes_.begin(), main_dishes_.end());
	return menu;
}

std::vector<Dish*>* Cafe_Menu::getSneckList() const
{
	return (std::vector<Dish*>* const)&snecks_;
}
