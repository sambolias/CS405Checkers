#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <ostream>
#include <iostream>
#include <vector>
#include "checkers.hpp"
#include <utility>

extern class BoardDisplay;

class GameManager
{
public:
	bool moved = false;
	std::vector<std::pair<int, int>> moves;
	bool playing;
	BoardDisplay* display;
	Game game;

	GameManager(BoardDisplay* display_) : display(display_), playing(false) {}

	void startNewGame();

	void onTileClicked(int x, int y);
};

#endif
