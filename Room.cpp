/*****************************************************************************
Class Name:		Room
Author:			Howard Chen
Last Modified:	3-17-2017
Description:	Room abstract base class. Contains pointers to other Rooms
				for creating a network of rooms.
*****************************************************************************/

#include "Room.hpp"
#include "input.hpp"
#include <iostream>

/*******
Description:	Default constructs a room.
Arguments:		None.
Precondition:	None.
Postcondition:	A room is constructed with no adjacent rooms, a default menu,
				and a default description.
*******/
Room::Room(){
	north = nullptr;
	south = nullptr;
	east = nullptr;
	west = nullptr;
	menu = RoomMenu();
	description = "def room description";
}

/*******
Description:	Custom constructs a room.
Arguments:		string representing a room description.
Precondition:	None.
Postcondition:	A room is constructed with no adjacent rooms, a default menu,
				and description = d;
*******/
Room::Room(std::string d) : Room() {
	description = d;
}

//virtual destructor
Room::~Room(){}


/*******
Description:	Prints objects of the room to console.
Arguments:		None.
Precondition:	None.
Postcondition:	Objects of room are printed to console.
*******/
void Room::printObjects(){
	
	std::cout << "You look around and see the following things: " << '\n';
	for( auto &r : stuff) {
		std::cout << (r.second)->getDescription();
		std::cout << ", ";
	}
	std::cout << std::endl;
}

/*******
Description:	This function runs the RoomMenu so the Player can interact with the Room.
Arguments:		[1] Reference to Room* that Player is currently in.
				[2] Reference to Player*.
Precondition:	Neither argument can be nullptr.
Postcondition:	Menu is updated based on content of Room (and Player), Menu is printed to
					console. User input is obtained and used to execute program response.
*******/
void Room::runMenu(Room* &r, Player* &p) {
	bool exitMenu = false;
	do {
	
		//Display all objects in the room.
		std::cout << "You enter the " << description << ", and see the following: " << '\n';
		for(auto &s : stuff) {
			std::cout << s.second->getDescription() << ", ";
		}
		std::cout << '\n' << std::endl;
		
		//Update menu. This means menu choice may change exitMenu.
		this->updateMenu(r, p, exitMenu);
		
		//Show menu.
		menu.display();
		
		//Get user choice.
		unsigned int exit = menu.length() - 1;
		std::cout << "Enter a menu choice between " << 0 << " and " << exit << ": ";
		unsigned int choice = inputFun::getAnInt(0, exit, std::cin);
		
		std::cout << "\n\n\n" << "***********************************************" << std::endl;
		
		
		//Execute the lambda corresponding to the choice.
		if(actions.find(choice) == actions.end()) {
			std::cerr << "SOMETHING WENT WRONG. CHOICE NOT IN ACTION MAP" << std::endl;
		}
		else {
			try{
				actions.at(choice)();
			}
			catch(...) {
				std::cout << "UNEXPECTED ERROR AT BACKPACK::RUNMENU" << std::endl;
			}
		}
		
		std::cout << "***********************************************" << "\n\n" << std::endl;
		
	}while(exitMenu == false);
}

/*******
Description:	Updates the menu based on the state of the Room and the Player.
Arguments:		[1] Reference to Room* that Player is currently in.
				[2] Reference to Player*
Precondition:	Neither argument can be nullptr
Postcondition:	Menu is updated, with each menu choice corresponding to a lambda that will be executed.
*******/
void Room::updateMenu(Room* &r, Player* &p, bool &flag){
	menu.clear();
	actions.clear();
	
	unsigned int choice = 0;
	
	//Always include choices for the available rooms to go to.
	if(north != nullptr){
		menu.addChoice("Move to " + north->getDescription() );
		actions.insert(std::make_pair(choice,
			[&r, this, &flag]{
				r = this->north;
				flag = true;
				std::cout << "Moving to " << north->getDescription()
						  << "... " << std::endl;
			}
		
		));
		choice++;
	}
	if(south != nullptr){
		menu.addChoice("Move to " + south->getDescription() );
		actions.insert(std::make_pair(choice, 
			[&r, this, &flag]{
				r = this->south;
				flag = true;
				std::cout << "Moving to " << south->getDescription()
						  << "... " << std::endl;
			}
		
		));
		choice++;
	}
	if(east != nullptr){
		menu.addChoice("Move to " + east->getDescription() );
		actions.insert(std::make_pair(choice, 
			[&r, this, &flag]{
				r = this->east;
				flag = true;
				std::cout << "Moving to " << east->getDescription()
						  << "... " << std::endl;
			}
		
		));
		choice++;
	}
	if(west != nullptr){
		menu.addChoice("Move to " + west->getDescription() );
		actions.insert(std::make_pair(choice, 
			[&r, this, &flag]{
				r = this->west;
				flag = true;
				std::cout << "Moving to " << west->getDescription()
						  << "... " << std::endl;
			}
		
		));
		choice++;
	}
	
	//Give options to interact with PERMANANENT objects only!
	//This simplifies things greatly.
	for(auto &s : stuff){
		if( dynamic_cast<Permanent*>(s.second) != nullptr) {
			menu.addChoice("Use " + (p->getEquip())->getName() + " on " + s.first);
			Object* p_obj = s.second;
			actions.insert(std::make_pair(choice, 
				[p_obj, p]{
					p_obj->interact(p->getEquip());
				}
			));
			choice++;
		}
	}
	
	//Give options to pick up the Holdable objects in the Room
	for(auto &s : stuff){
		if( dynamic_cast<Holdable*>(s.second) != nullptr){
			menu.addChoice("Pick up " + s.first);
			Holdable* p_hold = dynamic_cast<Holdable*>(s.second);
			actions.insert(std::make_pair(choice, 
				[p_hold, &p, this]{
					bool success = p->pickup(p_hold);
					
					//If pickup was successful, tell Player,
					//and remove object from the Room.
					if(success){
						stuff.erase(p_hold->getName());
						std::cout << "You took the " << p_hold->getName() << std::endl;
					}
					else{
						//DO NOTHING. Player is already informed it failed.
					}
				}
			));
			
			choice++;
		}
	}
	
	//Give option to view player backpack and interact with that.
	menu.addChoice("View backpack");
	actions.insert(std::make_pair(choice, 
		[&p]{
			std::cout << "Going to backpack..." << '\n';
			std::cout << "**********************************" << "\n\n\n";
			p->viewBackpack();
			std::cout << "Returning from Backpack..." << std::endl;
		}
	));
	choice++;
}

/*******
Description:	Adds object to the Room.
Arguments:		Pointer to an Object.
Precondition:	None.
Postcondition:	stuff has a new entry mapping the Object's name to the Object pointer.
*******/
void Room::addObject(Object *o){
	stuff.insert(std::make_pair(o->getName(), o ));
}

/*******
Description:	Returns address of north room.
Arguments:		None.
Precondition:	None.
Postcondition:	north is returned.
*******/
Room* Room::getNorth(){
	return north;
}

/*******
Description:	Returns address of south room.
Arguments:		None.
Precondition:	None.
Postcondition:	south is returned.
*******/
Room* Room::getSouth(){
	return south;
}

/*******
Description:	Returns address of east room.
Arguments:		None.
Precondition:	None.
Postcondition:	east is returned.
*******/
Room* Room::getEast(){
	return east;
}

/*******
Description:	Returns address of west rom.
Arguments:		None.
Precondition:	None.
Postcondition:	west is returned.
*******/
Room* Room::getWest(){
	return west;
}

/*******
Description:	Returns description of room.
Arguments:		None.
Precondition:	None.
Postcondition:	string description is returned.
*******/
std::string Room::getDescription(){
	return description;
}

/*******
Description:	Sets address of north room.
Arguments:		Room*
Precondition:	None.
Postcondition:	north is set to new address.
*******/
void Room::setNorth(Room* other) {
	north = other;
}

/*******
Description:	Sets address of south room.
Arguments:		Room*
Precondition:	None.
Postcondition:	south is set to new address.
*******/
void Room::setSouth(Room* other){
	south = other;
}

/*******
Description:	Sets address of east room.
Arguments:		Room*
Precondition:	None.
Postcondition:	east is set to new address.
*******/
void Room::setEast(Room* other){
	east = other;
}

/*******
Description:	Sets address of west room.
Arguments:		Room*
Precondition:	None.
Postcondition:	west is set to new address.
*******/
void Room::setWest(Room* other){
	west = other;
}

/*******
Description:	Sets description of room.
Arguments:		string d
Precondition:	None.
Postcondition:	Description is set to d.
*******/
void Room::setDescription(std::string d){
	description = d;
}


/*******
Description:	Debugging function. Logs state of the Room.
Arguments:		None.
Precondition:	None.
Postcondition:	Important member variables are logged to console.
*******/
void Room::log(){
	std::cout << "North: " << north << '\n';
	std::cout << "South: " << south << '\n';
	std::cout << "East: " << east << '\n';
	std::cout << "West: " << west << '\n';
	
	std::cout << "Description: " << description << '\n';
	
	std::cout << "Stuff: ";
	for(auto &r : stuff) {
		std::cout << (r.second)->getName();
		std::cout << ", ";
	}
	std::cout << std::endl;
	std::cout << "Actions: ";
	for(auto &r : actions) {
		std::cout << r.first << ", ";
	}
	std::cout << std::endl;
	menu.display();
}