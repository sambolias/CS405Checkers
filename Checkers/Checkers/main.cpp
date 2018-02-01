#include "BoardDisplay.h"
#include "checkers.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	BoardDisplay board;
	Game game = Game();

	while (!game.gameOver)
	{
		game.calculateMoves();

		board.display();
		board.displayPieces(game.getBoard());
	
		game.nextTurn();

	}

	std::string winner = ((game.turn != 0) ? "RED" : "BLACK");

	return a.exec();
}

