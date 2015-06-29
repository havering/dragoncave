
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>	 // for tolower
#include <vector>
#include "defaults.h"
#include "rooms.h"
using std::cout;
using std::cin;
using std::endl;
using std::tolower;
using std::vector;

// function prototypes
void playGame(Map* newMap);
int gameOne();
int gameTwo();
int gameThree();
void seeMenu();
void dragonRoom(Room* current, Player dude);

int main() {

	Map* gameMap = new Map();

	playGame(gameMap);

}

void playGame(Map* newMap) {
	Room* current = newMap->getStart();
	Player dude;
	int choosing;

	seeMenu();

	while (current != newMap->getEnd()) {
		int go;
		// one move per while loop executed
		// additional moves added for time solving puzzles
		dude.setMoves(1);

		cout << "You find yourself in " << current->getRName() << "." << endl;
		cout << current->getDesc() << endl;
		cout << endl;

		// puzzle rooms
		// adds the number of times it took to get correct answer to number of moves made by player
		// if the user has already solved the puzzle, they don't have to solve it again
		if (current->getID() == 3) {
			if (dude.getP1()) {
				cout << "You have already solved this puzzle, so you are free to go about your business." << endl;
				cout << endl;
			}
			else {
				int numMoves = gameOne();
				dude.setMoves(numMoves);
				bool setter = true;
				dude.setP1(setter);
			}
		}
		if (current->getID() == 5) {
			if (dude.getP2()) {
				cout << "You have already solved this puzzle, so you are free to go about your business." << endl;
				cout << endl;
			}
			else {
				int numMoves = gameTwo();
				dude.setMoves(numMoves);
				bool setter = true;
				dude.setP2(setter);
			}
		}
		if (current->getID() == 9) {
			if (dude.getP3()) {
				cout << "You have already solved this puzzle, so you are free to go about your business." << endl;
				cout << endl;
			}
			else {
				int numMoves = gameThree();
				dude.setMoves(numMoves);
				bool setter = true;
				dude.setP3(setter);
			}
		}
		// no option to collect jewels in the dragon's opening
		if (current->getID() == 10) {

			dragonRoom(current, dude);
		}
		else {
			// choice to pick up jewels or weapons
			cout << "Would you like to gather jewels (1), keep a weapon (2), or move on (3)? ";
			while (!(cin >> choosing)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Try again, using an integer: ";
			}
			while (choosing < 1 || choosing > 3) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Try again, using an integer between 1 and 3: ";
				cin >> choosing;
			}
			cout << endl;
			if (choosing == 1) {
				if (current->getJewels() > 0) {
					cout << "You pick out " << current->getJewels() << " jewels and decide to move on." << endl;
					int jewels = current->getJewels();
					dude.setJewels(jewels);
				}
				else {
					cout << "Unfortunately, there are no jewels to be found. You decide to move on." << endl;
				}
			}

			if (choosing == 2) {
				if (current->getWeapons() > 0) {
					cout << "You pick out " << current->getWeapons() << " weapon, " << current->getWeaponName() << "and keep moving." << endl;
					int weapons = current->getWeapons();
					dude.setWeapons(weapons);
					string wname = current->getWeaponName();
					dude.setWName(wname);
				}
				else {
					cout << "Unfortunately, there are no weapons to be found. You decided to move on." << endl;
				}
			}

			if (choosing == 3) {
				cout << "There's nothing of interest here. Better keep moving." << endl;
			}

		}

		// directional choices
		cout << endl;
		cout << "Which direction would you like to go?" << endl;
		cout << '\t' << "1. North" << endl;
		cout << '\t' << "2. South" << endl;
		cout << '\t' << "3. East" << endl;
		cout << '\t' << "4. West" << endl;
		cout << "Enter a choice: ";
		while (!(cin >> go)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid entry. Enter an integer." << endl;
		}
		while (go < 1 || go > 4) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid entry. Choose between 1 and 4: ";
			cin >> go;
		}
		cout << endl;
		if (go == 1) {
			Room* temp = current->getNorth();
			if (temp == NULL) {
				cout << "You feel along the northern wall, but can't find an opening." << endl;
			}
			else {
				cout << "You leave to the north." << endl;
				current = temp;
			}
		}

		if (go == 2) {
			Room* temp = current->getSouth();
			if (temp == NULL) {
				cout << "You feel along the southern wall, but can't find an opening." << endl;
			}
			else {
				cout << "You leave to the south." << endl;
				current = temp;
			}
		}

		if (go == 3) {
			Room* temp = current->getEast();
			if (temp == NULL) {
				cout << "You feel along the eastern wall, but can't find an opening." << endl;
			}
			else {
				cout << "You leave to the east." << endl;
				current = temp;
			}
		}

		if (go == 4) {
			Room* temp = current->getWest();
			if (temp == NULL) {
				cout << "You feel along the western wall, but can't find an opening." << endl;
			}
			else {
				cout << "You leave to the west." << endl;
				current = temp;
			}
		}
	}

	if (current == newMap->getEnd()) {
		cout << "You find yourself in " << current->getRName() << endl;
		cout << current->getDesc() << endl;
		//system("pause");
		exit(0);
	}

}

// guess the correct number between 1 and 4
int gameOne() {
	int numTries = 1;

	srand(time(NULL));
	int master = rand() % 4 + 1;
	int guess;

	cout << "The troll swings the ax over his shoulder and eyes you smugly. 'I'm thinking of\na number";
	cout << " between 1 and 4,' he says. 'If you can guess the number, you can pass.'" << endl;
	cout << "That's it? It could be worse. Time to tell him your number: ";
	while (!(cin >> guess)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "(Hint: enter an integer between 1 and 4)" << endl;
	}
	while (guess < 1 || guess > 4) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "(Hint: enter an integer between 1 and 4)" << endl;
		cin >> guess;
	}
	while (guess != master) {
		numTries++;
		cout << endl;
		cout << "'Wrong!!' The troll is almost giddy. 'Try again, or you'll never get out.'" << endl;
		cout << endl;
		cout << "You think of another number to tell him: ";
		while (!(cin >> guess)) {
			cout << "(Hint: enter an integer between 1 and 4)" << endl;
		}
		while (guess < 1 || guess > 4) {
			cout << "(Hint: enter an integer between 1 and 4)" << endl;
			cin >> guess;
		}
	}
	if (guess == master) {
		cout << endl;
		cout << "The troll seems shocked that you have guessed correctly, but begrudgingly";
		cout << "\nlets you pass." << endl;
		cout << endl;

		return numTries;
	}
}

int gameTwo() {
	int numTries = 1;
	char guess;
	char answer = 'e';

	cout << endl;
	cout << "Sensing your agreement, the magical voice hums again in your head:" << endl;
	cout << endl;
	cout << "  I am the beginning of the end, the end of every place." << endl;
	cout << "  I am the beginning of eternity, the end of time and space. What am I?" << endl;
	cout << endl;
	cout << "Hmmm, what is your guess? ";
	while (!(cin >> guess)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "(Hint: enter an alphabetical char)" << endl;
	}

	while (tolower(guess) != answer) {
		numTries++;
		cout << "A loud buzz vibrates inside your head. 'Incorrect,' the voice hums." << endl;
		cout << "You try to think of another guess: ";
		while (!(cin >> guess)) {
			cout << "(Hint: enter an alphabetical char)" << endl;
		}
	}
	if (tolower(guess) == answer) {
		cout << "The magical voice's approval is warm and bright, if such a thing can" << endl;
		cout << "be said of a telepathic presence. 'Correct!' The lock on the chest falls open," << endl;
		cout << "revealing jewels and a weapon inside." << endl;
		cout << endl;
		return numTries;
	}
}

int gameThree() {
	int numTries = 1;
	int guess;

	cout << "The serpent weaves back and forth between you and the next part of the cave." << endl;
	cout << "'Answer this: what lies beyond me in this cave?'" << endl;
	cout << '\t' << "1. A dragon" << endl;
	cout << '\t' << "2. A potato" << endl;
	cout << '\t' << "3. A birdhouse" << endl;
	cout << endl;
	cout << "'Which is it?' ";
	while (!(cin >> guess)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "(Hint: enter an integer between 1 and 3)" << endl;
	}
	while (guess < 1 || guess > 3) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "(Hint: enter an integer between 1 and 3)" << endl;
		cin >> guess;
	}
	cout << endl;
	while (guess != 1) {
		numTries++;
		cout << "The serpent hisses disapproval. 'Falsssssse. Try again.'" << endl;
		while (!(cin >> guess)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "(Hint: enter an integer between 1 and 3)" << endl;
		}
		while (guess < 1 || guess > 3) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "(Hint: enter an integer between 1 and 4)" << endl;
			cin >> guess;
		}
	}
	if (guess == 1) {
		cout << "'Yesssss, you are correct,' the serpent hisses. 'You may passssss.'" << endl;
		return numTries;
	}

}

void seeMenu() {
	int goal;

	cout << "Would you like to see the goal of the game?" << endl;
	cout << "Use 1 for yes or 2 for no: ";
	while (!(cin >> goal)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter 1 for yes or 2 for no." << endl;
	}
	while (goal > 2 || goal < 1) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Try again. 1 for yes or 2 for no: ";
		cin >> goal;
	}
	cout << endl;
	if (goal == 1) {
		cout << "********************************************************************" << endl;
		cout << "*          The goal of the game is to escape the cave.             *" << endl;
		cout << "*  You must gather enough items to move past the final challenge.  *" << endl;
		cout << "* You may go back and gather more items if you do not have enough. *" << endl;
		cout << "********************************************************************" << endl;
		cout << endl;
	}
}

// player chooses to fight the dragon, gather more supplies, or bribe the dragon
// if player has taken too many turns, they automatically lose and die
void dragonRoom(Room* current, Player dude) {
	int fight;

	cout << endl;
	if (dude.getMoves() > 20) {
		cout << endl;
		cout << "Oh no! The dragon is out of patience. He lets out a mighty roar and burns you \nto a crisp." << endl;
		cout << endl;
		cout << "                  GAME OVER                   " << endl;
		cout << endl;
		system("pause");
		exit(0);
	}
	else {
		cout << "Do you try to bribe the dragon (1), fight the dragon (2), or go back to gather \nsupplies (3)? ";
		while (!(cin >> fight)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Try again, using an integer: ";
		}
		while (fight < 1 || fight > 3) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Try again, using an integer between 1 and 3: ";
			cin >> fight;
		}

		if (fight == 1) {
			// user must have 15 jewels to bribe the dragon
			int numJewels = dude.getJewels();
			cout << "You rummage in your bag for the jewels you've stashed. You have " << numJewels << " jewels to \noffer." << endl;
			cout << "You hold them out to the dragon and hold your breath." << endl;
			cout << endl;
			if (numJewels >= 15) {
				cout << "The dragon growls deep in its throat, but gently swipes the pile of jewels out \nof your hands." << endl;
				cout << "Success! The opening is left clear and you are free to leave the cave." << endl;
				cout << endl;
				return;
			}
			else {
				cout << "The dragon yawns widely at you, flames escaping its maw as it does so." << endl;
				cout << "It seems you do not have enough jewels to bribe him. Better head back into the cave." << endl;
				return;
			}
		}

		if (fight == 2) {
			// user must have 5 weapons to bribe the dragon
			int numWeapons = dude.getWeapons();

			cout << "Finally, these heavy weapons come in handy!" << endl;
			cout << "You peer inside your bag - you have ";
			vector<string> temp = dude.getWName();
			for (int i = 0; i < temp.size(); i++) {
				cout << temp[i];
			}
			cout << "and your wits about you." << endl;
			cout << endl;
			if (numWeapons >= 5) {
				cout << "The dragon roars as it sees your available arsenal. It gives you a scathing \nlook, and slinks out of the way." << endl;
				cout << "That was anticlimatic." << endl;
				cout << endl;
				return;
			}
			else {
				cout << "The dragon threatens you with little snorts of flame, and you suddenly \nrealize that you aren't armed well enough to take on a battle." << endl;
				cout << "Perhaps you should head back into the cave for more supplies ..." << endl;
				cout << endl;
				return;
			}

		}

		if (fight == 3) {
			cout << "You decide to slip back and gather more supplies to help you make your choice." << endl;
			return;
		}
	}


}
