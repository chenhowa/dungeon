/**********************************************************
Class Name:		GoalRoom
Author:			Howard Chen
Last Modified:	3-20-2017
Description:	Room that is intended to only contain Goal objects.
				Player can visit this room to complete goals using
				the appropriate objects.
**********************************************************/


#include "GoalRoom.hpp"

/**************************************************
Description:	Default constructs a goal room.
Arguments:		None.
Precondition:	None.
Postcondition:	Default constructs a GoalRoom that is
				identitcal to a default Room, but the
				description is set to "goal room"
**************************************************/
GoalRoom::GoalRoom() :
Room(){
	this->description = "goal room";
}

/**************************************************
Description:	Custom constructs a GoalRoom.
Arguments:		[1] description.
Precondition:	None.
Postcondition:	description = d, otherwise GoalRoom
				is exactly like a default Room.
**************************************************/
GoalRoom::GoalRoom(std::string d) :
Room(d) {
}

/**************************************************
Description:	This function adds Object pointers to
				the GoalRoom's map. 
Arguments:		Object*
Precondition:	None.
Postcondition:	If o is also a Goal* pointer, then add
				it to the map. Otherwise, do nothing.
**************************************************/
void GoalRoom::special(Object *o){
	if(dynamic_cast<Goal*>(o) != nullptr) {
		this->addObject(o);
	}
}
