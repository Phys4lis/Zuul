#include <iostream>
#include <map>
#include <cstring>
#include "room.h"


using namespace std;

room::room() {
  
}

// Room functions
char* room::getDescription() {
  return description;
}

void room::setRoomID(int x) {
  roomID = x;
}

void room::setExit(char* dir, room* ro) {
  exits.insert(pair<char*, room*>(dir, ro)); 
}

room* room::getExit(char* input) {
  for (map<char*, room*>::iterator iter = exits.begin(); iter != exits.end(); iter++) {
    if (strcmp(iter->first, input) == 0) {
      return iter->second;
    }
  }
  return NULL;
}

	      
/*void room::setExitW(int a) {
  exitW = a;
}

void room::setExitN(int b) {
  exitN = b;
}

void room::setExitE(int c) {
  exitE = c;
}

void room::setExitS(int d) {
  exitS = d;
  }*/

