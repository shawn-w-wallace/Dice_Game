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

//dice class, houses face values for game.ccp dice switch and prompts player to enter 'r' to roll the dice. 
//without this "pause" function it is hard to see what is going on with the game.
class Dice {

private:

	char faces[6] = { 'L','C','R','*','*','*' };

public:

	char roll(int num = 1) {
		char s;
		while (true) {
			cout << "\tPlease Enter 'r' to roll dice #" << num << " : ";
			cin >> s;
			if (s == 'r') {
				return faces[rand() % 6];
			}
			cout << "\nInvalid input." << endl;
		}
	}
};