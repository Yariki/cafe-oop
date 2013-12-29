///////////////////////////////////////////////////////////
//  FirewoodException.h
//  Implementation of the Class FirewoodException
//  Created on:      20-Nov-2013 11:18:15 PM
///////////////////////////////////////////////////////////

#if !defined(EA_EEBD7BF2_684B_400e_B301_E1BA87FCF24C__INCLUDED_)
#define EA_EEBD7BF2_684B_400e_B301_E1BA87FCF24C__INCLUDED_

#include "BaseCafeException.h"
#include <string>

class FirewoodException : public BaseCafeException
{

public:
	FirewoodException(std::string message) : BaseCafeException(message){printf_s("FirewoodException was created...\n");}
	virtual ~FirewoodException();

};
#endif // !defined(EA_EEBD7BF2_684B_400e_B301_E1BA87FCF24C__INCLUDED_)
