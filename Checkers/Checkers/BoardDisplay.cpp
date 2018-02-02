#include "BoardDisplay.h"
#include <iostream>

BoardDisplay::BoardDisplay()
{
	manager = new GameManager(this);
	widget = new QWidget(this);
	this->setCentralWidget(widget);

	// todo when move is submitted the move is passed to text file
	moveText = new QLineEdit(this);
	moveText->setFixedSize(300, 600);
	
	// menu bar, mostly for later in the project when more options such as loading are required
	QMenu* menuGame = new QMenu("Game");
	QAction* startAction = menuGame->addAction("Start");
	connect(startAction, SIGNAL(triggered()), this, SLOT(start()));

	// save game
	QAction* saveAction = menuGame->addAction("Save");
	connect(saveAction, SIGNAL(triggered()), this, SLOT(saveGame()));

	// load game
	QAction* loadAction = menuGame->addAction("Load");
	connect(saveAction, SIGNAL(triggered()), this, SLOT(loadGame()));

	//exit application todo check to save or export your files
	QAction* exitAction = menuGame->addAction("Exit");
	connect(exitAction, SIGNAL(triggered()), this, SLOT(exitGame()));

	QMenuBar* mainMenu = this->menuBar();
	mainMenu->addMenu(menuGame);
}

void BoardDisplay::display()
{
	int horizontal = 350;
	for (int x = 0; x < 8; x++)
	{
		int vertical = 125;
		for (int y = 0; y < 8; y++)
		{
			tiles[x][y] = new TileDisplay(x, y, manager, widget);
			tiles[x][y]->color = (x + y) % 2;
			tiles[x][y]->display();
			tiles[x][y]->setGeometry(horizontal, vertical, 64, 64);
			vertical += 64;
		}
		horizontal += 64;
	}
	this->show();
}

void BoardDisplay::displayPieces(std::vector<std::vector<char>> board)
{
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			// todo update this for whatever type of board is being passed in, but it should work as is
			char type = board[x][y];
			if (type == Board::EMPTY || type == Board::INVALID_SQUARE)
			{
				tiles[x][y]->removePiece();
			}
			else
			{
				int color = std::tolower(type) == Board::RED; // black = 0, red = 1
				bool king = std::isupper(type); // king or not
				tiles[x][y]->displayPiece(color, king);
			}
		}
	}
}

void BoardDisplay::start()
{
	std::cout << "game started" << std::endl;
	manager->startNewGame();
}

void BoardDisplay::exitGame()
{
	exit(1);
}


void BoardDisplay::saveGame()
{

}

void BoardDisplay::loadGame()
{
	
}
