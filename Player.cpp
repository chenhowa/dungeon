/*****************************************************************************
Class Name:		Player
Author:			Howard Chen
Last Modified:	3-17-2017
Description:	Player class.  Has a backpack and equipment.
*****************************************************************************/

#include "Player.hpp"
#include <iostream>

/*****************************
Description:	Default constructs a Player.
Arguments:		None.
Precondition:	None.
Postcondition:	backpack = Default Backpack.
				nothing = default Usable object.
				equipment = &nothing.
******************************/
Player::Player(){
	backpack = Backpack();
	equipment = &nothing;
}

/*****************************
Description:	Equips a Usable to the Player.
Arguments:		Usable* (address of object to be equipped)
Precondition:	u cannot be nullptr.
Postcondition:	equipment = u.
******************************/
void Player::equip(Usable* u){
	equipment = u;
}

/*****************************
Description:	Unequips a Usable from the Player.
Arguments:		None.
Precondition:	None.
Postcondition:	equipment = &nothing, the default state.
******************************/
void Player::unequip(){
	equipment = &nothing;
}

/*****************************
Description:	Allows user to view Backpack contents and interact
				with the contents.
Arguments:		None.
Precondition:	None.
Postcondition:	backpack.runMenu() is executed.
******************************/
void Player::viewBackpack() {
	backpack.runMenu(equipment);
}

/*****************************
Description:	Returns the address of the User's equipped Object.
Arguments:		None.
Precondition:	None.
Postcondition:	Returns equipment.
******************************/
Usable* Player::getEquip() {
	return equipment;
}

/*****************************
Description:	Adds an object to the Player's backpack.
Arguments:		Holdable* (address of Holdable object to be added).
Precondition:	h should not be nullptr.
Postcondition:	h is added to Player's backpack.
				If successful, returns true;
				If it fails, returns false;
******************************/
bool Player::pickup(Holdable *h){
	return backpack.add(h);
}

/*****************************
Description:	Debugging function. Logs Player's state to console.
Arguments:		None.
Precondition:	None.
Postcondition:	Player's member variables are logged to console.
******************************/
void Player::log(){
	std::cout << "PLAYER: " << std::endl;
	backpack.log();
	std::cout << "equipped: " << equipment->getName() << std::endl;
	//nothing.log();
}