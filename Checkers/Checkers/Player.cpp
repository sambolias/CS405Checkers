#include "Player.hpp"
#include <QDebug>
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::cout;

Player::Player(char color) : _color(color) {}

Board & Player::TakeTurn(Board & board, vector<shared_ptr<Movement>> & moves)
{
    if (moves.size())
    {
        int moveIndex = rand() % moves.size();
        auto move = moves[moveIndex];
        move->ToString();
        board = move->ExecuteMovement(board);
		return board.UpdateKings();
    }
    else
    {
        qDebug() << "There are no moves for " + _color << '\n';
        return board;
    }
}

vector<shared_ptr<Movement>> Player::GenerateMoves(Board & board)
{   
	auto moves = _movementGenerator.GenerateMoves(board, _color);
	qDebug() << ((_color == Board::BLACK) ? "BLACK's turn." : "RED's turn.");
	for (auto & move : moves)
	{
		qDebug() << QString((move->ToString()).c_str());
	}
	return moves;
}