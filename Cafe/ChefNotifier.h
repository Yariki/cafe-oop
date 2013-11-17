///////////////////////////////////////////////////////////
//  ChefNotifier.h
//  Implementation of the Class ChefNotifier
//  Created on:      18-Nov-2013 12:26:27 AM
///////////////////////////////////////////////////////////

#if !defined(EA_9F7334D0_EBD1_4dbf_B40A_D99E45E8C95F__INCLUDED_)
#define EA_9F7334D0_EBD1_4dbf_B40A_D99E45E8C95F__INCLUDED_

#include "ICafeNotifier.h"
#include "ICafeObserver.h"

class Chef;

class ChefNotifier : public ICafeNotifier<ICafeObserver<Chef>>
{

public:
	ChefNotifier();
	virtual ~ChefNotifier();
	virtual void Attach(ICafeObserver<Chef>* observer);
	virtual void Detach(ICafeObserver<Chef>* observer);
	virtual void Notify(int command);

};
#endif // !defined(EA_9F7334D0_EBD1_4dbf_B40A_D99E45E8C95F__INCLUDED_)
