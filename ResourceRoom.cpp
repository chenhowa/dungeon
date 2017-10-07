/****************************************************
Class Name:		ResourceRoom
Author:			Howard Chen
Last Modified:	3-20-2017
Description:	Derived from Room, the ResourceRoom is forced
				to contain only Holdable pointers, so the
				Player is able to pick up objects only from
				ResourceRooms.
*****************************************************/

#include "ResourceRoom.hpp"

/*****************************************
Description:	Default constructs a ResourceRoom.
Arguments:		None.
Precondition:	None.
Postcondition:	In state, the new ResourceRoom is identical
				to a default Room.
*****************************************/
ResourceRoom::ResourceRoom() : Room(){
	description = "Resource Room";
}

/*****************************************
Description:	Custom constructs a ResourceRoom.
Arguments:		None.
Precondition:	None.
Postcondition:	ResourceRoom uses Room custom
				constructor.
*****************************************/
ResourceRoom::ResourceRoom(std::string d):Room(d){
}

/*****************************************
Description:	Adds Object pointers to ResourceRoom'sb_type
				map.
Arguments:		Object pointer.
Precondition:	None.
Postcondition:	If o is also type Holdable*, then
				add it to the map. Otherwise do nothing.
*****************************************/
void ResourceRoom::special(Object* o){
	if(dynamic_cast<Holdable*>(o) != nullptr){
		this->addObject(o);
	}
}