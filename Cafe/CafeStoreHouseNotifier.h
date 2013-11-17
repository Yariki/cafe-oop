///////////////////////////////////////////////////////////
//  CafeStoreHouseNotifier.h
//  Implementation of the Class CafeStoreHouseNotifier
//  Created on:      18-Nov-2013 12:26:25 AM
///////////////////////////////////////////////////////////

#if !defined(EA_A1E84AA3_2E7E_4b1c_BADC_FF5AEB3BB283__INCLUDED_)
#define EA_A1E84AA3_2E7E_4b1c_BADC_FF5AEB3BB283__INCLUDED_

#include "ICafeNotifier.h"
#include "ICafeObserver.h"

class CafeStoreHouse;

class CafeStoreHouseNotifier : public ICafeNotifier<ICafeObserver<CafeStoreHouse>>
{

public:
	CafeStoreHouseNotifier();
	virtual ~CafeStoreHouseNotifier();

	virtual void Attach(ICafeObserver<CafeStoreHouse>* observer);
	virtual void Detach(ICafeObserver<CafeStoreHouse>* observer);
	virtual void Notify(int command);

};
#endif // !defined(EA_A1E84AA3_2E7E_4b1c_BADC_FF5AEB3BB283__INCLUDED_)
