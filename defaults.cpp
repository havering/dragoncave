#include <string>
#include <vector>
#include <iostream>
#include "defaults.h"
#include "rooms.h"
using std::vector;
using std::string;
using std::cout;

/*****Room Functions*****/

Room::Room() {
	jewels = 0;
	weapons = 0;
	weaponName = "";
	roomDesc = "";
}

int Room::getJewels() {
	return jewels;
}

string Room::getRName() {
	return roomName;
}

int Room::getWeapons() {
	return weapons;
}

string Room::getWeaponName() {
	return weaponName;
}

int Room::getID() {
	return roomID;
}

void Room::setID(int num) {
	roomID = num;
}

void Room::setDesc(string desc) {
	roomDesc = desc;
}

string Room::getDesc() {
	return roomDesc;
}

void Room::setNextNode(Room* anotherNode) {
	//next = anotherNode;
}

void Room::setNorth(Room* northNode) {
	north = northNode;
}

void Room::setSouth(Room* southNode) {
	south = southNode;
}

void Room::setEast(Room* eastNode) {
	east = eastNode;
}

void Room::setWest(Room* westNode) {
	west = westNode;
}

Room* Room::getNorth() {
	return north;
}

Room* Room::getSouth() {
	return south;
}

Room* Room::getEast() {
	return east;
}

Room* Room::getWest() {
	return west;
}

/****Player Functions*****/

Player::Player() {
	jewels = 0;
	weapons = 0;
	moves = 0;
	p1 = false;
	p2 = false;
	p3 = false;
}

int Player::getMoves() {
	return moves;
}

void Player::setMoves(int m) {
	moves += m;
}

int Player::getJewels() {
	return jewels;
}

void Player::setJewels(int j) {
	jewels += j;
}

int Player::getWeapons() {
	return weapons;
}

void Player::setWeapons(int w) {
	weapons += w;
}

void Player::setWName(string name) {
	weaponNames.push_back(name);
}

vector<string> Player::getWName() {
	return weaponNames;
}

void Player::setP1(bool p) {
	p1 = p;
}

bool Player::getP1() {
	return p1;
}

void Player::setP2(bool p) {
	p2 = p;
}

bool Player::getP2() {
	return p2;
}

void Player::setP3(bool p) {
	p3 = p;
}

bool Player::getP3() {
	return p3;
}

/*****Map Functions*****/

Map::Map() {
	Room* start = new DragonRoom("a deep cave");
	setStart(start);
	start->setWest(NULL);
	start->setSouth(NULL);
	start->setNorth(NULL);
	start->setID(1);
	string one = "You find yourself deep in catacombs. The light from the entrance is dim and \nfar away, but bright enough for you to follow.";
	start->setDesc(one);

	Room* secondRoom = new GenericRoom("a dimly lit cave", "a dagger, ");
	start->setEast(secondRoom);
	secondRoom->setWest(start);
	secondRoom->setNorth(NULL);
	secondRoom->setEast(NULL);
	secondRoom->setID(2);
	string two = "As the light grows brighter, your eyes are caught by the gleam of metal and \njewels in the corner. "
				 "A small pile of rubies sits on a rough rock ledge, \nwhile a dagger rests on the floor beneath.";
	secondRoom->setDesc(two);

	Room* thirdRoom = new PuzzleRoom("a narrow catacomb", "a helmet, ");
	secondRoom->setSouth(thirdRoom);
	thirdRoom->setNorth(start);
	thirdRoom->setEast(NULL);
	thirdRoom->setSouth(NULL);
	thirdRoom->setID(3);
	string three = "You squeeze into the next catacomb, which is considerably narrower than the \nfirst. The exit is blocked by a squat troll, whose ax dissuades you from \npassing."
					" 'You can pass if you solve a puzzle,' the troll growls at you. \nYou have no choice but to agree.";
	thirdRoom->setDesc(three);

	Room* fourthRoom = new JewelRoom("an opulent room");
	thirdRoom->setWest(fourthRoom);
	fourthRoom->setEast(thirdRoom);
	fourthRoom->setNorth(NULL);
	fourthRoom->setWest(NULL);
	fourthRoom->setID(4);
	string four = "Your relief at making it past the gnome turns to delight as you find yourself \nin a new cavern."
		" This one is draped in velvet, fur, strings of jewelry, and \npiles of gold. Who would leave such riches laying about?";
	fourthRoom->setDesc(four);

	Room* fifthRoom = new PuzzleRoom("a cobwebbed cave", "a mace, ");
	fourthRoom->setSouth(fifthRoom);
	fifthRoom->setNorth(fourthRoom);
	fifthRoom->setWest(NULL);
	fifthRoom->setSouth(NULL);
	fifthRoom->setID(5);
	string five = "This room in the cave is not nearly so pleasant. It smells musty and is covered\nin thick cobwebs. You do your best to pick through them."
		" As you step to the \nsideto avoid an intact web, your foot kicks up against a locked chest. You \ndon't see a key, but as you touch the lock, a voice hums in your mind:"
		"\n'Solve a riddle to gain a reward.'";
	fifthRoom->setDesc(five);

	Room* sixthRoom = new WeaponRoom("an armory", "a shield, ");
	fifthRoom->setEast(sixthRoom);
	sixthRoom->setWest(fifthRoom);
	sixthRoom->setSouth(NULL);
	sixthRoom->setNorth(NULL);
	sixthRoom->setID(6);
	string six = "You enter what appears to be an armory. Racks and racks of swords, shields, and\nspears fill the large space. You consider grabbing one before moving on.";
	sixthRoom->setDesc(six);

	Room* seventhRoom = new GenericRoom("a cave covered in cockroaches", "a throwing star, ");
	sixthRoom->setEast(seventhRoom);
	seventhRoom->setWest(sixthRoom);
	seventhRoom->setSouth(NULL);
	seventhRoom->setEast(NULL);
	seventhRoom->setID(7);
	string seven = "There are cockroaches everywhere. Your stomach churns, and you try to ignore \nthe crunching as you stride quickly across the room."
		"\nThe gleam of metal and jewels again catches your eye - but it is tempting \nto move on without investigating.";
	seventhRoom->setDesc(seven);

	Room* eighthRoom = new GenericRoom("a cave filled with bats", "a broadsword, ");
	seventhRoom->setNorth(eighthRoom);
	eighthRoom->setSouth(seventhRoom);
	eighthRoom->setNorth(NULL);
	eighthRoom->setWest(NULL);
	eighthRoom->setID(8);
	string eight = "The good news is that you've made it through the room full of cockroaches. The \nbad news is that the ceiling of this small cave is covered in bats. "
		"\n'Why don't they eat the cockroaches?' you wonder. A few of them stir when \nyou walk in, but for the most part, they seem to be asleep. "
		"\nYou are tempted by a satchel of jewels hanging from the hilt of a broadsword \nthat is leaned against the wall.";
	eighthRoom->setDesc(eight);

	Room* ninthRoom = new PuzzleRoom("a bright room", "a spear, ");
	eighthRoom->setEast(ninthRoom);
	ninthRoom->setWest(eighthRoom);
	ninthRoom->setEast(NULL);
	ninthRoom->setSouth(NULL);
	ninthRoom->setID(9);
	string nine = "The light from the entrance, which has been growing progressively brighter, \nbeams clearly into the room as you walk in. You freeze when you \nsee a serpent blocking your path. "
		"The serpent raises its head and hisses \nat you, 'You musssst anssssswer a quessssstion iffff you want to esssscape.'";
	ninthRoom->setDesc(nine);

	Room* tenthRoom = new DragonRoom("the cave opening");
	ninthRoom->setNorth(tenthRoom);
	tenthRoom->setSouth(ninthRoom);
	tenthRoom->setEast(NULL);
	tenthRoom->setWest(NULL);
	tenthRoom->setID(10);
	string ten = "You find yourself at the mouth of the cave. Just one problem: you find a dragon\nat the mouth of the cave, too. It rumbles at you, smoke curling up from its \nnostrils. "
		"You consider trying to dash past it, but there is not enough room \nfor you to squeeze past without being caught. You consider bribing or slaying \nthe dragon.";
	tenthRoom->setDesc(ten);

	Room* exit = new DragonRoom("the open air");
	setEnd(exit);
	tenthRoom->setNorth(exit);
	exit->setSouth(NULL);
	exit->setNorth(NULL);
	exit->setEast(NULL);
	exit->setWest(NULL);
	string eleven = "You did it! You've never been so relieved to see the sky.";
	exit->setDesc(eleven);
}

void Map::setStart(Room* start) {
	starter = start;
}

Room* Map::getStart() {
	return starter;
}

void Map::setEnd(Room* ender) {
	end = ender;
}

Room* Map::getEnd() {
	return end;
}
