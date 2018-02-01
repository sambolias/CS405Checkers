#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Board.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>
#include <string>

class Game
{
private:
    Board _board;
    std::vector<Player> _players;
	bool _isOver;
	int _turn;
public:
	const int RED_TURN;
	const int BLACK_TURN;
    Game();
	void TakeNextTurn();
	Board & GetBoard();
	bool IsOver();
	int GetTurn();
};

#endif