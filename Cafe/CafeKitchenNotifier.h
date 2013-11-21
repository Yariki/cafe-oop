///////////////////////////////////////////////////////////
//  CafeKitchenNotifier.h
//  Implementation of the Class CafeKitchenNotifier
//  Created on:      18-Nov-2013 12:16:33 AM
///////////////////////////////////////////////////////////

#if !defined(EA_DE1BAA30_C0B7_4943_A3AA_BF41CC83CB56__INCLUDED_)
#define EA_DE1BAA30_C0B7_4943_A3AA_BF41CC83CB56__INCLUDED_

#include "ICafeNotifier.h"
#include "ICafeObserver.h"

class CafeKitchen;

class CafeKitchenNotifier : public ICafeNotifier<ICafeObserver<CafeKitchen>>
{

public:
	CafeKitchenNotifier();
	virtual ~CafeKitchenNotifier();

	virtual void Attach(ICafeObserver<CafeKitchen>* observer);
	virtual void Detach(ICafeObserver<CafeKitchen>* observer);
	virtual void Notify(int command);

};
#endif // !defined(EA_DE1BAA30_C0B7_4943_A3AA_BF41CC83CB56__INCLUDED_)
