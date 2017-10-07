/***************************************************************************
Class Name:		Usable
Author:			Howard Chen
Last Modified:	3-18-2017
Description:	Usable object, derived from Object. The main difference is that
				it contains two additional strings, action and result,
				that are printed to the console to tell the user what happens
				when an Object interacts with the Usable.
***************************************************************************/

#include "Usable.hpp"
#include <iostream>

/************************************************
Description: 	Default constructs a Usable object
Arguments:		None.
Precondition:	None.
Postcondition:	Default values for member variables, as shown.
************************************************/
Usable::Usable() : Holdable() {
	action = "Your robot arms work hard at it!";
	description = "default usable";
	result = "You feel a little less energy in your battery";
	name = "robot arms";
	key = "robot";
	
}

/************************************************
Description:	Custom constructs a Usable object.
Arguments:		[1] name, [2] description, [3] key,
				[4] weight, [5] action, [6] result
Precondition:	None.
Postcondition:	Each of the Usable object's member variables
				is set to the value of the corresponding
				argument.
************************************************/
Usable::Usable(std::string n, std::string d, std::string k, double w, std::string a, std::string r) :
Holdable(n,d,k, w) {
	action = a;
	result = r;
}

/************************************************
Description:	Returns the action string.
Arguments:		None.
Precondition:	None.
Postcondition:	Returns action string.
************************************************/
std::string Usable::getAction(){
	return action;
}

/************************************************
Description:	Returns the result string.
Arguments:		None.
Precondition:	None.
Postcondition:	Returns the result string.
************************************************/
std::string Usable::getResult(){
	return result;
}

/************************************************
Description:	Sets the action string.
Arguments:		string.
Precondition:	None.
Postcondition:	action = a;
************************************************/
void Usable::setAction(std::string a){
	action = a;
}

/************************************************
Description:	Sets the result string.
Arguments:		string.
Precondition:	None.
Postcondition:	result = r;
************************************************/
void Usable::setResult(std::string r){
	result = r;
}

/************************************************
Description:	Debugging function. Logs member variables to console.
Arguments:		None.
Precondition:	None.
Postcondition:	Logs all member variables to console.
************************************************/
void Usable::log() {
	Holdable::log();
	std::cout << "Action: " << action << '\n';
	std::cout << "Result: " << result << '\n';
}