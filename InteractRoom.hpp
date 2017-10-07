/***************************************************
Class Name:		InteractRoom
Author:			Howard Chen
Last Modified:	3-20-2017
Description:	Derived from Room, an InteractRoom can only
				contain Permanent* pointers in its map.
				So the Player can only interact with these items.
****************************************************/


#ifndef HC_INTERACTROOM_HPP
#define HC_INTERACTROOM_HPP

#include "Permanent.hpp"
#include "Room.hpp"
#include <string>

class InteractRoom : public Room {
public:
	/*****************************************
	See InteractRoom.cpp for documentation
	******************************************/
	InteractRoom();							//tested.
	InteractRoom(std::string d);			//tested.
	
	virtual void special(Object *o) override; //tested


private:
	
};

#endif