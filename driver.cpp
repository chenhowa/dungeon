/**********************************************
File name:		Driver Functions.
Author:			Howard Chen
Last Modified:	3-20-2017
Description:	Collection of test functions for the classes
				in the final project of CS 162.
**********************************************/

#include "driver.hpp"

/*******************************************************
See driver.hpp for documentation
*********************************************************/


void driver::objectTest(){
	///////////// Object /////////////////////////
	Object def;
	def.log();
	std::cout << std::endl;
	
	Object cus("Bear", "brown", "danger");
	cus.log();
	std::cout << std::endl;
	
	cus.addInteraction(std::make_pair("danger",
		[&cus, &def] {def.setKey("new"); def.log();  }
	));
	
		//test equality operators.
	Object def2;
	if(def == def2){
		std::cout << "Default objects were equal" << std::endl;
	}
	else {
		std::cout << "Default objects WERE NOT equal" << std::endl;
	}
	if(def != cus){
		std::cout << "Different objects were not equal " << std::endl;
	}
	else {
		std::cout << "Different objects WERE EQUAL!!" << std::endl;
	}
	std::cout << '\n';
	
	cus.interact(&cus);
	cus.interact(&def);
	std::cout << std::endl;
	
	//////////// Holdable ///////////////////////
	Holdable hold;
	hold.log();
	std::cout << std::endl;
	Holdable cus_hold("cup", "round", "liquid", 15);
	cus_hold.log();
	std::cout << std::endl;
	
	
	/////////// Usable /////////////////////////
	Usable use;
	use.log();
	std::cout << std::endl;
	Usable cus_use("sword", "sharp", "weapon", 20, "Slash!", "Cut!" );
	cus_use.log();
	std::cout << std::endl;
	
	cus.addInteraction(std::make_pair("weapon",
		[&cus, &cus_use] {
			cus.setDescription("hurt bear");
			cus_use.setKey("broken");
			cus_use.setDescription("broken but fixable");
		}
	));
	cus.interact(&cus_use);
	
	cus.log();
	std::cout << std::endl;
	
	cus_use.log();
	std::cout << std::endl;
	
	////////// Goal /////////////////////
	Goal goal;
	goal.log();
	std::cout << std::endl; 
	Goal cus_goal(	
		"defeat the bear",
		"find the den of the bear and kill it",
		"Congratulations, you killed the bear!",
		"The bear killed you!"
	);
	cus_goal.log();
	std::cout << std::endl;
}

void driver::menuTest(){
	///////////////////   BPMenu //////////////////
	BPMenu bp;
	bp.log();
	std::cout << std::endl;
	
	bp.addChoice("Hi");
	bp.addChoice("Bye");
	
	bp.log();
	std::cout << std::endl;
	
	////////////////// RoomMenu //////////////////
	RoomMenu rm;
	rm.log();
	std::cout << std::endl;
	
	rm.addChoice("Enter");
	rm.addChoice("Leave");
	
	rm.log();
	std::cout << std::endl;
}

void driver::backpackTest(){
	Backpack bp;
	bp.log();
	std::cout << std::endl;
	
	Backpack cus_bp(100);
	cus_bp.log();
	std::cout << std::endl;
	
	Holdable h;
	Usable use;
	Usable cus_use(
		"key",
		"brass and brown key",
		"unlock",
		250,
		"UNLOCK",
		"UNLOCKED"
	);
	cus_bp.add(&h);
	cus_bp.add(&use);
	cus_bp.add(&cus_use);
	
	cus_use.setWeight(50);
	cus_bp.add(&cus_use);
	
	cus_bp.log();
	std::cout << std::endl;
	
	Usable sword(
		"sword",
		"sharp",
		"cut",
		20,
		"SLASH",
		"OUCH"
	);
	Usable* ptr = &sword;
	cus_bp.runMenu(ptr);
	
	cus_bp.remove("key");
	cus_bp.remove("horse");
	cus_bp.log();
	std::cout << std::endl;
}

void driver::playerTest() {
	Player p;
	p.log();
	std::cout << std::endl;
	
	Holdable h;
	Holdable cus_h("note", "text that says, 'where were you?'", "read", 20);
	Usable use;
	Usable cus_use(
		"key",
		"brass and brown key",
		"unlock",
		50,
		"UNLOCK",
		"UNLOCKED"
	);
	Usable sword(
		"sword",
		"sharp",
		"cut",
		20,
		"SLASH",
		"OUCH"
	);
	
	p.pickup(&h);
	p.pickup(&cus_h);
	p.pickup(&use);
	p.pickup(&cus_use);
	p.pickup(&sword);
	
	p.equip(&sword);
	
	p.log();
	std::cout << std::endl;
	
	p.unequip();
	p.log();
	std::cout << std::endl;
	
	p.viewBackpack();
	
	p.log();
	std::cout << std::endl;
}

void driver::roomTest() {
	//Define the series of objects to put in each room.
	Permanent perm;
	Permanent cus_perm(
		"Wall",
		"a brick wall",
		"immovable"
	);
	
	Holdable h;
	Holdable cus_h("note", "text that says, 'where were you?'", "read", 20);
	
	Usable use;
	Usable cus_use(
		"key",
		"brass and brown key",
		"unlock",
		50,
		"UNLOCK",
		"UNLOCKED"
	);
	Usable sword(
		"sword",
		"sharp",
		"cut",
		20,
		"SLASH",
		"OUCH"
	);
	
	Goal g;
	Goal cus_g(
		"Primary Goal",
		"a brown stone altar",
		"You succeeded and won the game!",
		"You failed and Kim Jong-Un died!"
	);
	
	Player p;
	Player *p_ptr = &p;
	
	GoalRoom def_room;
	
	///////////// Goal Room //////////////////
	GoalRoom g_room("special room");
	Room *g_ptr = &g_room;
	g_room.setNorth(&def_room);
	g_room.special(&perm);
	g_room.special(&cus_perm);
	g_room.special(&h);
	g_room.special(&cus_h);
	g_room.special(&use);
	g_room.special(&cus_use);
	g_room.special(&sword);
	g_room.special(&g);
	g_room.special(&cus_g);
	
	g_room.log();
	g_room.printObjects();
	std::cout << std::endl;
	
	g_room.runMenu(g_ptr, p_ptr);
	g_ptr->log();
	std::cout << std::endl;
	
	
	///////////// ResourceRoom ///////////////
	ResourceRoom r_room("resource ROOM");
	Room *r_ptr = &r_room;
	r_room.setNorth(&def_room);
	r_room.special(&perm);
	r_room.special(&cus_perm);
	r_room.special(&h);
	r_room.special(&cus_h);
	r_room.special(&use);
	r_room.special(&cus_use);
	r_room.special(&sword);
	r_room.special(&g);
	r_room.special(&cus_g);
	
	r_room.log();
	r_room.printObjects();
	std::cout << std::endl;
	
	r_room.runMenu(r_ptr, p_ptr);
	r_ptr->log();
	std::cout << std::endl;
	
	///////////// InteractRoom ///////////////
	InteractRoom i_room("interact ROOM");
	Room *i_ptr = &i_room;
	i_room.setNorth(&def_room);
	i_room.special(&perm);
	i_room.special(&cus_perm);
	i_room.special(&h);
	i_room.special(&cus_h);
	i_room.special(&use);
	i_room.special(&cus_use);
	i_room.special(&sword);
	i_room.special(&g);
	i_room.special(&cus_g);
	
	i_room.log();
	i_room.printObjects();
	std::cout << std::endl;
	
	i_room.runMenu(i_ptr, p_ptr);
	i_ptr->log();
	std::cout << std::endl;
	
	////////////// All the Rooms together //////////////////
	
	//Link all the rooms together, and then try navigating them.
	g_room.setNorth(&def_room);
	g_room.setSouth(&r_room);
	g_room.setEast(&i_room);
	
	i_room.setSouth(&r_room);
	def_room.setWest(&r_room);
	
	Room *room_ptr = &g_room;
	for(int i = 0; i < 7; i++) {
		room_ptr->runMenu(room_ptr, p_ptr);
	}
	std::cout << std::endl;
	
}