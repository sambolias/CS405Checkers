#ifndef BOARD_DISPLAY_H
#define BOARD_DISPLAY_H

#include "TileDisplay.h"
#include "GameManager.h"
#include <QWidget>
#include <QAction>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <cctype>

class BoardDisplay : public QMainWindow
{
	Q_OBJECT
private:
	virtual QSize sizeHint() const { return QSize(2400, 1400); }

public slots:
	void start();

public:
	TileDisplay * tiles[8][8];
	QWidget* widget;
	GameManager * manager;

	BoardDisplay();

	void display();
	void displayPieces(std::vector<std::vector<char>> board);
};
#endif