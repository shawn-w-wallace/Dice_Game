#pragma once
#include "stdafx.h"
#include "playerClass.h"
#include "diceClass.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#using <system.dll>  
using namespace std;
using namespace System;
using namespace System::IO;

//player class controls the flow, inital assignment of chips, and dice result flow and assignment of chips.
class Player {

private:

	int numChips;

public:

	Player() {
		this->numChips = 3; //starting chips
	}
	char* rollDice(Dice dice) { //dice assignment based on player current chips
		char *playerDice = new char[this->numChips];
		for (int i = 0; i<this->numChips; i++) {
			playerDice[i] = dice.roll(i + 1);
		}
		return playerDice;
	}
	void loseChipCenter() {
		this->numChips--;
	}
	void getChip() {
		this->numChips++;
	}
	void loseChip() {
		this->numChips--;
	}
	bool hasChips() {
		if (this->numChips > 0) {
			return true;
		}
		return false;
	}
	int getNumChips() {
		return this->numChips;
	}
};