///////////////////////////////////////////////////////////
//  Waiter.h
//  Implementation of the Class Waiter
//  Created on:      16-Nov-2013 8:48:19 PM
///////////////////////////////////////////////////////////

#if !defined(EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_)
#define EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_

#include "Person.h"
#include "order.h"
#include "Client.h"
#include <vector>
#include "WaiterNotifier.h"

class Waiter : public Person, public WaiterNotifier
{

public:
	Waiter();
	virtual ~Waiter();

	void addNewClient(Client* client);
	void deleteClient(Client* client);
	void setOrder(Order* order);
	void giveOrderToChef();
	void giveOrderToClient();

private:
	std::vector<Client*> clients_;
	std::vector<Order*> orders_;

};
#endif // !defined(EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_)
