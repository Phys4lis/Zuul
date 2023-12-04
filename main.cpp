/* This program will simulate a text-based adventure game with text information and commands that will allow the user to travel through and interact with rooms.
 * Date: 11/15/23
 * Author: Roger Li
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "room.h"
#include <map>

void introduction();
void createRooms(vector<room*> &Rooms); 
void getHelp();
int validInput();

using namespace std;

int main() {
  vector<room*> Rooms;
  introduction();
  // createRooms(Rooms);
  
  // Create rooms
  room* entranceExit = new room();
  room* grandHall = new room();
  room* basement = new room();
  room* magicCircle = new room();
  room* library = new room();
  room* diningHall = new room();
  room* garden = new room();
  room* centralStairway = new room();
  room* forest = new room();
  room* commonRooms = new room();
  room* childrensRoom = new room();
  room* closet = new room();
  room* balcony = new room();
  room* masterBedroom = new room();
  room* changingRoom = new room();
  room* bathroom = new room();

  
  // idea from Vikram Vasudevan
  char west[10];
  strcpy(west, "west");
  char north[10];
  strcpy(north, "north");
  char east[10];
  strcpy(east, "east");
  char south[10];
  strcpy(south, "south");

  // Create room descriptions and exits
  strcpy(entranceExit->description, "A wave of uneasiness washes over you. The grand hall in front of you appears more ominous than grand...");
  entranceExit->roomID = 0;
  entranceExit->setExit(north, grandHall);
  
  strcpy(grandHall->description, "You glance around the hall, wondering if a key could be hidden behind any of the gigantic paintings hung up on the walls. You try to move a painting but it doesn't budge. The key must be in another room.");
  grandHall->roomID = 1;
  grandHall->setExit(west, basement);
  grandHall->setExit(north, centralStairway);
  grandHall->setExit(east, diningHall);
  grandHall->setExit(south, entranceExit);
  
  strcpy(basement->description, "You look under a table and find a rusty trapdoor. Letting your curiosity get the better of you, you crawl through a dusty tunnel and find youself in...a basement?");
  basement->roomID = 2;
  basement->setExit(east, grandHall);
  basement->setExit(south, magicCircle);
  
  strcpy(magicCircle->description, "A faint glow beckons you forward, but you regret your decision as you realize you're standing in the middle of a magic circle. Are you about to become the subject of an experiment?");
  magicCircle->roomID = 3;
  magicCircle->setExit(north, basement);
  magicCircle->setExit(west, library);
  
  strcpy(library->description, "Running for your life, you stumble through a broken door and wind up in the most aesthetic library you've ever seen. You also notice a shimmering silver key located on one of the library's many smooth oak tables.");
  library->roomID = 4;
  library->setExit(east, magicCircle);
  
  strcpy(diningHall->description, "Tables, chairs, candles, and broken chandeliers line the dining hall. Where's the food?");
  diningHall->roomID = 5;
  diningHall->setExit(west, grandHall);
  diningHall->setExit(north, garden);
  
  strcpy(garden->description, "Past the dining hall is an extensive garden overgrown with weeds. What a shame.");
  garden->roomID = 6;
  garden->setExit(east, forest);
  garden->setExit(south, diningHall);
  
  strcpy(forest->description, "Bored of the dead flowers and prickly weeds, you venture into the forest, where a strong stench of blood stains the air...you look down and spot a pile of gold coins...alongside a bunch of ragged clothes...what happened here?");
  forest->roomID = 7;
  forest->setExit(west, garden);
  
  strcpy(centralStairway->description, "In front of you is a spiralling staircase that honestly seems like a pain to climb...but you nonetheless keep climbing knowing that there's a chance that the key is located upstairs.");
  centralStairway->roomID = 8;
  centralStairway->setExit(south, grandHall);
  centralStairway->setExit(north, commonRooms);
  
  strcpy(commonRooms->description, "A warm fireplace is the first thing you've encountered that suggests that maybe this mansion isn't haunted. But then again, why is the fireplace burning in the first place?");
  commonRooms->roomID = 9;
  commonRooms->setExit(west, masterBedroom);
  commonRooms->setExit(north, balcony);
  commonRooms->setExit(east, childrensRoom);
  commonRooms->setExit(south, centralStairway);
  
  strcpy(childrensRoom->description, "A room empty except for a couple of toys and a singular bunkbed. Is this really the room of children?");
  childrensRoom->roomID = 10;
  childrensRoom->setExit(west, commonRooms);
  childrensRoom->setExit(east, closet);
  
  strcpy(closet->description, "The closet contains a singular doll. A one-eyed ragged doll with a half stitched on leg and a creepy grin.");
  closet->roomID = 11;
  closet->setExit(west, childrensRoom);
  
  strcpy(balcony->description, "A balcony! Freedom at last! You internally ready yourself to jump...and then you remember that the mansion is situated on a cliff...best not to fall to your death...");
  balcony->roomID = 12;
  balcony->setExit(south, commonRooms);
  
  strcpy(masterBedroom->description, "You enter the master bedroom with your silver key and immediately become drowsy. A sweet scent enters your noise, and you realize you need to hurry up before your brain shuts down.");
  masterBedroom->roomID = 13;
  masterBedroom->setExit(west, bathroom);
  masterBedroom->setExit(north, changingRoom);
  masterBedroom->setExit(east, commonRooms);
  
  strcpy(changingRoom->description, "Racks of clothes and...is that a golden key??");
  changingRoom->roomID = 14;
  changingRoom->setExit(south, masterBedroom);
  
  strcpy(bathroom->description, "An ordinary bathroom with an ordinary sink and an unordinary toothbrush. Since when were toothbrushes sharp?");
  bathroom->roomID = 15;
  bathroom->setExit(east, masterBedroom);
  
  // Add rooms to vector
  Rooms.push_back(entranceExit);
  Rooms.push_back(grandHall);
  Rooms.push_back(basement);
  Rooms.push_back(magicCircle);
  Rooms.push_back(library);
  Rooms.push_back(diningHall);
  Rooms.push_back(garden);
  Rooms.push_back(forest);
  Rooms.push_back(centralStairway);
  Rooms.push_back(commonRooms);
  Rooms.push_back(childrensRoom);
  Rooms.push_back(closet);
  Rooms.push_back(balcony);
  Rooms.push_back(masterBedroom);
  Rooms.push_back(changingRoom);
  Rooms.push_back(bathroom);

  // Set items
  library->hasBedroomKey = true;
  bool playerHasBedroomKey = false;
  changingRoom->hasGrandKey = true;
  bool playerHasGrandKey = false;
  forest->hasCoins = true;
  bool playerHasCoins = false;
  closet->hasDoll = true;
  bool playerHasDoll = false;
  bathroom->hasToothbrush = true;
  bool playerHasToothbrush = false;

  // Set starting room
  room* currentRoom = entranceExit;
  
  bool running = true;
  while (running == true) {
    int input = validInput();
    // Help command
    if (input == 1) {
      getHelp();
    }
    // Go command 
    else if (input == 2) {
      bool running2 = true;
      while (running2 == true) {
	cout << "What direction would you like to go?" << endl;
	char direction[10];
	cin.get(direction, 10);
	cin.get();
	if (currentRoom->getExit(direction) == NULL) {
	  cout << endl << "There isn't a room there!" << endl << endl;
	}
	else {
	  currentRoom = currentRoom->getExit(direction);
	  cout << endl << currentRoom->getDescription() << endl << endl;
	  cout << "The exits are:" << endl;
	  if (currentRoom->getExit(north) != NULL) {
	    cout << "north ";
	  }
	  if (currentRoom->getExit(east) != NULL) {
	    cout << "east ";
	  }
	  if (currentRoom->getExit(south) != NULL) {
	    cout << "south ";
	  }
	  if (currentRoom->getExit(west) != NULL) {
	    cout << "west ";
	  }
	  cout << endl << endl;
	  if (currentRoom->hasBedroomKey == true || currentRoom->hasGrandKey == true || currentRoom->hasCoins == true || currentRoom->hasDoll == true || currentRoom->hasToothbrush == true) {
	    cout << "The items in this room include: " << endl;
	    if (currentRoom->hasBedroomKey == true) {
	      cout << "bedroom key ";
	    }
	    if (currentRoom->hasGrandKey == true) {
	      cout << "grand key ";
	    }
	    if (currentRoom->hasCoins == true) {
	      cout << "coins ";
	    }
	    if (currentRoom->hasDoll == true) {
	      cout << "doll ";
	    }
	    if (currentRoom->hasToothbrush == true) {
	      cout << "toothbrush ";
	    }
	    cout << endl << endl;
	  }
	  running2 = false;
	}
      }
    }
    // Inventory command
    else if (input == 3) {
      int numOfItems = 0;
      cout << endl << "Your inventory currently contains: ";
      if (playerHasBedroomKey == true) {
	cout << "bedroom key ";
	numOfItems++;
      }
      if (playerHasGrandKey == true) {
	cout << "grand key ";
	numOfItems++;
      }
      if (playerHasCoins == true) {
	cout << "coins ";
	numOfItems++;
      }
      if (playerHasDoll == true) {
	cout << "doll ";
	numOfItems++;
      }
      if (playerHasToothbrush == true) {
	cout << "toothbrush ";
	numOfItems++;
      }
      if (numOfItems == 0) {
	cout << "...nothing";
      }
      cout << endl << endl;
    }
    // Get command
    else if (input == 4) {
      // Check if the room has any of the five items
      if (currentRoom->hasBedroomKey == true || currentRoom->hasGrandKey == true || currentRoom->hasCoins == true || currentRoom->hasDoll == true || currentRoom->hasToothbrush == true) {
	cout << "What item would you like to get?" << endl;
	char input[40];
	cin.get(input, 40);
	cin.get();
	if ((currentRoom->hasBedroomKey == true) && (strcmp(input, "bedroom key") == 0)) {
	  cout << endl << "You have picked up a bedroom key.";
	  playerHasBedroomKey = true;
	  currentRoom->hasBedroomKey = false;
	}
	if ((currentRoom->hasGrandKey == true) && (strcmp(input, "grand key") == 0)) {
	  cout << endl << "You have picked up a grand key.";
	  playerHasGrandKey = true;
	  currentRoom->hasGrandKey = false;
	}
	if ((currentRoom->hasCoins == true) && (strcmp(input, "coins") == 0)) {
	  cout << endl << "You have picked up some coins.";
	  playerHasCoins = true;
	  currentRoom->hasCoins = false;
	}
	if ((currentRoom->hasDoll == true) && (strcmp(input, "doll") == 0)) {
	  cout << endl << "You have picked up a doll.";
	  playerHasDoll = true;
	  currentRoom->hasDoll = false;
	}
	if ((currentRoom->hasToothbrush == true) && (strcmp(input, "toothbrush") == 0)) {
	  cout << endl << "You have picked up a toothbrush.";
	  playerHasToothbrush = true;
	  currentRoom->hasToothbrush = false;
	}
	cout << endl << endl;
      }
      // If the room doesn't have any of the 5 items
      else {
	cout << endl << "There aren't any items in this room!" << endl << endl;
      }
    }
    // Drop command
    else if (input == 5) {
      if (playerHasBedroomKey == true || playerHasGrandKey == true || playerHasCoins == true || playerHasDoll == true || playerHasToothbrush == true) {
	cout << "What would you like to drop?" << endl;
	char input[40];
	cin.get(input, 40);
	cin.get();
	cout << endl;
	if ((playerHasBedroomKey == true) && (strcmp(input, "bedroom key") == 0)) {
	  cout << "You have dropped your bedroom key.";
	  playerHasBedroomKey = false;
	  currentRoom->hasBedroomKey = true;
	}
	if ((playerHasGrandKey == true) && (strcmp(input, "grand key") == 0)){
	  cout << "You have dropped your grand key.";
	  playerHasGrandKey = false;
	  currentRoom->hasGrandKey = true;
	}
	if ((playerHasCoins == true) && (strcmp(input, "coins") == 0)) {
	  cout << "You have dropped your coins.";
	  playerHasCoins = false;
	  currentRoom->hasCoins = true;
	}
	if ((playerHasDoll == true) && (strcmp(input, "doll") == 0)) {
	  cout << "You have dropped your doll.";
	  playerHasDoll = false;
	  currentRoom->hasDoll = true;
	}
	if ((playerHasToothbrush == true) && (strcmp(input, "toothbrush") == 0)) {
	  cout << "You have dropped your toothbrush.";
	  playerHasToothbrush = false;
	  currentRoom->hasToothbrush = true;
	}
	cout << endl << endl;
      }
      else {
	cout << endl << "You don't have any items to drop!" << endl << endl;
      }
    }
    // Quit command
    else if (input == 6) {
      running = false;
      cout << "Have a good day." << endl;
    }
  }
}

void introduction() {
  cout << endl << "Maybe visiting your parents' old mansion for summer break wasn't the best idea. Neither was choosing to fly there at midnight." << endl;
  cout << "." << endl;
  cout << "." << endl;
  cout << "You enter the mansion cautiously, only for the door you entered through to suddenly slam shut. You sprint to the door and try to pry it open with no avail. Glancing down at the door handle, you notice a golden lock with a keyhole." << endl;
  cout << "." << endl;
  cout << "." << endl;
  cout << "Perhaps a golden key will save you, but for now, you're stuck in the mansion." << endl;
  cout << "Enter 'help' if you ever require assistance" << endl << endl;
  cout << "There are exits:" << endl;
  cout << "north" << endl << endl;
}


void getHelp() {
  cout << endl << "Your command words are: " << "help, go, inventory, get, drop, quit" << endl << endl;
}

int validInput() {
  cout << "What would you like to do next?" << endl;
  bool looping = true;
  while (looping == true) {
    char commandInput[20];
    cin.get(commandInput, 20);
    cin.get();
    if (strcmp(commandInput, "help") == 0) {
      return 1;
    }
    else if (strcmp(commandInput, "go") == 0) {
      return 2;
    }
    else if (strcmp(commandInput, "inventory") == 0) {
      return 3;
    }
    else if (strcmp(commandInput, "get") == 0) {
      return 4;
    }
    else if (strcmp(commandInput, "drop") == 0) {
      return 5;
    }
    else if (strcmp(commandInput, "quit") == 0) {
      return 6;
    }
    else {
      cout << "Please enter a valid command." << endl;
      continue;
    }
  }
  return -1;
}
