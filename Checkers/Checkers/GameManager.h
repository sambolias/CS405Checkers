#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <ostream>
#include <iostream>
#include <vector>
#include <utility>
#include "Game.hpp"


extern class BoardDisplay;

class GameManager
{
public:
	bool moved = false;
	bool playing;
	BoardDisplay* display;
	Game game;
	GameManager(BoardDisplay* display_) : display(display_), playing(false) {}

	void startNewGame();

	void onTileClicked(int x, int y);
};

#endif
