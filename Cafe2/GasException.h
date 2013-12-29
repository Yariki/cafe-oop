///////////////////////////////////////////////////////////
//  GasException.h
//  Implementation of the Class GasException
//  Created on:      20-Nov-2013 11:18:14 PM
///////////////////////////////////////////////////////////

#if !defined(EA_6825AB18_B7B3_467f_A8D9_207D1796D8BE__INCLUDED_)
#define EA_6825AB18_B7B3_467f_A8D9_207D1796D8BE__INCLUDED_

#include "BaseCafeException.h"
#include <string>

class GasException : public BaseCafeException
{

public:
	GasException(std::string message) : BaseCafeException(message) {printf_s("GasException was created...\n");}
	virtual ~GasException();

};
#endif // !defined(EA_6825AB18_B7B3_467f_A8D9_207D1796D8BE__INCLUDED_)
