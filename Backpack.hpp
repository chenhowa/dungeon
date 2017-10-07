/*****************************************************************************
Class Name:		Backpack
Author:			Howard Chen
Last Modified:	3-17-2017
Description:	Backpack class. Contains Holdable objects and a BPMenu.
				Has a weight limit.
*****************************************************************************/

//TESTED.


#ifndef HC_BACKPACK_HPP
#define HC_BACKPACK_HPP

#include "BPMenu.hpp"
#include "Holdable.hpp"
#include "Usable.hpp"
#include <map>
#include <functional>

class Backpack {
public:
	/************************************
	See Backpack.cpp for documentation
	*************************************/
	Backpack();				//tested
	Backpack(double l);		//tested.
	
	bool add(Holdable* h);	//tested
	void view();			//tested.
	void remove(std::string n);		//tested
	void runMenu(Usable* &u);		//tested.
	void updateMenu(Usable* &u);	//tested.
	
	
	void log();					//tested.


private:
	std::map<std::string, Holdable*> stuff;
	double limit;
	double current;
	BPMenu menu;
	std::map<unsigned int, std::function<void ()>> actions;
	Usable nothing;
	
	
};



#endif