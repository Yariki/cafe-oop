#include<vector>
#include"dish.h"

class Order : public ICafeObject, public ICafeObject
{
	public:
	Dish *m_Dish;
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
	void setClient(Client* client);
	Client* getClient();
	void setCook(Cook* cook);
	Cook* getCook();
	void setWaiter(Waiter* waiter);
	Waiter* getWaiter();

	private:
        double total_cost_;
        std::vector<Dish> order_;
	Cook* cook_;
	Waiter* waiter_;
	Client* client_;

        void calculateCost();
};