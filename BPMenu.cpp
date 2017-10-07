/************************************************************************
Class Name:		BPMenu
Author:			Howard Chen
Last Modified:	3-17-2017
Description:	Menu for the Backpack class. Not really needed, but it's
				work to eliminate it now. I'd rather not introduce bugs.
************************************************************************/

#include "BPMenu.hpp"

/**************************
Description:	Default constructs a BPMenu, which is basically a Menu.
Arguments:		None.
Precondition:	None.
Postcondition:	BPMenu is constructed.
**************************/
BPMenu::BPMenu() :
Menu() {

}

/**************************
Description:	Debugging function. Logs BPMenu choices to console.
Arguments:		None.
Precondition:	None.
Postcondition:	Prints BPMenu choices to console.
**************************/
void BPMenu::log(){

	this->display();
}