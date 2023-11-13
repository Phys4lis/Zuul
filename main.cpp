/* This program will simulate a text-based adventure game with text information and commands that will allow the user to travel through and interact with rooms.
 * Date: 11/13/23
 * Author: Roger Li
 */

#include <iostream>
#include <cstdlib>

void introduction();

using namespace std;

int main() {
  introduction();
}

void introduction() {
   cout << "Maybe visiting your parents' old mansion for summer break wasn't the best idea. Neither was choosing to fly there at 11:30 PM." << endl;
  cout << "." << endl;
  cout << "." << endl;
  cout << "You enter the mansion cautiously, only for the door you entered through to suddenly slam shut. You sprint to the door and try to pry it open with no avail. You glance down at the handle and notice a golden lock with a keyhole." << endl;
  cout << "." << endl;
  cout << "." << endl;
  cout << "Perhaps a golden key will save you." << endl;
  cout << "Enter 'help' if you ever require assistance" << endl;
}

void getHelp() {
  cout << "Your command words are: " << "help, go, inventory, get, drop, quit" << endl;
}
