#include "GameManager.h"
#include "BoardDisplay.h"

#include <utility>
#include <QApplication>

// temporary to show use of gui
std::vector<std::vector<char>> generateBoard()
{
	std::vector<std::vector<char>> board(8, std::vector<char>(8));
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			board[x][y] = Board::EMPTY;
		}
	}
	return board;
}


void GameManager::startNewGame()
{
	playing = true;
	display->displayPieces(game.GetBoard());

	while (playing)
	{
		if (moved)
		{
			game.TakeNextTurn();
			if (game.IsOver())
				break;

			display->displayPieces(game.GetBoard());
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

	std::string winner = ((game.GetTurn() == game.RED_TURN) ? "BLACK" : "RED");
	std::cout << winner << " won\n";
	//game over clears board for now
	display->displayPieces(generateBoard());
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
