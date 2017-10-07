/*********************************************************
Class Name:		Goal
Author:			Howard Chen
Last Modified:	3-18-2017
Description:	Goal object that contains key information
				that the Player receives when interacting
				with the Goal.
*********************************************************/


#ifndef HC_GOAL_HPP
#define HC_GOAL_HPP

#include "Permanent.hpp"
#include <string>

class Goal : public Permanent {
public:
	/******************************************
	See Goal.cpp for documentation
	********************************************/
	Goal();					//tested
	Goal(std::string n, std::string d, std::string s, std::string f); //tested.
	
	virtual void interact(Object *o) override;
	
	std::string getSuccess();				//tested
	std::string getFailure();
	
	void setSuccess(std::string s);			//tested.
	void setFailure(std::string f);

	virtual void log() override;

private:
	std::string success;
	std::string failure;
	
	
};



#endif