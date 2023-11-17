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

void introduction(vector<room*> Rooms);
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

void introduction(vector<room*> Rooms) {
   cout << "Maybe visiting your parents' old mansion for summer break wasn't the best idea. Neither was choosing to fly there at midnight." << endl;
  cout << "." << endl;
  cout << "." << endl;
  cout << "You enter the mansion cautiously, only for the door you entered through to suddenly slam shut. You sprint to the door and try to pry it open with no avail. Glancing down at the door handle, you notice a golden lock with a keyhole." << endl;
  cout << "." << endl;
  cout << "." << endl;
  cout << "Perhaps a golden key will save you, but for now, you're stuck in the mansion." << endl;
  cout << "Enter 'help' if you ever require assistance" << endl << endl;

  // Create the rooms
  room* entranceExit = new room();
  room* grandHall = new room();
  room* basement = new room();
  room* magicCircle = new room();
  room* library = new room();
  room* diningHall = new room();
  room* garden = new room();
  room* forest = new room();
  room* centralStairway = new room();
  room* commonRooms = new room();
  room* childrensRoom = new room();
  room* closet = new room();
  room* balcony = new room();
  room* masterBedroom = new room();
  room* changingRoom = new room();
  room* bathroom = new room();

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
  map[1] = entranceExit;
}

void getHelp() {
  cout << "Your command words are: " << "help, go, inventory, get, drop, quit" << endl << endl;
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
