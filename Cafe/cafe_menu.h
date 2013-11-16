#include "dish.h"
#include <vector>

class Cafe_Menu : public ICafeObject, public ICafeObject
{
public:
	Dish *m_Dish;
	Cafe_Menu(void);        
    ~Cafe_Menu(void);

	void addSneck(Dish d);
    void deleteSneck(Dish d);
    void addMainDish(Dish d);
    void deleteMainDish(Dish d);
    std::vector<Dish> getMenu();

private:
    std::vector<Dish> snecks_;
    std::vector<Dish> main_dishes_;
};