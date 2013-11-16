///////////////////////////////////////////////////////////
//  WaiterObserver.h
//  Implementation of the Class WaiterObserver
//  Created on:      16-Nov-2013 9:41:00 PM
//  Original author: Yariki
///////////////////////////////////////////////////////////

#if !defined(EA_16328FE1_4077_4274_92ED_906D818675C2__INCLUDED_)
#define EA_16328FE1_4077_4274_92ED_906D818675C2__INCLUDED_

#include "ICafeObserver.h"
#include "Waiter.h"
#include "Cafe.h"

class WaiterObserver : public ICafeObserver<Waiter>
{

public:
	WaiterObserver(Cafe*  cafe) : ICafeObserver<Waiter>(cafe){}
	virtual ~WaiterObserver();

	virtual void Update( int command, Waiter* obj );


};
#endif // !defined(EA_16328FE1_4077_4274_92ED_906D818675C2__INCLUDED_)
