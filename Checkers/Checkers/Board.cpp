#include "Board.hpp"
using std::vector;
#include <iostream>
using std::cout;

const char Board::INVALID_SQUARE = '_';
const char Board::EMPTY = '-';
const char Board::RED = 'r';
const char Board::BLACK = 'b';
const char Board::K_RED = 'R';
const char Board::K_BLACK = 'B';

Board::Board()
{
    char r = Board::RED;
    char b = Board::BLACK;
    char e = Board::EMPTY;
    _board =
    { 
        r,r,r,r,
        r,r,r,r,
        r,r,r,r,
        e,e,e,e,
        e,e,e,e,
        b,b,b,b,
        b,b,b,b,
        b,b,b,b,
    };
}

vector<char> & Board::GetBoard()
{
    return _board;
}

vector<vector<char>> Board::GetBoardAsMatrix()
{
	vector<vector<char>> board(8, vector<char>(8,Board::INVALID_SQUARE));
	int index = 0;
	for (int row = 0; row < 8; ++row)
	{
		int columnOffset = row % 2;
		for (int column = columnOffset; column < 8; column += 2)
		{
			board[row][column] = _board[index++];
		}
	}
	return board;
}

char & Board::operator[](int index)
{
    return _board[index];
}

void Board::Print()
{
    int isValidSpot = true;
    int index = 0;
    int columCount = 0;
    while (index < _board.size())
    {
        if (isValidSpot)
        {
            cout << _board[index++];
        }
        else
        {
            cout << Board::INVALID_SQUARE;
        }
        if (++columCount >= 8)
        {
            cout << '\n';
            columCount = 0;
        }
        else
        {
            isValidSpot = !isValidSpot;
        }
    }
}