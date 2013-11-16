///////////////////////////////////////////////////////////
//  Person.h
//  Implementation of the Class Person
//  Created on:      13-Nov-2013 1:27:52 AM
//  Original author: Yariki
///////////////////////////////////////////////////////////

#if !defined(EA_78019771_352A_43a6_8498_311F639F29FE__INCLUDED_)
#define EA_78019771_352A_43a6_8498_311F639F29FE__INCLUDED_

#include "Specialization.h"

class Person : public ICafeObject, public ICafeObject
{

public:
	virtual ~Person();

	void Person();
	void Person(std::string name, std::string surname, Specialization specialization);
	void Person(Person p);
	void Person();
	void setName(std::string name);
	const std::string getName();
	void setSurname(std::string surname);
	std::string setSurname();
	void setSpecialization(Specialization sp);
	Specialization getSpecialization();

private:
	std::string name_;
	Specialization specialization_;
	std::string surname_;

};
#endif // !defined(EA_78019771_352A_43a6_8498_311F639F29FE__INCLUDED_)
