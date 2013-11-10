#include<vector>
#include"dish.h"

class Order
{
	public:
		Order(void);
		Order(std::vector<Dish>);
		Order(const Order &o);
		~Order(void);

        void addDish(Dish dish);
        void addDishes(std::vector<Dish> dishes);
        void deleteDish(Dish dish);
        void deleteDishes(std::vector<Dish>);
        double getTotalCost() const;
        std::vector<Dish> getOrder() const;

	private:
        double total_cost_;
        std::vector<Dish> order_;

        void calculateCost();
};