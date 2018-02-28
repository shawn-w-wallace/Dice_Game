#include "stdafx.h"
#include "playerClass.h"
#include "diceClass.h"
#include "game.cpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#using <system.dll>  
using namespace std;
using namespace System;
using namespace System::IO;

int main(int argc, char *argv[]) {
	srand(time(NULL));
	Game lcrgame;
	lcrgame.displayRules();
	lcrgame.getNumPlayers();
	lcrgame.startGame();
	return 0;
}
