#include "order.h"
#include <algorithm>

Order::Order(void)
{
	printf_s("Order was created...\n");
}

Order::Order( const Order& inst )
{
	printf_s("Order was created (copy ctor)...\n");
}

Order::~Order(void)
{
	printf_s("Order was deleted...\n");
}
