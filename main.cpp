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

void introduction(vector<room*> &Rooms);
void getHelp();
int validInput();

using namespace std;

int main() {

  map<char*, room*> exits;
  vector<room*> Rooms;
  introduction(Rooms);
  bool running = true;
  while (running == true) {
    int input = validInput();
    // Help command
    if (input == 1) {
      getHelp();
    }
    // Go command 
    else if (input == 2) {
      cout << "What direction would you like to go?" << endl;
      char direction[10];
      cin.get(direction, 10);
      cin.get();
      if ((strcmp(direction, "west") == 0) || (strcmp(direction, "WEST") == 0)) {

      }
      else if ((strcmp(direction, "north") == 0) || (strcmp(direction, "NORTH") == 0)) {

      }
      else if ((strcmp(direction, "east") == 0) || (strcmp(direction, "EAST") == 0)) {

      }
      else if ((strcmp(direction, "south") == 0) || (strcmp(direction, "SOUTH") == 0)) {

      }
    }
    // Inventory command
    else if (input == 3) {

    }
    // Get command
    else if (input == 4) {

    }
    // Drop command
    else if (input == 5) {

    }
    // Quit command
    else if (input == 6) {
      running = false;
      cout << "Have a good day." << endl;
    }
  }
}

void introduction(vector<room*> &Rooms) {
  cout << endl << "Maybe visiting your parents' old mansion for summer break wasn't the best idea. Neither was choosing to fly there at midnight." << endl;
  cout << "." << endl;
  cout << "." << endl;
  cout << "You enter the mansion cautiously, only for the door you entered through to suddenly slam shut. You sprint to the door and try to pry it open with no avail. Glancing down at the door handle, you notice a golden lock with a keyhole." << endl;
  cout << "." << endl;
  cout << "." << endl;
  cout << "Perhaps a golden key will save you, but for now, you're stuck in the mansion." << endl;
  cout << "Enter 'help' if you ever require assistance" << endl << endl;

  // Create the rooms
  room* entranceExit = new room();
  strcpy(entranceExit->description, "A wave of uneasiness washes over you. The grand hall in front of you appears more ominous than grand...");
  entranceExit->roomID = 0;
  room* grandHall = new room();
  strcpy(grandHall->description, "You glance around the hall, wondering if a key could be hidden behind any of the gigantic paintings hung up on the walls. You try to move a painting but it doesn't budge. The key must be in another room.");
  grandHall->roomID = 1;
  room* basement = new room();
  strcpy(basement->description, "You look under a table and find a rusty trapdoor. Letting your curiosity get the better of you, you crawl through a dusty tunnel and find youself in...a basement?");
  basement->roomID = 2;
  room* magicCircle = new room();
  strcpy(magicCircle->description, "A faint glow beckons you forward, but you regret your decision as you realize you're standing in the middle of a magic circle. Are you about to become the subject of an experiment?");
  magicCircle->roomID = 3;
  room* library = new room();
  strcpy(library->description, "Running for your life, you stumble through a broken door and wind up in the most aesthetic library you've ever seen. You also notice a shimmering silver key located on one of the library's many smooth oak tables.");
  library->roomID = 4;
  room* diningHall = new room();
  strcpy(diningHall->description, "Tables, chairs, candles, and broken chandeliers line the dining hall. Where's the food?");
  diningHall->roomID = 5;
  room* garden = new room();
  strcpy(garden->description, "Past the dining hall is an extensive garden overgrown with weeds. What a shame.");
  garden->roomID = 6;
  room* forest = new room();
  strcpy(forest->description, "Bored of the dead flowers and prickly weeds, you venture into the forest, where a strong stench of blood stains the air...you look down and spot a pile of gold coins...alongside a bunch of ragged clothes...what happened here?");
  forest->roomID = 7;
  room* centralStairway = new room();
  strcpy(centralStairway->description, "In front of you is a spiralling staircase that honestly seems like a pain to climb...but you nonetheless keep climbing knowing that there's a chance that the key is located upstairs.");
  centralStairway->roomID = 8;
  room* commonRooms = new room();
  strcpy(commonRooms->description, "A warm fireplace is the first thing you've encountered that suggests that maybe this mansion isn't haunted. But then again, why is the fireplace burning in the first place?");
  commonRoom->roomID = 9;
  room* childrensRoom = new room();
  strcpy(childrensRoom->description, "A room empty except for a couple of toys and a singular bunkbed. Is this really the room of children?");
  childrensRoom->roomID = 10;
  room* closet = new room();
  strcpy(closet->description, "The closet contains a singular doll. A one-eyed ragged doll with a half stitched on leg and a creepy grin.");
  closet->roomID = 11;
  room* balcony = new room();
  strcpy(balcony->description, "A balcony! Freedom at last! You internally ready yourself to jump...and then you remember that the mansion is situated on a cliff...best to not fall to your death...");
  balcony->roomID = 12;
  room* masterBedroom = new room();
  strcpy(masterBedroom->description, "You enter the master bedroom with your silver key and immediately become drowsy. A sweet scent enters your noise, and you realize you need to hurry up before your brain shuts down.");
  masterBedroom->roomID = 13;
  room* changingRoom = new room();
  strcpy(changingRoom->description, "Racks of clothes and...is that a golden key??");
  changingRoom->roomID = 14;
  room* bathroom = new room();
  strcpy(bathroom->description, "An ordinary bathroom with an ordinary sink and an unordinary toothbrush. Since when were toothbrushes sharp?");
  bathroom->roomID = 15;
  
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

  // Mapping
  // map[1] = entranceExit;
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
