/*****************************************************************
Class Name:		Permanent
Author:			Howard Chen
Last Modified: 	3-20-2017
Description:	Derived from Object. Intended to only be able to
				interact with other objects, and that's all.
*****************************************************************/


#include "Permanent.hpp"

/*********************************************
Description:	Default constructs a Permanent object.
Arguments:		None.
Precondition:	None.
Postcondition:	Default constructed Permanent object.
*********************************************/
Permanent::Permanent() : Object() {
	name = "default permanent";
}

/*********************************************
Description:	Custom constructs a Permanent object.
Arguments:		[1] name, [2] description, [3] key
Precondition:	None.
Postcondition:	name = n, description = d, key = k
*********************************************/
Permanent::Permanent(std::string n, std::string d, std::string k) : 
Object(n, d, k) {
}

//virtual destructor
Permanent::~Permanent(){
}