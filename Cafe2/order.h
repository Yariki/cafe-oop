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
	Order(const Order& inst);
	virtual ~Order(void);
};

#endif