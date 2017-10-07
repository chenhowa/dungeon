/***********************************************************
Class Name:		Holdable
Author:			Howard Chen
Last Modified:	3-18-2017
Description:	This class defines the Holdable objects that have weight,
				that the Player is permitted to hold.
***********************************************************/

#ifndef HC_HOLDABLE_HPP
#define HC_HOLDABLE_HPP

#include "Object.hpp"

class Holdable : public Object {
public:
	/******************************************
	See Holdable.cpp for documentation
	******************************************/
	Holdable();					//tested 
	Holdable(std::string n, std::string d, std::string k, double w); //tested.
	virtual ~Holdable();
	
	double getWeight();				//works.
	
	void setWeight(double w);		//works.
	
	virtual void log();				//works.


private:
	double weight;
	
	
};




#endif