#include <iostream>
#include "room.h"

using namespace std;

room::room() {
  
}

void room::setRoomId(int x) {
  roomId = x;
}

void room::setExitW(int a) {
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
}



