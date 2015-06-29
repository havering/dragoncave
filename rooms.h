#ifndef ROOMS_H
#define ROOMS_H

#include "defaults.h"

class DragonRoom : public Room {
private:

public:
	DragonRoom(string name);
};

class PuzzleRoom : public Room {
private:

public:
	PuzzleRoom(string name, string wname);
};

class GenericRoom : public Room {
private:

public:
	GenericRoom(string name, string wname);
};

class WeaponRoom : public Room {
private:

public:
	WeaponRoom(string name, string wname);
};

class JewelRoom : public Room {
private:

public:
	JewelRoom(string name);
};

#endif
