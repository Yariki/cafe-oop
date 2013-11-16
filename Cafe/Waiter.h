///////////////////////////////////////////////////////////
//  Waiter.h
//  Implementation of the Class Waiter
//  Created on:      16-Nov-2013 8:48:19 PM
///////////////////////////////////////////////////////////

#if !defined(EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_)
#define EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_

#include "Person.h"

class Waiter : public Person
{

public:
	virtual ~Waiter();

	void Waiter();
	void Waiter();
	void addNewClient(Client* client);
	void deleteClient(Client* client);
	void setOrder(Order* order);
	void giveOrderToChef();
	void giveOrderToClient();

private:
	vector<Client*> clients_;
	vector<Order*> orders_;

};
#endif // !defined(EA_283F64EB_2586_471d_B57C_0D322667A2A3__INCLUDED_)
