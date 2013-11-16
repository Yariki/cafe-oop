///////////////////////////////////////////////////////////
//  CafeStoreHouseObserver.h
//  Implementation of the Class CafeStoreHouseObserver
//  Created on:      16-Nov-2013 9:40:59 PM
//  Original author: Yariki
///////////////////////////////////////////////////////////

#if !defined(EA_69103898_DC3C_4c32_B87B_96F72CE138D3__INCLUDED_)
#define EA_69103898_DC3C_4c32_B87B_96F72CE138D3__INCLUDED_

#include "ICafeObserver.h"
#include "CafeStoreHouse.h"
#include "Cafe.h"

class CafeStoreHouseObserver : public ICafeObserver<CafeStoreHouse>
{

public:
	CafeStoreHouseObserver(Cafe*  cafe) : ICafeObserver<CafeStoreHouse>*(cafe){}
	virtual ~CafeStoreHouseObserver();

	virtual void Update( int command, CafeStoreHouse* obj );


};
#endif // !defined(EA_69103898_DC3C_4c32_B87B_96F72CE138D3__INCLUDED_)
