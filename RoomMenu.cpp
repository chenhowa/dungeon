/*****************************************************************************
Class Name:		RoomMenu
Author:			Howard Chen
Last Modified:	3-17-2017
Description:	A menu for a Room object. Not a very important class, as it
				turns out. Could be eliminated but I don't want to spend the time.
*****************************************************************************/

#include "RoomMenu.hpp"

/******************************
Description:	Default constructs a RoomMenu.
Arguments:		None.
Precondition:	None.
Postcondition:	Default RoomMenu is obtained. Essentially a menu.
******************************/
RoomMenu::RoomMenu() :
Menu() {
	
}

/******************************
Description:	For debugging. Logs the RoomMenu to console.
Arguments:		None.
Precondition:	None.
Postcondition:	Prints menu options to console.
******************************/
void RoomMenu::log() { 
	this->display();
}