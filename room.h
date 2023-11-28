#ifndef ROOM_H
#define ROOM_H

#include <iostream>

using namespace std;

class room {
 public:
  room();
  char description[1000];
  int roomID;
  int exitW;
  int exitN;
  int exitE;
  int exitS;
  
  bool hasExitW;
  bool hasExitN;
  bool hasExitE;
  bool hasExitS;

  char* getDescription();
  
  void setRoomID(int x);
  void setExitW(int a);
  void setExitN(int b);
  void setExitE(int c);
  void setExitS(int d);
  
  bool hasBedroomKey;
  bool hasGrandKey;
  bool hasCoins;
  bool hasDoll;
  bool hasToothbrush;
};

#endif
