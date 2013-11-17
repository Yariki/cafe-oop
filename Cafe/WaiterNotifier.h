///////////////////////////////////////////////////////////
//  WaiterNotifier.h
//  Implementation of the Class WaiterNotifier
//  Created on:      18-Nov-2013 12:26:30 AM
///////////////////////////////////////////////////////////

#if !defined(EA_3460920D_A0D8_434a_A640_7DB0D0E82CB6__INCLUDED_)
#define EA_3460920D_A0D8_434a_A640_7DB0D0E82CB6__INCLUDED_

#include "ICafeNotifier.h"
#include "ICafeObserver.h"

class Waiter;

class WaiterNotifier : public ICafeNotifier<ICafeObserver<Waiter>>
{

public:
	WaiterNotifier();
	virtual ~WaiterNotifier();

	virtual void Attach(ICafeObserver<Waiter>* observer);
	virtual void Detach(ICafeObserver<Waiter>* observer);
	virtual void Notify(int command);

};
#endif // !defined(EA_3460920D_A0D8_434a_A640_7DB0D0E82CB6__INCLUDED_)
