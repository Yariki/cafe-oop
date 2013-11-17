///////////////////////////////////////////////////////////
//  CafeKitchenObserver.h
//  Implementation of the Class CafeKitchenObserver
//  Created on:      16-Nov-2013 9:40:58 PM
//  Original author: Yariki
///////////////////////////////////////////////////////////

#if !defined(EA_0CF32C57_23A7_41c7_9951_FB37C5B84B15__INCLUDED_)
#define EA_0CF32C57_23A7_41c7_9951_FB37C5B84B15__INCLUDED_

#include "ICafeObserver.h"
#include "ICafe.h"


class CafeKitchen;

class CafeKitchenObserver : public ICafeObserver<CafeKitchen>
{

public:
	CafeKitchenObserver(ICafe* cafe) {}
	virtual ~CafeKitchenObserver() {}
	virtual void Update( int command, CafeKitchen* obj );
private:
	ICafe* cafe_;
};
#endif // !defined(EA_0CF32C57_23A7_41c7_9951_FB37C5B84B15__INCLUDED_)
