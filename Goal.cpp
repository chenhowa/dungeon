/*********************************************************
Class Name:		Goal
Author:			Howard Chen
Last Modified:	3-18-2017
Description:	Goal object that contains key information
				that the Player receives when interacting
				with the Goal.
*********************************************************/

#include "Goal.hpp"
#include <iostream>

/****************************
Description:	Default constructs a Goal object.
Arguments:		None.
Precondition:	None.
Postcondition:	All values set to default.
*****************************/
Goal::Goal() : Permanent() {
	success = "default";
	failure = "default";
	name = "default goal";
	description = "a goal";
}

/****************************
Description:	Custom constructs a Goal object.
Arguments:		[1] name, [2] success, [3] failure
Precondition:	None.
Postcondition:	Values set as shown. The rest are default.
*****************************/
Goal::Goal(std::string n, std::string d, std::string s, std::string f) : Permanent() {
	name = n;
	description = d;
	success = s;
	failure = f;
}

/***********************************
Description:	Allows another Object to interact with THIS Goal.
Arguments:		Object*
Precondition:	None.
Postcondition:	Results of interaction are executed, or an error is printed.
***********************************/
void Goal::interact(Object *o) {
	//If the key does exist in THIS object's interactions map,
	//call the corresponding function.
	//Otherwise, tell the player it failed
	if(interactions.find(o->getKey()) == interactions.end()) {
		std::cout << failure << std::endl;
	}
	else {
		try {
			interactions.at(o->getKey())();
		}
		catch(...) {
			std::cerr << "UNEXPECTED ERROR IN GOAL::INTERACT" << std::endl;
		}
	}
}


/****************************
Description:	Returns success string.
Arguments:		None.
Precondition:	None.
Postcondition:	Returns success string.
*****************************/
std::string Goal::getSuccess(){
	return success;
}

/****************************
Description:	Returns failure string.
Arguments:		None.
Precondition:	None..
Postcondition:	Returns failure string.
*****************************/
std::string Goal::getFailure(){
	return failure;
}

/****************************
Description:	Set success string.
Arguments:		string.
Precondition:	None.
Postcondition:	success = s;
*****************************/
void Goal::setSuccess(std::string s) {
	success = s;
}

/****************************
Description:	Sets failure string.
Arguments:		string.
Precondition:	none.
Postcondition:	failure = f;
*****************************/
void Goal::setFailure(std::string f) {
	failure = f;
}

/****************************
Description:	Debugging function. Logs Goal object's state to console.
Arguments:		None.
Precondition:	None.
Postcondition:	Prints all member variables to console.
*****************************/
void Goal::log() {
	Object::log();
	std::cout << "Success: " << success << '\n';
	std::cout << "Failure: " << failure << '\n';
}