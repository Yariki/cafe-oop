///////////////////////////////////////////////////////////
//  BaseCafeException.h
//  Implementation of the Class BaseCafeException
//  Created on:      20-Nov-2013 11:18:11 PM
///////////////////////////////////////////////////////////

#if !defined(EA_26A0D80E_30ED_4963_BDF9_C4E2032ACB8C__INCLUDED_)
#define EA_26A0D80E_30ED_4963_BDF9_C4E2032ACB8C__INCLUDED_

#include <string>

class BaseCafeException
{

public:
	BaseCafeException();
	BaseCafeException(const BaseCafeException&);
	virtual ~BaseCafeException();

	virtual std::string getMessage();

protected:
	BaseCafeException(std::string message);

private:
	std::string message_;

};
#endif // !defined(EA_26A0D80E_30ED_4963_BDF9_C4E2032ACB8C__INCLUDED_)
