///////////////////////////////////////////////////////////
//  CookNotifier.h
//  Implementation of the Class CookNotifier
//  Created on:      18-Nov-2013 12:26:28 AM
///////////////////////////////////////////////////////////

#if !defined(EA_806C6570_1D58_4aa7_BECB_F50117380C3F__INCLUDED_)
#define EA_806C6570_1D58_4aa7_BECB_F50117380C3F__INCLUDED_

#include "ICafeNotifier.h"
#include "ICafeObserver.h"

class Cook;

class CookNotifier : public ICafeNotifier<ICafeObserver<Cook>>
{

public:
	CookNotifier();
	virtual ~CookNotifier();

	virtual void Attach(ICafeObserver<Cook>* observer);
	virtual void Detach(ICafeObserver<Cook>* observer);
	virtual void Notify(int command);
	

};
#endif // !defined(EA_806C6570_1D58_4aa7_BECB_F50117380C3F__INCLUDED_)
