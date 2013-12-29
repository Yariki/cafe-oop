///////////////////////////////////////////////////////////
//  WaiterObserver.h
//  Implementation of the Class WaiterObserver
//  Created on:      16-Nov-2013 9:41:00 PM
///////////////////////////////////////////////////////////

#if !defined(EA_16328FE1_4077_4274_92ED_906D818675C2__INCLUDED_)
#define EA_16328FE1_4077_4274_92ED_906D818675C2__INCLUDED_

#include "ICafeObserver.h"
#include "Waiter.h"
#include "ICafe.h"

class WaiterObserver : public ICafeObserver<Waiter>
{

public:
	WaiterObserver(ICafe*  cafe) {cafe_ = cafe; printf_s("WaiterObserver was created...\n");}
	virtual ~WaiterObserver();

	virtual void Update( int command, Waiter* obj );

private:
	ICafe* cafe_;
};
#endif // !defined(EA_16328FE1_4077_4274_92ED_906D818675C2__INCLUDED_)
