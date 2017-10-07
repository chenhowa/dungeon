/***********************************************************
Class Name:		Holdable
Author:			Howard Chen
Last Modified:	3-18-2017
Description:	This class defines the Holdable objects that have weight,
				that the Player is permitted to hold.
***********************************************************/


#include "Holdable.hpp"
#include <iostream>

/**************************************
Description:	Default constructs a Holdable object.
Arguments:		None.
Precondition:	None.
Postcondition:	weight = 0,
				rest are values from default construction of Object.
**************************************/
Holdable::Holdable() :
Object() {
	weight = 5;
	name = "default holdable";
}

/**************************************
Description:	 Custom constructs a Holdable object.
Arguments:		[1] name, [2] description, [3] key, [4] weight
Precondition:	None.
Postcondition:	name = n, description = d, key = k, weight = w
**************************************/
Holdable::Holdable(std::string n, std::string d, std::string k, double w) :
Object(n, d, k) {
	weight = w;
}

//virtual destructor
Holdable::~Holdable(){}

/**************************************
Description:	Returns weight of Holdable object.
Arguments:		None.
Precondition:	None.
Postcondition:	Returns weight.
**************************************/
double Holdable::getWeight(){
	return weight;
}

/**************************************
Description:	Sets weight of Holdable object.
Arguments:		double representing weight.
Precondition:	None.
Postcondition:	weight = w;
**************************************/
void Holdable::setWeight(double w) {
	weight = w;
}

/**************************************
Description:	Debugging function. Logs member variables of
				Holdable object to console.
Arguments:		None.
Precondition:	None.
Postcondition:	Prints member variables to console.
**************************************/
void Holdable::log() {
	Object::log();
	std::cout << "Weight: " << weight << std::endl;
}