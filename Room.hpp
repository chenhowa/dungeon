/*****************************************************************************
Class Name:		Room
Author:			Howard Chen
Last Modified:	3-17-2017
Description:	Room abstract base class. Contains pointers to other Rooms
				for creating a network of rooms.
*****************************************************************************/

//TESTED


#ifndef HC_ROOM_HPP
#define HC_ROOM_HPP
#include <string>
#include <map> 
#include "RoomMenu.hpp"
#include "Object.hpp"
#include "Player.hpp"
#include "Permanent.hpp"
#include <functional>
#include <map>

class Room {
public:

	/**********************************************************************************
	See Room.cpp for documentation
	*********************************************************************************/
	Room(); //tested
	Room(std::string d);
	virtual ~Room();
	
	//I have no idea how to implement these, so I'm going to delete them. Rooms cannot be copied or assigned.
	Room(const Room& other) = delete;
	Room& operator=(const Room& other) = delete;
	
	virtual void special(Object *o)=0;
	
	virtual void printObjects();			//tested.
	void runMenu(Room* &r, Player* &p);		//tested
	void updateMenu(Room* &r, Player* &p, bool &flag);		//tested
	
	Room* getNorth();				//get functions work.
	Room* getSouth();
	Room* getEast();
	Room* getWest();
	std::string getDescription();
	
	void setNorth(Room* other);		//set functions work.
	void setSouth(Room* other);
	void setEast(Room* other);
	void setWest(Room* other);
	void setDescription(std::string d);
	
	void log();				//tested.
	
protected:
	void addObject(Object *o);					//tested
	std::string description;

private:
	Room* north;
	Room* south;
	Room* east;
	Room* west;
	RoomMenu menu;
	std::map<std::string, Object*> stuff;
	std::map<unsigned int, std::function<void ()>> actions;
	
	
	//Since I'll be allocating the Objects
	//in the heap, the room will not take care of storing the pointers
	//FOR LATER memory deallocation, the game will.
	
};


#endif