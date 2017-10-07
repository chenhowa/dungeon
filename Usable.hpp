/***************************************************************************
Class Name:		Usable
Author:			Howard Chen
Last Modified:	3-18-2017
Description:	Usable object, derived from Object. The main difference is that
				it contains two additional strings, action and result,
				that are printed to the console to tell the user what happens
				when an Object interacts with the Usable.
***************************************************************************/

#ifndef HC_USABLE_HPP
#define HC_USABLE_HPP

#include "Holdable.hpp"
#include <string>

class Usable : public Holdable {
public:
	/**********************************************
	See Usable.cpp for documentation
	***********************************************/
	Usable();				//tested
	Usable(std::string n, std::string d, std::string k, double w, std::string a, std::string r); 	//tested.
	
	std::string getAction();		//getters tested.
	std::string getResult();
	
	void setAction(std::string a);	//tested
	void setResult(std::string r);	//tested

	virtual void log();				//tested
private:
	std::string action;
	std::string result;
};



#endif