///////////////////////////////////////////////////////////
//  ChefObserver.h
//  Implementation of the Class ChefObserver
//  Created on:      16-Nov-2013 9:40:54 PM
///////////////////////////////////////////////////////////

#if !defined(EA_5E958594_9A82_4821_A2B7_71273EB719EB__INCLUDED_)
#define EA_5E958594_9A82_4821_A2B7_71273EB719EB__INCLUDED_

#include "ICafeObserver.h"
#include "Chef.h"
#include "ICafe.h"

// TODO: I should delete this file and place all code in CookObserver

class ChefObserver : public ICafeObserver<Chef>
{

public:
	ChefObserver(ICafe* cafe){}
	virtual ~ChefObserver();

	virtual void Update( int command, Chef* obj );

private:
	void InternalSetOrderToCook(Chef* const chef);

private:
	ICafe* cafe_;

};
#endif // !defined(EA_5E958594_9A82_4821_A2B7_71273EB719EB__INCLUDED_)
