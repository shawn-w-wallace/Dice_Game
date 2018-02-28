/*
The biggest issue I had with the project was the Player class, specifically the player array and how chips are handled.
I did not have an issue assigning the class the chips variable or initializing that variable to 3. Instead the issue
was understanding the syntax of constructing an array from user input.  I consistently had errors saying that (variable)
this cannot point to a value of (blank) data type.  Issues along those lines.  I had to do some additional research to
understand arrays, for some reason I just wasn't wrapping my head around it.  I eventually solved the issue when I realized
that I would have make a pointer variable of the player class and use it to create an array from the user input so that it
would be a part of the player class.  Another issue I had was passing chips between players.  What helped me through this
issue was thinking of the dice rolling function as an iteration.  I had to look at it and say, "ok during this iteration
of the function I am "doing stuff to" X player of the player class in the player array.  What does the player class do to
X player during this iteration of the function?"  That is when I understand that the player class needed to call on the
functions of dice rolling loop to update the chip values of the players in the player array who are a part of the player
class.
*/



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