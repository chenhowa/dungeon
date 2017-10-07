/*****************************************************************************
Class Name:		Object
Author:			Howard Chen
Last Modified:	3-17-2017
Description:	Object class. Can interact with other Objects, has description,
				name, and key.
*****************************************************************************/

//TESTED. THIS CLASS WORKS!


#ifndef HC_OBJECT_HPP
#define HC_OBJECT_HPP

#include <string>
#include <map>
#include <functional>

class Object {
public:
	/**************************************
	See Object.cpp for documentation
	****************************************/
	friend bool operator==(const Object &lhs, const Object &rhs);
	friend bool operator!=(const Object &lhs, const Object &rhs);
	
	
	
	Object();												//tested.
	Object(std::string n, std::string d, std::string k); //tested
	virtual ~Object();											//tested.
	
	virtual void interact(Object*);		//tested with lambdas.
	void addInteraction(std::pair< std::string,std::function<void ()> > p); //tested with lambdas.
	
	std::string getDescription();		//Getters work.
	std::string getName();
	std::string getKey();
	
	void setDescription(std::string s); //All setters are tested.
	void setName(std::string s);
	void setKey(std::string s);

	virtual void log();				//tested


protected:
	std::string name;
	std::string description;
	std::string key;
	std::map<std::string, std::function<void ()>> interactions;
	
};

bool operator==(const Object &lhs, const Object &rhs);
bool operator!=(const Object &lhs, const Object &rhs);




#endif