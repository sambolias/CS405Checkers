#include "Player.hpp"
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::cout;

Player::Player(char color) : _color(color)
{
    if (color == Board::RED)
    {
        _movementGenerator = make_shared<RedMovementGenerator>();
        _opponentColor = Board::BLACK;
    }
    else
    {
        if (color != Board::BLACK)
        {
            cout << "Player color (" << color << ") not recognized. Defaulting to BLACK.\n";
        }
        _movementGenerator = make_shared<BlackMovementGenerator>();
        _opponentColor = Board::RED;
    }
}

Board & Player::TakeTurn(Board & board, vector<shared_ptr<Movement>> & moves)
{
    if (moves.size())
    {
        int moveIndex = rand() % moves.size();
        auto move = moves[moveIndex];
        move->Print();
        return move->ExecuteMovement(board);
    }
    else
    {
        cout << "There are no moves for " + _color << '\n';
        return board;
    }
}

vector<shared_ptr<Movement>> Player::GenerateMoves(Board & board)
{   
    vector<shared_ptr<Movement>> movements;
    for (int boardIndex = 0; boardIndex < board.GetBoard().size(); ++boardIndex)
    {
        if (board[boardIndex] == _color)
        {
            auto boardPieceMoves = _movementGenerator->GenerateMoves(boardIndex, board, _opponentColor);
            for (auto & move : boardPieceMoves)
            {
                movements.push_back(move);
            }
        }
    }
    return movements;
}