#include "GameManager.h"
#include "BoardDisplay.h"

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



	// todo 
	// this is all temporary for testing
	// board use example
	std::vector<std::vector<char>> matrix = generateBoard();
	matrix[2][3] = 'R';
	display->displayPieces(matrix);
}


void GameManager::onTileClicked(int x, int y)
{
	std::cout << x << ", " << y << std::endl;
}
