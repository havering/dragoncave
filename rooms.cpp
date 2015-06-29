// Holds inherited classes of different room types
// Sets the unique jewel/weapons values for each room

//#include "defaults.h"
#include "rooms.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

DragonRoom::DragonRoom(string name) {
	jewels = 0;
	weapons = 0;
	roomName = name;
}

PuzzleRoom::PuzzleRoom(string name, string wname) {
	jewels = 4;
	weapons = 1;
	roomName = name;
	weaponName = wname;
}

GenericRoom::GenericRoom(string name, string wname) {
	jewels = 3;
	weapons = 1;
	roomName = name;
	weaponName = wname;
}

WeaponRoom::WeaponRoom(string name, string wname) {
	jewels = 0;
	weapons = 1;
	roomName = name;
	weaponName = wname;
}

JewelRoom::JewelRoom(string name) {
	jewels = 5;
	weapons = 0;
	roomName = name;
}

