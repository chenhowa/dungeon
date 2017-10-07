/******************************************************
Class Name: 	Menu
Author:			Howard Chen
Date:			3/19/2017
Description:	A console menu that can be edited before
					being displayed.
************************************************8******/

#include "menu.hpp"
#include <iostream>


//Description: Default constructor for a Menu Object.
//Arguments: none 
//Returns Menu object
//Precondition: none.
//Postcondition: Menu object is created completely empty.
Menu::Menu()
{
}

//Description: Get one of the menu choices.
//Arguments: number of the choice.
//Returns a const char* representing the message.
//Precondition: Menu must have at least one choice.
//Postcondition: Either the menu choice is returned,
//			or an error message is returned.
std::string Menu::getChoice(unsigned int num)
{
	if(num < choice.size())
		return choice[num];
	else
		return "ERROR: CHOICE NUMBER IS OUT OF BOUNDS";
}

//Description: Get the number of choices in the menu.
//Arguments: none 
//Returns: number of menu choices.
//Precondition: Menu must exist.
//Postcondition: Menu's choice number is returned.
int Menu::getNumChoices()
{
	return choice.size();
}

//Description: Validates a menu choice.
//Arguments: a number representing the menu choice.
//Returns boolean: whether or not the menu choice is valid.
//Precondition: Menu should have at least one choice.
//Postcondition: Returns true or false.
bool Menu::validate(unsigned int num)
{
	if(num < choice.size())
		return true;
	else
		return false;
}

//Description: Adds options to the menu.
//Arguments: c-string representing the menu choice.
//Returns nothing.
//Precondition: None.
//Postcondition: Menu will have one extra option.
void  Menu::addChoice(std::string option)
{
	choice.push_back(option);
}


//Description: Swaps menu option positions.
//Arguments: option positions that will be swapped.
//Returns nothing. 
//Precondition: Menu must have at least two options.
//Postcondition: Menu options are swapped.
void Menu::swapChoice(unsigned int first, unsigned int second)
{	
	//Check if swap positions are valid choices.
	unsigned int bound = choice.size();
	
	//If they are, swap them. Otherwise, print an
	//error message.
	if(first < bound && second < bound)
	{
		std::string temp = choice[first];
		choice[first] = choice[second];
		choice[second] = temp;
	}
	else
		std::cout << "ERROR: OUT OF BOUNDS" << std::endl;
}

//Description: Display the menu options to a user.
//Arguments: none.
//Returns nothing. 
//Precondition: Menu object must have at least one option.
//Postcondition: Menu will be printed to console.
void Menu::display()
{
	std::cout << "Menu Options" << std::endl;
	for(unsigned int i = 0; i < choice.size(); ++i)
	{	
		std::cout << i << '\t' << choice[i] << std::endl;
	}
}

//Description: removes a specified choice from the menu.
//Arguments: position of the menu choice.
//Returns nothing.
//Precondition: Menu must have at least one choice.
//Postcondition: Menu option is removed.
void Menu::removeChoice(unsigned int num)
{
	//Print an error message if menu is empty.
	if(choice.empty())
		std::cout << "ERROR: Empty Menu!" << std::endl;
	//Remove option if it is valid, otherwise print an
	//error message.
	else if (num < choice.size())
	{
		unsigned int last = choice.size() - 1;
		std::string tmp = choice[num];
		choice[num] = choice[last];
		choice[last] = tmp;
		choice.pop_back();
	}
	else
		std::cout << "ERROR: OUT OF BOUNDS" << std::endl;
}

/*
Description:	Returns length of menu.
Arguments:		None.
Precondition:	None.
Postcondition:	Returns length of menu.
*/
int Menu::length()
{
	return this->choice.size();
}

/*
Description:	Clears menu of all choices.
Arguments:		None.
Precondition:	None.
Postcondition:	Menu is cleared of all choices.
*/
void Menu::clear(){
	choice.clear();
}