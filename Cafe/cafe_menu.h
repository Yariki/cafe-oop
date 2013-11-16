
#ifndef _CAFE_MENU_H_
#define _CAFE_MENU_H_

#include "ICafeObject.h"
#include "dish.h"
#include <vector>

class Cafe_Menu : public ICafeObject
{
public:
	Cafe_Menu(void);        
    virtual ~Cafe_Menu(void);

	void addSneck(Dish* d);
    void deleteSneck(Dish* d);
    void addMainDish(Dish* d);
    void deleteMainDish(Dish* d);
    std::vector<Dish*> getMenu();

private:
    std::vector<Dish*> snecks_;
    std::vector<Dish*> main_dishes_;
};

#endif