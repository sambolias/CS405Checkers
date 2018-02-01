#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>

class Board
{
private:
    std::vector<char> _board;
public:
    Board();
    std::vector<char> & GetBoard();
    char & operator[](int index);
    void Print();
    const static char INVALID_SQUARE;
    const static char EMPTY;
    const static char RED;
    const static char BLACK;
    const static char K_RED;
    const static char K_BLACK;
};

#endif