///////////////////////////////////////////////////////////
//  CookObserver.h
//  Implementation of the Class CookObserver
//  Created on:      16-Nov-2013 9:40:56 PM
//  Original author: Yariki
///////////////////////////////////////////////////////////

#if !defined(EA_F324BC50_166E_4045_BEBD_0F57DAB19ECD__INCLUDED_)
#define EA_F324BC50_166E_4045_BEBD_0F57DAB19ECD__INCLUDED_

#include "ICafeObserver.h"
#include "Cook.h"
#include "ICafe.h"

class CookObserver : public ICafeObserver<Cook>
{

public:
	CookObserver(ICafe* cafe) {}
	virtual ~CookObserver();

	virtual void Update( int command, Cook* obj );
private:
	ICafe* cafe_;
};
#endif // !defined(EA_F324BC50_166E_4045_BEBD_0F57DAB19ECD__INCLUDED_)
