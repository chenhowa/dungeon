/*****************************************************************************
Class Name:		Player
Author:			Howard Chen
Last Modified:	3-17-2017
Description:	Player class. Has a backpack and equipment.
*****************************************************************************/

#ifndef HC_PLAYER_HPP
#define HC_PLAYER_HPP

#include "Backpack.hpp"
#include "Usable.hpp"
#include "Holdable.hpp"

class Player {
public:
	/************************************
	See Player.cpp for documentation
	***********************************/
	Player();					//tested.
	
	void equip(Usable* u);		//tested.
	void unequip();				//tested.
	void viewBackpack();		//TESTED
	bool pickup(Holdable *h);	//tested.
	
	Usable* getEquip();			//works.
	
	
	void log();					//tested.


private:
	Backpack backpack;
	Usable *equipment;
	Usable nothing;
};




#endif