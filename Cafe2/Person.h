///////////////////////////////////////////////////////////
//  Person.h
//  Implementation of the Class Person
//  Created on:      13-Nov-2013 1:27:52 AM
//  Original author: Yariki
///////////////////////////////////////////////////////////

#if !defined(EA_78019771_352A_43a6_8498_311F639F29FE__INCLUDED_)
#define EA_78019771_352A_43a6_8498_311F639F29FE__INCLUDED_

#include <string>

#include "Specialization.h"

class Person
{

public:
	Person();
	Person(std::string name, std::string surname, Specialization specialization);
	virtual ~Person();

private:
	std::string name_;
	Specialization specialization_;
	std::string surname_;

};
#endif // !defined(EA_78019771_352A_43a6_8498_311F639F29FE__INCLUDED_)
