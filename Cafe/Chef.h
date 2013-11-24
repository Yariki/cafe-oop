///////////////////////////////////////////////////////////
//  Chef.h
//  Implementation of the Class Chef
//  Created on:      16-Nov-2013 8:48:05 PM
///////////////////////////////////////////////////////////

#if !defined(EA_76A3FF41_F6D6_4227_A5E3_766AFD2CB231__INCLUDED_)
#define EA_76A3FF41_F6D6_4227_A5E3_766AFD2CB231__INCLUDED_

#include "Cook.h"
#include "order.h"
#include <vector>
#include "ChefNotifier.h"

class Chef : public Cook, public ChefNotifier
{

public:
	Chef();
	virtual ~Chef();

	virtual void setOrder( Order* order );

public:
	

private:
	std::vector<Order> orders_;
	std::vector<Cook> helpers_;

};
#endif // !defined(EA_76A3FF41_F6D6_4227_A5E3_766AFD2CB231__INCLUDED_)
