///////////////////////////////////////////////////////////
//  ElectricityException.h
//  Implementation of the Class ElectricityException
//  Created on:      20-Nov-2013 11:18:13 PM
///////////////////////////////////////////////////////////

#if !defined(EA_0B7F38AE_A5E0_4f84_A4DE_9C21F5845191__INCLUDED_)
#define EA_0B7F38AE_A5E0_4f84_A4DE_9C21F5845191__INCLUDED_

#include "BaseCafeException.h"
#include <string>

class ElectricityException : public BaseCafeException
{

public:
	ElectricityException(std::string message) : BaseCafeException(message) {}
	virtual ~ElectricityException();

};
#endif // !defined(EA_0B7F38AE_A5E0_4f84_A4DE_9C21F5845191__INCLUDED_)
