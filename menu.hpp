/******************************************************
Class Name: 	Menu
Author:			Howard Chen
Date:			3/19/2017
Description:	A console menu that can be edited before
					being displayed.
************************************************8******/


#ifndef HC_MENU_HPP
#define HC_MENU_HPP
#include <vector>
#include <string>


class Menu
{
public:
	//Description: Default constructor for a Menu Object.
	//Arguments: none 
	//Returns Menu object
	//Precondition: none.
	//Postcondition: Menu object is created with a default
	//			message.
	Menu();
	
	//Description: Get one of the menu choices.
	//Arguments: number of the choice.
	//Returns a const char* representing the message.
	//Precondition: Menu must have at least one choice.
	//Postcondition: Either the menu choice is returned,
	//			or an error message is returned.
	std::string getChoice(unsigned int num);
	
	//Description: Get the number of choices in the menu.
	//Arguments: none 
	//Returns: number of menu choices.
	//Precondition: Menu must exist.
	//Postcondition: Menu's choice number is returned.
	int getNumChoices();
	
	//Description: Validates a menu choice.
	//Arguments: a number representing the menu choice.
	//Returns boolean: whether or not the menu choice is valid.
	//Precondition: Menu should have at least one choice.
	//Postcondition: Returns true or false.
	bool validate(unsigned int num);
	
	//Description: Adds options to the menu.
	//Arguments: c-string representing the menu choice.
	//Returns nothing.
	//Precondition: None.
	//Postcondition: Menu will have one extra option.
	void  addChoice(std::string s);
	
	
	//Description: Swaps menu option positions.
	//Arguments: option positions that will be swapped.
	//Returns nothing. 
	//Precondition: Menu must have at least two options.
	//Postcondition: Menu options are swapped.
	void swapChoice(unsigned int first, unsigned int second);
	
	//Description: Display the menu options to a user.
	//Arguments: none.
	//Returns nothing. 
	//Precondition: Menu object must have at least one option.
	//Postcondition: Menu will be printed to console.
	void display();
	
	//Description: removes a specified choice from the menu.
	//Arguments: position of the menu choice.
	//Returns nothing.
	//Precondition: Menu must have at least one choice.
	//Postcondition: Menu option is removed.
	void removeChoice(unsigned int num);
	
	/*
	Description:	Returns length of menu.
	Arguments:		None.
	Precondition:	None.
	Postcondition:	Returns length of menu.
	*/
	int length();
	
	/*
	Description:	Clears menu of all choices.
	Arguments:		None.
	Precondition:	None.
	Postcondition:	Menu is cleared of all choices.
	*/
	void clear();
	
protected:
	std::vector<std::string> choice;

};



#endif
