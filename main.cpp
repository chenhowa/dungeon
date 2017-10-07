/***********************************************************
File Name:		MAIN GAME
Author:			Howard Chen
Last Modified:	3-21-2017
Description:	Allows for running and testing of the Final Project files.

How to run:		main objects 	- test the object class
				main menus	 	- test the menu classes.
				main backpack	- test the backpack class.
				main player		- test the player class.
				main rooms		- test the room classes.
				main			- run the Game.
***********************************************************/

#include "Game.hpp"
#include "driver.hpp"

#include <iostream>
#include <functional>
#include <string.h>


int main(int argc, char** argv)
{
	if (argc > 1 && strcmp(argv[1], "objects") == 0)
	{	//Test the object classes.
		driver::objectTest();
	}
	else if(argc > 1 && strcmp(argv[1], "menus") == 0) {
		driver::menuTest();
	}
	else if(argc > 1 && strcmp(argv[1], "backpack") == 0) {
		driver::backpackTest();
	}
	else if(argc > 1 && strcmp(argv[1], "player") == 0) {
		driver::playerTest();
	}
	else if(argc > 1 && strcmp(argv[1], "rooms") == 0) {
		driver::roomTest();
	}
	else {
		Game game;
		game.play();
	}
	
	return 0;
}
