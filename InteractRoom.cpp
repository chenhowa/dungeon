/***************************************************
Class Name:		InteractRoom
Author:			Howard Chen
Last Modified:	3-20-2017
Description:	Derived from Room, an InteractRoom can only
				contain Permanent* pointers in its map.
				So the Player can only interact with these items.
****************************************************/

#include "InteractRoom.hpp"

/************************************************
Description:	Default constructs an InteractRoom.
Arguments:		None.
Precondition:	None.
Postcondition:	InteractRoom has same state as default Room.
************************************************/
InteractRoom::InteractRoom() : Room(){
	this->description = "Interact Room";
}

/************************************************
Description:	Custom constructs an InteractRoom.
Arguments:		[1] description.
Precondition:	None.
Postcondition:	InteractRoom uses custom Room constructor.
************************************************/
InteractRoom::InteractRoom(std::string d):
Room(d){
}

/************************************************
Description:	Adds Object pointers to the InteractRoom's map.
Arguments:		Object pointer.
Precondition:	None.
Postcondition:	If o is also type Permanent*, then
				add it to the map. Otherwise do nothing.
************************************************/
void InteractRoom::special(Object *o){
	if(dynamic_cast<Permanent*>(o) != nullptr) {
		this->addObject(o);
	}
}