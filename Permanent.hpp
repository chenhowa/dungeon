/*****************************************************************
Class Name:		Permanent
Author:			Howard Chen
Last Modified: 	3-20-2017
Description:	Derived from Object. Intended to only be able to
				interact with other objects, and that's all.
*****************************************************************/



#ifndef HC_PERMANENT_HPP
#define HC_PERMANENT_HPP

#include "Object.hpp"

class Permanent : public Object {
public:
	/******************************
	See Permanent.cpp for documentation
	******************************/
	Permanent();
	Permanent(std::string n, std::string d, std::string k);
	virtual ~Permanent();
	
	
	
private:
	
};


#endif