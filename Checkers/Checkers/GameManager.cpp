#include "GameManager.h"
#include "BoardDisplay.h"

#include <utility>
using std::pair;
#include <QApplication>
#include "checkers.hpp"

// temporary to show use of gui
std::vector<std::vector<char>> generateBoard()
{
	std::vector<std::vector<char>> board(8, std::vector<char>(8));
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			board[x][y] = '-';
		}
	}
	return board;
}


void GameManager::startNewGame()
{
	playing = true;

	game = Game();
	std::vector<std::vector<char>> matrix = game.getBoard();
	display->displayPieces(matrix);

	while (!game.gameOver && playing)
	{
		if (moved)
		{
			game.calculateMoves();
			game.chooseRandom();
			game.nextTurn();
			matrix = game.getBoard();
			display->displayPieces(matrix);
			moved = false;
			/*if(!game.getPlayer().comp)	//only wait for move if not computer player
				moved = false;
			else
			{
				game.chooseRandom();
				game.nextTurn();
			}*/
			
		}

		QApplication::processEvents();	

	}

	std::string winner = ((game.turn != 0) ? "RED" : "BLACK");
	std::cout << winner << " won\n";
	//game over clears board for now
	matrix = generateBoard();
	display->displayPieces(matrix);
	
}


void GameManager::onTileClicked(int x, int y)
{
	std::cout << x << ", " << y << std::endl;
	moved = true;
	/*if (moves.size() == 0)
	{
		moves.push_back(std::pair<int, int>(x, y));
	}
	else if (moves.size() == 1)
	{
		moves.push_back(std::pair<int, int>(x, y));
		moved = game.selectMove(moves[0], moves[1]);
		std::vector<std::vector<char>> matrix = game.getBoard();
		display->displayPieces(matrix);
		game.nextTurn();
		moves.clear();
	}*/
	
}
