/*****************************************************************************
Class Name:		Object
Author:			Howard Chen
Last Modified:	3-17-2017
Description:	Object class. Can interact with Usable* objects, has description,
				name, and key.
*****************************************************************************/

#include "Object.hpp"
#include <iostream>

/***********************************
Description:	Default constructs an object.
Arguments:		None.
Precondition:	None.
Postcondition:	Each member variable is set to "object"
***********************************/
Object::Object() {
	name = "default object";
	description = "object";
	key = "object";	
}

/***********************************
Description:	Custom constructs an object.
Arguments:		[1] name, [2] description, [3] key
Precondition:	None.
Postcondition:	name = n;
				description = d;
				key = k;
***********************************/
Object::Object(std::string n, std::string d, std::string k){
	name = n;
	description = d;
	key = k;
}

//virtual destructor
Object::~Object(){}

/***********************************
Description:	Allows another Object to interact with THIS object.
Arguments:		Object*
Precondition:	None.
Postcondition:	Results of interaction are executed, or an error is printed.
				If executed, the argument object will be set to have THIS object's
				key.
***********************************/	
void Object::interact(Object* u) {
	
	//If the key does exist in THIS object's interactions map,
	//call the corresponding function.
	//Otherwise, tell the player it did nothing.
	if(interactions.find(u->getKey()) == interactions.end()) {
		std::cout << "Using the " << u->getName() << " on the " << this->name
				  << " didn't do anything." << std::endl;
	}
	else {
		try {
			interactions.at(u->getKey())();
			u->setKey(this->key);
		}
		catch(...) {
			std::cerr << "UNEXPECTED ERROR IN OBJECT::INTERACT" << std::endl;
		}
	}
	
	
}

/***********************************
Description:	Function that adds interactions to an Object.
Arguments:		pair that maps a string to a callable object that has
				no arguments and returns nothing.
Precondition:	None.
Postcondition:	Adds the specified pair to the interactions map.
***********************************/
void Object::addInteraction(std::pair<std::string,std::function<void ()> > p){
	interactions.insert(p);
}

/***********************************
Description:	Returns object's description string.
Arguments:		None.
Precondition:	None.
Postcondition:	Returns description string.
***********************************/
std::string Object::getDescription(){
	return description;
	
}

/***********************************
Description:	Returns object's name string.
Arguments:		None.
Precondition:	None.
Postcondition:	Returns name string.
***********************************/
std::string Object::getName() {
	return name;
}

/***********************************
Description:	Returns object's key string.
Arguments:		None.
Precondition:	None.
Postcondition:	Returns key string.
***********************************/
std::string Object::getKey(){
	
	return key;
}

/***********************************
Description:	Sets object's description string.
Arguments:		string
Precondition:	None.
Postcondition:	description = s;
***********************************/
void Object::setDescription(std::string s){
	description = s;
}

/***********************************
Description:	Sets object's name string.
Arguments:		string.
Precondition:	None.
Postcondition:	name = s;
***********************************/
void Object::setName(std::string s){
	name = s;
}

/***********************************
Description:	Sets object's key string.
Arguments:		string
Precondition:	None.
Postcondition:	key = s;
***********************************/
void Object::setKey(std::string s){
	key = s;
}

/***********************************
Description:	Debugging function that logs Object state
				to the console.
Arguments:		None.
Precondition:	None.
Postcondition:	Logs name, description, and key to console.
***********************************/
void Object::log(){
	std::cout << "Name: " << name << '\n';
	std::cout << "Description: " << description << '\n';
	std::cout << "Key: " << key << std::endl;
}

/********************************
Description:	Returns whether two objects are equal.
Arguments:		Object, Object,
Precondition:	name, key, and description of both Objects must be valid.
Postcondition:	Return true if name, key, and description are all equal.
				If even one pair is not equal, return false.
********************************/
bool operator==(const Object &lhs, const Object &rhs){
	
	return (lhs.name == rhs.name) &&
			(lhs.key == rhs.key) &&
			(lhs.description == rhs.description);
}

/********************************
Description:	Returns whether two objects are NOT equal.
Arguments:		Object, Object.
Precondition:	name, key, and description of both objects must be valid.
Postcondition: 	Return false if name, key, and description are all equal.
				If even one pair is not equal, return true.
********************************/
bool operator!=(const Object &lhs, const Object &rhs){
	return !(lhs == rhs);
}