#include "order.h"
#include <algorithm>

Order::Order(void)
{
        total_cost_ = 0;
}

Order::Order(std::vector<Dish*> dishes)
{
        order_.insert(order_.end(), dishes.begin(), dishes.end());
        calculateCost();
}


Order::~Order(void)
{
        order_.clear();
}

void Order::addDish(Dish* dish)
{
        order_.push_back(dish);
        calculateCost();
}

void Order::addDishes(std::vector<Dish*> dishes)
{
        order_.insert(order_.end(), dishes.begin(), dishes.end());
        calculateCost();
}

void Order::deleteDish(Dish* dish)
{
        order_.erase(std::find(order_.begin(), order_.end(), dish));
        calculateCost();
}

void Order::deleteDishes(std::vector<Dish*> dishes)
{
        for(size_t i = 0; i < dishes.size(); i++)
                order_.erase(std::find(order_.begin(), order_.end(), dishes[i]));
        calculateCost();
}

double Order::getTotalCost()
{
        return total_cost_;
}

std::vector<Dish*>* Order::getOrder()
{
        return (std::vector<Dish*>*)&order_;
}

void Order::calculateCost()
{
        total_cost_ = 0;
        for(size_t i = 0; i < order_.size(); i++)
                total_cost_ += order_[i]->getCost();
}


void Order::setClient(Client* client){
	client_ = client;
}


Client* Order::getClient(){

	return  client_;
}


void Order::setCook(Cook* cook){
	cook_ = cook;
}


Cook* Order::getCook(){

	return  cook_;
}


void Order::setWaiter(Waiter* waiter){
	waiter_ = waiter;
}


Waiter* Order::getWaiter(){

	return  waiter_;
}