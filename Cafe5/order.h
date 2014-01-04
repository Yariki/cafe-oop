#ifndef _ORDER_H_
#define _ORDER_H_

#include <vector>
#include "dish.h"


class Cook;
class Waiter;
class Client;

class Order 
{
public:
	Order(void);
	Order(std::vector<Dish*> dishes);

	

	virtual ~Order(void);

	void addDish(Dish* dish);
	void addDishes(std::vector<Dish*> dishes);
	void deleteDish(Dish* dish);
	void deleteDishes(std::vector<Dish*>);
	double getTotalCost();
	std::vector<Dish*>* getOrder();
	void setClient(Client* client);
	Client* getClient();
	void setCook(Cook* cook);
	Cook* getCook();
	void setWaiter(Waiter* waiter);
	Waiter* getWaiter();

	Order operator+(const Order&);
	Order operator-(const Order&);
	friend Order operator+ (const Order& lhs, const Order& rhs);
	friend Order operator- (const Order& lhs, const Order& rhs);

private:
    double total_cost_;
    std::vector<Dish*> order_;
	Cook* cook_;
	Waiter* waiter_;
	Client* client_;

	void calculateCost();
	void init() 
	{
		cook_ =  nullptr;
		waiter_ = nullptr;
		client_ = nullptr;
	}
};

#endif