#include "order.h"
#include <algorithm>

Order::Order(void)
{
        total_cost_ = 0;
}

Order::Order(std::vector<Dish> dishes)
{
        order_.insert(order_.end(), dishes.begin(), dishes.end());
        calculateCost();
}

Order::Order(const Order &o)
{
        total_cost_ = o.getTotalCost();
        order_ = o.getOrder();
}

Order::~Order(void)
{
        order_.clear();
}

void Order::addDish(Dish dish)
{
        order_.push_back(dish);
        calculateCost();
}

void Order::addDishes(std::vector<Dish> dishes)
{
        order_.insert(order_.end(), dishes.begin(), dishes.end());
        calculateCost();
}

void Order::deleteDish(Dish dish)
{
        order_.erase(std::find(order_.begin(), order_.end(), dish));
        calculateCost();
}

void Order::deleteDishes(std::vector<Dish> dishes)
{
        for(int i = 0; i < dishes.size(); i++)
                order_.erase(std::find(order_.begin(), order_.end(), dishes[i]));
        calculateCost();
}

double Order::getTotalCost() const
{
        return total_cost_;
}

std::vector<Dish> Order::getOrder() const
{
        return order_;
}

void Order::calculateCost()
{
        total_cost_ = 0;
        for(int i = 0; i < order_.size(); i++)
                total_cost_ += order_[i].getCost();
}