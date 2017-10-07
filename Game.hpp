/************************************************************************
Class Name:		Game
Author:			Howard Chen
Last Modified:	3-26-2017
Description:	Overall Game class that contains a RoomGraph, Player,
				and methods for playing the game.
************************************************************************/


#ifndef HC_GAME_HPP
#define HC_GAME_HPP

#include "Object.hpp"
#include "Holdable.hpp"
#include "Usable.hpp"
#include "Goal.hpp"
#include "Permanent.hpp"
#include "BPMenu.hpp"
#include "RoomMenu.hpp"
#include "Backpack.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "GoalRoom.hpp"
#include "ResourceRoom.hpp"
#include "InteractRoom.hpp"

#include <functional>
#include <list>

class Game {
public:
	/*************************************
	Description:	Default constructs a Game.
	Arguments:		None.
	Precondition:	None.
	Postcondition:	Game is constructed in line
					with the Game's theme.
	*************************************/
	Game();
	
	/*************************************
	Description:	Game destructor.
	Arguments:		None.
	Precondition:	Game object should be default-constructed.
	Postcondition:	Deallocates all memory allocated in the
					default constructor.
	*************************************/
	~Game();
	
	/*************************************
	Description:	Plays the game.
	Arguments:		None.
	Precondition:	Game object should be default-constructed.
	Postcondition:	Game launches and does not exit until either
					the Game is won or the Game is lost.
	*************************************/
	void play();
	
	/*************************************
	Description:	Debugging function. Logs Game state to console.
	Arguments:		None.
	Precondition:	None.
	Postcondition:	Logs Game's member variables to console.
	*************************************/
	void log();
	

private:
	Player player;
	Room* currentRoom;
	int maxSteps;
	int curSteps;
	std::list<Object*> objects;
	std::list<Goal*> goals;
	std::list<Room*> rooms;
	

	
	
	
};




#endif