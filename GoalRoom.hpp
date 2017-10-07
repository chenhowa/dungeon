/**********************************************************
Class Name:		GoalRoom
Author:			Howard Chen
Last Modified:	3-20-2017
Description:	Room that is intended to only contain Goal objects.
				Player can visit this room to complete goals using
				the appropriate objects.
**********************************************************/


#ifndef HC_GOALROOM_HPP
#define HC_GOALROOM_HPP

#include "Room.hpp"
#include "Goal.hpp"
#include <string>

class GoalRoom : public Room {
public:
	/************************************
	See GoalRoom.cpp for documentation
	*************************************/
	GoalRoom();								//tested.
	GoalRoom(std::string);					//tested.
	
	virtual void special(Object *) override;	//tested.

private:
	
};

#endif