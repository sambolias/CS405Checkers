#include "JumpMovement.hpp"
#include <iostream>
using std::map;
using std::cout;

JumpMovement::JumpMovement(int start, int end, int jumpedPiece) : JumpMovement(start,end)
{
    AddJumpedPiece(jumpedPiece);
}

bool JumpMovement::isValidJumpedPiece(int jumpedPiece)
{
    return (jumpedPiece < 32 && jumpedPiece >= 0);
}

Board & JumpMovement::ExecuteMovement(Board & board)
{
    for (const auto & jumpedPiece : _jumpedPieces)
    {
    	int key = jumpedPiece.first;
    	board[key] = Board::EMPTY;
    }
    board[_end] = board[_start];
    board[_start] = Board::EMPTY;
    return board;
}

void JumpMovement::Print()
{
    cout << "Jump Movement (start, end): (" << _start << ", " << _end << ")\n";
    cout << "Jumped Pieces: ";
    bool firstPiece = true;
    for (const auto jumpedPiece : _jumpedPieces)
    {
        if (firstPiece == false)
        {
            cout << ", " << jumpedPiece.first;
        }
        else
        {
            cout << jumpedPiece.first;
            firstPiece = false;
        }
    }
    cout << '\n';
}

int JumpMovement::GetStartPosition()
{
    return _start;
}

int JumpMovement::GetEndPosition()
{
    return _end;
}

map<int,bool> JumpMovement::GetJumpedPieces()
{
    return _jumpedPieces;
}

void JumpMovement::SetStartPosition(int startPosition)
{
    _start = startPosition;
}

void JumpMovement::SetEndPosition(int endPosition)
{
    _end = endPosition;
}

void JumpMovement::AddJumpedPiece(int jumpedPiece)
{
    if (isValidJumpedPiece(jumpedPiece))
    {
        _jumpedPieces[jumpedPiece] = true;
    }
}

void JumpMovement::AddJumpedPieces(map<int,bool> && jumpedPieces)
{
    for (const auto jumpedPiece : jumpedPieces)
    {
    	_jumpedPieces[jumpedPiece.first] = jumpedPiece.second;
    }
}


bool JumpMovement::ContainsJumpedPiece(int jumpedPiece)
{
    return (_jumpedPieces.count(jumpedPiece));
}