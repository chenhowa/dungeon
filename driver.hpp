/**********************************************
File name:		Driver Functions.
Author:			Howard Chen
Last Modified:	3-20-2017
Description:	Collection of test functions for the classes
				in the final project of CS 162.
**********************************************/


#ifndef HC_DRIVER_HPP
#define HC_DRIVER_HPP

#include "Object.hpp"
#include "Holdable.hpp"
#include "Usable.hpp"
#include "Goal.hpp"
#include "Permanent.hpp"
#include "BPMenu.hpp"
#include "RoomMenu.hpp"
#include "Backpack.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "GoalRoom.hpp"
#include "ResourceRoom.hpp"
#include "InteractRoom.hpp"

#include <iostream>
#include <functional>


struct driver{
	//test the object classes.
	static void objectTest();
	
	//test the menu classes.
	static void menuTest();
	
	//test the backpack class.
	static void backpackTest();
	
	//test the player class.
	static void playerTest();
	
	//tes the room classes.
	static void roomTest();
};



#endif