/*****************************************************************************
Class Name:		Backpack
Author:			Howard Chen
Last Modified:	3-17-2017
Description:	Backpack class. Contains Holdable objects and a BPMenu.
				Has a weight limit.
*****************************************************************************/

#include "Backpack.hpp"
#include "Usable.hpp"
#include <iostream>
#include "input.hpp"

/***************************************
Description:	Default constructs a Backpack.
Arguments:		None.
Precondition:	None.
Postcondition:	Member variables are set as follows:
				limit = 200;
				current = 0;
				menu = default BPMenu;
				nothing is a default Usable();
				equipment = &nothing
****************************************/
Backpack::Backpack(){
	limit = 200;
	current = 0;
}

/***************************************
Description:	Custom constructs a Backpack with regard to limit.
Arguments:		double
Precondition:	None.
Postcondition:	Member variables are set as follows.
				limit = l;
				current = 0;
				menu = default BPMenu;
				nothing is a default Usable();
				equipment = &nothing
****************************************/
Backpack::Backpack(double l){
	limit = l;
	current = 0;
}

/***************************************
Description:	If space is available, adds a Holdable Object to the
					Backpack.
Arguments:		Pointer to Holdable.
Precondition:	None.
Postcondition:	If space is still left, adds the Holdable and updates
					the Backpack's current weight. RETURNS true.
				Otherwise prints message, and RETURNS false.
****************************************/
bool Backpack::add(Holdable* h){
	
	if(h->getWeight() + this->current < limit){
		stuff.insert(make_pair(h->getName(), h));
		current += h->getWeight();
		return true;
	}
	else {
		std::cout << "Your backpack is too full to add the "
				  << h->getName() << std::endl;
		return false;
	}
}

/***************************************
Description:	Prints items in Backpack to console.
Arguments:		None.
Precondition:	None.
Postcondition:	For each item in stuf, the item's key
				is printed to console.
****************************************/
void Backpack::view(){
	std::cout << "BACKPACK ITEMS: ";
	for (auto &r : stuff) {
		std::cout << r.first << ", ";
	}
	std::cout << std::endl;
}

/***************************************
Description:	Removes the pair with the given key from the Backpack.
Arguments:		string representing key.
Precondition:	key should be in the map. If not, behavior is undefined.
Postcondition:	Pair with the key is removed from the Backpack.
****************************************/
void Backpack::remove(std::string n){
	if(stuff.find(n) == stuff.end()) {
		std::cout << n << " is not in the backpack" << std::endl;
	}
	else {
		current -= stuff[n]->getWeight();
		stuff.erase(n);
	}
}

/***************************************
Description:	Updates BPMenu based on objects in Backpack and a Usable object.
Arguments:		Usable* representing the Player's currently-equipped item.
Precondition:	Argument is not nullptr.
Postcondition:	Menu is updated, and each menu choice is mapped to a lambda
				that contains the correct instructions for the menu choice.
****************************************/
void Backpack::updateMenu(Usable* &u){
	menu.clear();
	actions.clear();
	unsigned int choice = 0;
	
	//Give menu "examine" choices for each Holdable, and insert
	//the corresponding function for each choice in the menu.
	for(auto &r : stuff){
		menu.addChoice("Examine the " + r.first);
		Holdable *p_hold = r.second;
		actions.insert(std::make_pair(choice,
			[p_hold]{
				std::cout << p_hold->getName() << ": " << p_hold->getDescription()
						  << ", " << p_hold->getWeight() << " kg" << std::endl;
				
			}
		));
		choice++;
	}
	
	//Give menu "drop" chocies for each Holdable (EXCEPT EQUIPPED), and insert the
	//corresponding function for each choice in the menu.
	for(auto &r : stuff) {
		if(r.second != u) {
			menu.addChoice("Drop the " + r.first);
			std::string key = r.first;
			actions.insert(std::make_pair(choice,
				[key, this]{
					this->remove(key);
					std::cout << key << " was dropped" << std::endl;
				}
			));
			choice++;
		}
	}
	
	//Give menu "equip" choices for each Usable object, and insert
	//the corresponding function for each choice in the menu.
	//NO equip choice if already equipped.
	for(auto &r : stuff){
		//IF holdable object is usable, give the choice to equip it.
		if(dynamic_cast<Usable*>(r.second) != nullptr){
			if( *dynamic_cast<Usable*>(r.second) != *u ){
				menu.addChoice("Equip the " + r.first);
				
				Usable *p_use = dynamic_cast<Usable*>(r.second);
				actions.insert(std::make_pair(choice,
					[p_use, &u]{
						u = p_use;
						std::cout << p_use->getName() << " has been equipped" << std::endl;
					}
				
				));
				choice++;
			}
		}
	}
	
	//Give menu the option to unequip the current usable object, if it is not default.
	if(*u != this->nothing) {
		menu.addChoice("Unequip the " + u->getName());
		actions.insert(std::make_pair(choice,
			[&u, this]{
				std::cout << u->getName() << " was unequipped" << std::endl;
				u = &nothing;
			}
		));
		choice++;
	}
	
	//Last option is always to exit the menu.
	menu.addChoice("Exit the Backpack");
	choice++;
}

/***************************************
Description:	Runs the Backpack menu by printing contents of Backpack, showing menu, getting
				Player choice, and executing that choice.
Arguments:		Usable* representing Player's equipped Usable object.
Precondition:	Argument cannot be nullptr.
Postcondition:	Menu is run and executed.
****************************************/
void Backpack::runMenu(Usable* &u) {
	bool exitMenu = false;
	do{
		//Show names of all items in Backpack, and current weight.
		std::cout << "You examine your storage chassis, and see the following: " << "\n\n\t";
		for(auto &r : stuff){
			std::cout << r.first << ", ";
		}
		std::cout << "\n\n";
		std::cout << "Current weight: " << current << '\n';
		std::cout << "Remaining: " << limit - current << '\n';
		std::cout << "Weight limit: " << limit << '\n' << '\n';
		
		std::cout << "Currently equipped: " << u->getName() << "\n\n";
		
		//Update the menu to reflect the current state of the Backpack.
		this->updateMenu(u);
		
		//Show the menu choices.
		menu.display();
		
		//Get and execute the menu choices, or do nothing if user chooses to exit.
		//MENU WILL RUN AND UPDATE REPEATEDLY UNTIL USER CHOOSES TO EXIT.
		unsigned int exit = menu.length() - 1;
		std::cout << "Enter a menu choice between " << 0 << " and " << exit << ": ";
		unsigned int choice = inputFun::getAnInt(0, exit, std::cin);
		
		std::cout << "\n\n" << "********************************************" << std::endl;
		
		//If choice is to exit, set exit flag. Otherwise, execute the lambda corresponding to the choice.
		if(choice == exit) {
			exitMenu = true;
		}
		else {
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
		}
		std::cout << "********************************************";
		std::cout << "\n\n" << std::endl;
		
	} while(exitMenu == false);
}

/***************************************
Description:	Debugging function that logs Backpack member variables
				to console.
Arguments:		None.
Precondition:	None.
Postcondition:	Menu is printed to console. Objects in
				Backpack are printed to console.
****************************************/
void Backpack::log(){
	std::cout << "Limit: " << limit << '\n';
	std::cout << "Current: " << current << '\n';
	this->view();
	std::cout << "actions: ";
	for( auto &r : actions){
		std::cout << r.first << ", ";
	}
	std::cout << std::endl;
	menu.display();
}
	