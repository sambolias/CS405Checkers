#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <ostream>
#include <iostream>
#include <vector>

extern class BoardDisplay;

class GameManager
{
public:

	bool playing;
	BoardDisplay* display;

	GameManager(BoardDisplay* display_) : display(display_), playing(false) {}

	void startNewGame();

	void onTileClicked(int x, int y);
};

#endif
