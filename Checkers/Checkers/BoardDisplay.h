#ifndef BOARD_DISPLAY_H
#define BOARD_DISPLAY_H

#include "TileDisplay.h"
#include "GameManager.h"
#include "Board.hpp"
#include <QWidget>
#include <QAction>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <cctype>
#include <fstream>

class BoardDisplay : public QMainWindow
{
	Q_OBJECT
private:
	virtual QSize sizeHint() const { return QSize(1200, 700); }

public slots:
	void start();
	void exitGame();
	void saveGame();
	void loadGame();

public:
	TileDisplay * tiles[8][8];
	QWidget* widget;
	GameManager * manager;
	QLineEdit* moveText; // text of the moves that have transpired
	BoardDisplay();

	void display();
	void displayPieces(std::vector<std::vector<char>> board);
};
#endif