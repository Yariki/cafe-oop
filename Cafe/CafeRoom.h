///////////////////////////////////////////////////////////
//  CafeRoom.h
//  Implementation of the Class CafeRoom
//  Created on:      16-Nov-2013 8:48:03 PM
///////////////////////////////////////////////////////////

#if !defined(EA_183058A5_9B85_4cc0_AA6F_92DC86B010E4__INCLUDED_)
#define EA_183058A5_9B85_4cc0_AA6F_92DC86B010E4__INCLUDED_

#include "ICafeObject.h"

class Cafe;

class CafeRoom : public ICafeObject
{

public:
	CafeRoom(Cafe* cafe);
	virtual ~CafeRoom();

private:
	Cafe* cafe_;

};
#endif // !defined(EA_183058A5_9B85_4cc0_AA6F_92DC86B010E4__INCLUDED_)
