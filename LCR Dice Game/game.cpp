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


class Game {

private:

	int numPlayers;
	Dice dice;
	Player *players;
	int playersInGame;

public:
	//reads text file and outputs the contents.
	void displayRules() {
		String^ fileName = "LCR_Rules.txt";
		{
			StreamReader^ din = File::OpenText(fileName);
			String^ str;
			while ((str = din->ReadLine()) != nullptr)
			{
				Console::WriteLine(str);
			}
		}
		cout << endl << "Let's Play!" << endl;
	}
	//ask user for the number of players
	void getNumPlayers() {
		while (true) {
			cout << "\nEnter number of players : ";
			cin >> this->numPlayers;
			if (this->numPlayers < 3) {
				cout << "\nSorry, there must be at least 3 players.";
			}
			else {
				break;
			}
		}
		this->playersInGame = this->numPlayers;
		players = new Player[this->numPlayers];
	}
	//function calculates how many dice the rolling player gets, and based on dice results assigns chips.
	void playersRollDice() {
		for (int i = 0; i<this->numPlayers; i++) {
			if (this->players[i].hasChips()) {
				cout << "\nPlayer #" << (i + 1) << " please roll your dice" << endl;
				char *diceValues = this->players[i].rollDice(this->dice);
				int chips = this->players[i].getNumChips();
				for (int j = 0; j<chips; j++) {
					int p = j;
					switch (diceValues[j]) {
					case 'L':
						if (i == 0) {
							p = 2;
						}
						else {
							p = (i - 1) % this->numPlayers;
						}
						cout << "\t\tPlayer #" << (i + 1) << " passed a chip to Player #" << (p + 1) << "." << endl;
						this->players[i].loseChip();
						this->players[p].getChip();
						break;
					case 'C':
						cout << "\t\tPlayer #" << (i + 1) << " places a chip in the center pot." << endl;
						this->players[i].loseChipCenter();
						break;
					case 'R':
						p = (i + 1) % this->numPlayers;
						cout << "\t\tPlayer #" << (i + 1) << " passed a chip to Player #" << (p + 1) << "." << endl;
						this->players[i].loseChip();
						this->players[p].getChip();
						break;
					case '*':
						cout << "\t\tPlayer #" << (i + 1) << " kept a chip." << endl;
						break;
					}
				}
			}

			this->playersInGame = 0;
			for (int i = 0; i<this->numPlayers; i++) {
				if (this->players[i].hasChips()) {
					this->playersInGame++;
				}
			}
			if (this->playersInGame == 1) {
				break;
			}
		}
	}
	//while game is started, check for winner.
	void startGame() {
		while (this->playersInGame > 1) {
			this->playersRollDice();
		}
		if (this->playersInGame == 0) {
			cout << "\n\nThis game was a draw." << endl;
			return;
		}
		for (int i = 0; i<this->numPlayers; i++) {
			if (this->players[i].hasChips()) {
				cout << "\n\nPlayer #" << (i + 1) << " won the game!";
			}
		}
	}
};