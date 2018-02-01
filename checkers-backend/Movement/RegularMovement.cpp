#include "RegularMovement.hpp"
#include <iostream>
using std::cout;

Board & RegularMovement::ExecuteMovement(Board & board)
{
    board[_end] = board[_start];
    board[_start] = Board::EMPTY;
    return board;
}

void RegularMovement::Print()
{
    cout << "Regular Movement (start, end): (" << _start << ", " << _end << ")\n";
}
