/************************************************************************
Class Name:		Game
Author:			Howard Chen
Last Modified:	3-26-2017
Description:	Overall Game class that contains a RoomGraph, Player,
				and methods for playing the game.
************************************************************************/

#include "Game.hpp"
#include <iostream>

/*************************************
See Game.hpp for documentation
***************************************/

Game::Game(){
	maxSteps = 40;
	curSteps = 0;
	
	//MAKE AND SAVE PERMANENT OBJECTS
	Permanent* blood_cells = new Permanent("blood cells", "red and white blood cells", "robot");
	Permanent* clots = new Permanent("clots", "clots tough and fibrous tissue", "robot");
	Permanent* cavities = new Permanent("cavities", "multiple lesions full of bacteria", "permanent");
	Permanent* cancer = new Permanent("lipoma", "a nearly malignant tumor", "permanent");
	Permanent* perforations = new Permanent("performations", "several bleeding wounds in the brain", "permanent");
	
	objects.push_front(blood_cells);
	objects.push_front(clots);
	objects.push_front(cavities);
	objects.push_front(cancer);
	objects.push_front(perforations);
	
	//SET UP INTERACTIONS FOR THE PERMANENT OBJECTS
	blood_cells->addInteraction(std::make_pair( "robot",
		[]{
			std::cout << "You pull some cells apart. Not good." << std::endl;
		}
	));
	clots->addInteraction(std::make_pair( "robot",
		[] {
			std::cout << "The clot is too dense to pull apart, unfortunately" << std::endl;
		}
	));
	cavities->addInteraction(std::make_pair( "rebuild",
		[cavities]{
			cavities->setKey("small");
			std::cout << "Jong Un's teeth look as good as new!" << std::endl;
			cavities->setDescription("beautiful set of teeth");
			cavities->setName("gorgeous teeth");
			std::cout << "Use the remaining calcium on the correct microchip to log this success"
					  << std::endl;
		}
	
	));
	cancer->addInteraction(std::make_pair( "t-cell",
		[cancer]{
			cancer->setKey("immune");
			std::cout << "The tumor starts to shrink!" << std::endl;
			cancer->setDescription("shrinking tumor");
			cancer->setName("shrinking tumor");
			std::cout << "Use the remaining T-cells on the correct microchip to log this success"
					  << std::endl;
		}
	));
	perforations->addInteraction(std::make_pair("repair",
		[perforations] {
			perforations->setKey("scab");
			std::cout << "The bleeding slows to a trickle, and then stops" << std::endl;
			perforations->setDescription("brain that is healing well");
			perforations->setName("healing brain");
			std::cout << "Use the remaining healiing factor on the correct microchip to log this success"
					  << std::endl;
		}
	));
	
	//MAKE AND SAVE USABLE OBJECTS
	Usable* calcium = new Usable("calcium", "a large amount of minerals", "rebuild", 20,
		"rebuild the hydroxyapatite in the teeth", "the teeth are now healthy"
	);
	Usable* t_cells = new Usable("T-cells", "programmable, differentiable T-cells", "t-cell", 30,
		"You program the T-cells to attack the cancer cells alone at a slow, but steady pace "
		"that avoids the release of large amounts of toxins", "The tumor begins to disintegrate"
	);
	Usable* healer = new Usable("brain repair factor pill", "a pill full of repair factors", "repair", 25,
		"The repair factors attract platelets", "The perforations in the brain quickly close"
	);
	
	objects.push_front(calcium);
	objects.push_front(t_cells);
	objects.push_front(healer);
	
	//MAKE AND SAVE HOLDABLE OBJECTS
	Holdable* hint = new Holdable(
		"hint map",
		"a nano-sized document that says the following: t-cell to brain, calcium to cavities, "
			"pill to brain. When done, bring t-cell, calcium, and cavities to heart and use each one "
			"on the correct microchip. Then, when all goals have been completed, go to mouth for "
			"extraction from Jong-Un's body",
		"hint", 40
	);
	
	objects.push_front(hint);
	
	//MAKE AND SAVE GOAL OBJECTS
	Goal* heal = new Goal("a red microchip", "a red microchip",
		"COMPLETED: At this point, the bleeding has stopped. The brain is beginning to recover",
		"GOAL: Fix the bleeding in the brain!"
	);
	Goal* destroy = new Goal("a green microchip", "a green microchip",
		"COMPLETED: The tumor is being attacked by the T-cells. It should be gone within a day",
		"GOAL: Destroy the tumor in the fat!"
	);
	Goal* dental = new Goal("a blue microchip", "a blue microchip",
		"COMPLETED: Jong Un's teeth look as good as new!",
		"GOAL: Fix the cavities in Jong Un's teeth!"
	);
	
	goals.push_front(heal);
	goals.push_front(destroy);
	goals.push_front(dental);
	
	//SET UP INTERACTIONS FOR THE GOAL OBJECTS
	heal->addInteraction(std::make_pair( "scab",
		[heal] {
			std::cout << heal->getSuccess() << std::endl;
			heal->setKey("success");
			heal->setFailure(heal->getSuccess());
		}
	));
	
	destroy->addInteraction(std::make_pair( "immune",
		[destroy] {
			std::cout << destroy->getSuccess() << std::endl;
			destroy->setKey("success");
			destroy->setFailure(destroy->getSuccess());
		}
	));
	
	dental->addInteraction(std::make_pair("small",
		[dental] {
			std::cout << dental->getSuccess() << std::endl;
			dental->setKey("success");
			dental->setFailure(dental->getSuccess());
		}
	));
	
	
	//CREATE THE ROOMS SAVE EACH ROOM, and ADD OBJECT TO EACH ROOM.
	Room* heart = new GoalRoom("the heart");
	heart->special(heal);
	heart->special(destroy);
	heart->special(dental);
	currentRoom = heart;		//heart is also the first room of the player.
	rooms.push_front(heart);
	
	Room* blood = new InteractRoom("the bloodstream");
	blood->special(blood_cells);
	blood->special(clots);
	rooms.push_front(blood);
	
	Room* bone = new ResourceRoom("the bone");
	bone->special(calcium);
	rooms.push_front(bone);
	
	Room* mouth = new InteractRoom("the mouth");
	mouth->special(cavities);
	rooms.push_front(mouth);
	
	Room* fat = new InteractRoom("the neck fat");
	fat->special(cancer);
	rooms.push_front(fat);
	
	Room* thymus = new ResourceRoom("the thymus");
	thymus->special(t_cells);
	rooms.push_front(thymus);
	
	Room* brain = new InteractRoom("the brain");
	brain->special(perforations);
	rooms.push_front(brain);
	
	Room* intestines = new ResourceRoom("the intestines");
	intestines->special(healer);
	intestines->special(hint);
	rooms.push_front(intestines);
	
	
	//FINALLY, LINK THE ROOMS.
	heart->setNorth(mouth);
	heart->setSouth(blood);
	heart->setEast(bone);
	heart->setWest(fat);
	
	blood->setNorth(heart);
	blood->setSouth(intestines);
	blood->setEast(thymus);
	blood->setWest(brain);
	
	intestines->setNorth(heart);
	intestines->setEast(mouth);
	
	mouth->setSouth(heart);
	mouth->setEast(intestines);
	mouth->setWest(brain);
	
	brain->setEast(blood);
	brain->setNorth(mouth);
	
	thymus->setNorth(bone);
	thymus->setWest(fat);
	
	fat->setSouth(thymus);
	fat->setEast(heart);
	
	bone->setSouth(thymus);
	bone->setWest(heart);
	
	//THE GAME IS SET UP. NOW YOU'RE READY TO PLAY!
}

//Destructor. Destroy all allocated memory.
Game::~Game(){
	for(auto &p : objects){
		delete p;
		p = nullptr;
	}
	for(auto &p : goals) {
		delete p;
		p = nullptr;
	}
	for(auto &p : rooms) {
		delete p;
		p = nullptr;
	}
}

void Game::play(){
	std::cout << "\n\n\n";
	
	std::cout << "Kim Jong Un is extremely ill. He's bleeding in the brain, has a tumor in his neck fat, "
				 "and has multiple cavities. As a result, he cannot appear in public. The people are "
				 "are beginning to doubt his strength, and his generals are thinking about replacing him. "
				 "Your job as a medical nanobot is to fix all these medical problems so that Jong Un can get "
				 "back to ruling the greatest country in the world." << "\n\n" <<
				 "You will be activated within Jong Un's heart, along with 3 microchips that list your goals. "
				 "Look through the intestine, bones, and thymus of Jong-Un to find the materials you need to "
				 "fix his health problems. Then use the materials on each microchip to log your successes. "
				 "Then LEAVE THE HEART so we can extract you safely. \n\n"
				 "You only have the time to visit 40 Rooms at most. Good luck.";
	
	std::cout << "\n\n\n";
	
	bool lose = true;
	bool match = true;
	Player* p_player = &player;
	while(curSteps < maxSteps && lose){
		std::cout << "Current step: " << curSteps << std::endl;
		std::cout << "Max step: " << maxSteps << "\n\n";
		
		currentRoom->runMenu(currentRoom, p_player);
		
		//SET UP CONDITIONS FOR WINNING AND MESSAGES
		//FOR WINNING AND LOSING.
		match = true;
		for(auto &r : goals){
			if(r->getKey() != "success") {
				match = false;
			}
		}
		
		if(match){
			lose = false;
		}
		
		curSteps++;
	}
	
	if(match){
		std::cout << "\n\n" << "Congratulations! You saved Kim Jong Un's life!" << "\n\n";
	}
	else{
		std::cout << "\n\n" << "You failed to save Kim Jong Un's life!" << "\n\n";
	}
	
	std::cout << std::endl;
	
	
}


void Game::log() {
	player.log();
	currentRoom->log();
	std::cout << "Max Steps: " << maxSteps << '\n';
	std::cout << "Current Steps: " << curSteps << '\n';
	
	std::cout << "Objects: ";
	for(auto &obj : objects){
		std::cout << obj->getName() << ", ";
	}
	std::cout << '\n';
	
	std::cout << "Goals: ";
	for(auto &g : goals){
		std::cout << g->getName() << ", ";
	}
	std::cout << '\n';
	
	std::cout << "Rooms: ";
	for(auto &r : rooms){
		std::cout << r->getDescription() << ", ";
	}
	std::cout << std::endl;
}