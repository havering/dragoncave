#ifndef DEFAULTS_H
#define DEFAULTS_H

#include <string>
#include <vector>
using std::vector;
using std::string;

// default class for rooms
// room "superclass"
class Room {
	friend class Map;

protected:
	int jewels;
	int weapons;
	string weaponName;
	string roomName;
	string roomDesc;
	Room* north;
	Room* south;
	Room* east;
	Room* west;
	int roomID;

public:
	Room();
	virtual string getRName();
	virtual int getJewels();
	virtual int getWeapons();
	virtual string getWeaponName();
	void setNorth(Room* northNode);
	void setSouth(Room* southNode);
	void setEast(Room* eastNode);
	void setWest(Room* westNode);
	void setDesc(string desc);
	string getDesc();
	Room* getNorth();
	Room* getSouth();
	Room* getEast();
	Room* getWest();
	virtual int getID();
	virtual void setID(int num);
	virtual void setNextNode(Room* nextNode);

};

// default class for player
class Player {
private:
	int moves;	// number of moves player has taken
	int jewels;
	int weapons;
	bool p1;
	bool p2;
	bool p3;
	vector<string> weaponNames;

public:
	Player();
	int getMoves();
	void setMoves(int m);
	int getJewels();
	void setJewels(int j);
	int getWeapons();
	void setWeapons(int w);
	void setWName(string name);
	void setP1(bool p);
	bool getP1();
	void setP2(bool p);
	bool getP2();
	void setP3(bool p);
	bool getP3();
	vector<string> getWName();

};

class Map {
private:
	vector<Room*> roomList;
	Room* starter;
	Room* end;

public:
	Map();
	void setStart(Room* start);
	Room* getStart();
	void setEnd(Room* ender);
	Room* getEnd();
};

#endif
