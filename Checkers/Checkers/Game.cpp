#include "Game.hpp"
using std::vector;
using std::string;
using std::cout;

Game::Game(): RED_TURN(0), BLACK_TURN(1)
{
    _players.push_back(Player(Board::RED));
    _players.push_back(Player(Board::BLACK));
	_turn = RED_TURN;
	_isOver = false;
}

bool Game::IsOver()
{
	return _isOver;
}

void Game::TakeNextTurn()
{
	auto moves = _players[_turn].GenerateMoves(_board);
	if (moves.size())
	{
		_board = _players[_turn].TakeTurn(_board, moves);
		_turn = (_turn == BLACK_TURN) ? RED_TURN : BLACK_TURN;
	}
	else
	{
		_isOver = true;
	}
}

Board & Game::GetBoard()
{
	return _board;
}

int Game::GetTurn()
{
	return _turn;
}