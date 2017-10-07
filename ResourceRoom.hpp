/****************************************************
Class Name:		ResourceRoom
Author:			Howard Chen
Last Modified:	3-20-2017
Description:	Derived from Room, the ResourceRoom is forced
				to contain only Holdable pointers, so the
				Player is able to pick up objects only from
				ResourceRooms.
*****************************************************/




#ifndef HC_RESOURCEROOM_HPP
#define HC_RESOURCEROOM_HPP

#include "Room.hpp"
#include "Holdable.hpp"
#include <string>

class ResourceRoom : public Room {
public:
	/***************************************************
	See ResourceRoom.cpp for documentation
	***************************************************/
	ResourceRoom();					//tested
	ResourceRoom(std::string d);		//tested
	
	virtual void special(Object* o) override;	//tested

private:


};

#endif