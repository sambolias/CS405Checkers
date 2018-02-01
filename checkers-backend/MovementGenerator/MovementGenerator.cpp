#include "MovementGenerator.hpp"
using std::vector;
using std::make_shared;
using std::shared_ptr;
using std::unordered_map;

vector<shared_ptr<Movement>> MovementGenerator::GenerateMoves(int startPoint, Board & board, char opponentColor)
{
    vector<shared_ptr<Movement>> movements;       
    if (_legalRegularMoves.count(startPoint))
    {
        auto movementEndPoints = _legalRegularMoves[startPoint];
        for (auto endPoint : movementEndPoints)
        {
            // Check for jumps
            if (board[endPoint] == opponentColor)
            {
                int opponentPosition = endPoint;
                int jumpEndPoint = GetJumpEndPoint(startPoint, opponentPosition);
                if (jumpEndPoint >= 0 && board[jumpEndPoint] == Board::EMPTY)
                {
                    auto jumpMovement = make_shared<JumpMovement>(startPoint, jumpEndPoint, opponentPosition);
                    movements = GenerateJumps(movements, board, jumpMovement, opponentColor);
                }
            }
            // Check for regular moves
            else if (board[endPoint] == Board::EMPTY)
            {
                auto move = make_shared<RegularMovement>(startPoint, endPoint);
                movements.push_back(move);
            }
        }
    }
    return movements;
}

// finds the common space between a player's jump point and the opponent's starting position
// ex. for RED to jump from 1-10, there needs to be an opponent at space 5
int MovementGenerator::GetJumpEndPoint(int playerStartPoint, int opponentStartPoint)
{
    if (_legalJumpMoves.count(playerStartPoint) && _legalRegularMoves.count(opponentStartPoint))
    {
        auto jumpEndPoints = _legalJumpMoves[playerStartPoint];
        auto opponentEndPoints = _legalRegularMoves[opponentStartPoint];
        for (auto jumpEndPoint : jumpEndPoints)
        {
            for (auto opponentEndPoint : opponentEndPoints)
            {
                if (jumpEndPoint == opponentEndPoint)
                {
                    return jumpEndPoint;
                }
            }
        }
    }
    return -1;
}

vector<shared_ptr<Movement>> & MovementGenerator::GenerateJumps(vector<shared_ptr<Movement>> & jumpMoves,
                                                                 Board & board, 
                                                                 shared_ptr<JumpMovement> jumpMovement, 
                                                                 char opponentColor)
{
    // starting from the end of the last jump
    int startPosition = jumpMovement->GetEndPosition();
    if (_legalRegularMoves.count(startPosition))
    {
        auto postionsOneAway = _legalRegularMoves[startPosition];
        for (auto positionOneAway : postionsOneAway)
        {
            bool canJump = false;
            // check if position one away from start is opponent and if it hasn't been jumped already
            if (board[positionOneAway] == opponentColor && jumpMovement->ContainsJumpedPiece(positionOneAway) == false)
            {
                int opponentPosition = positionOneAway;
                int jumpEndPoint = GetJumpEndPoint(startPosition, opponentPosition);
                if (jumpEndPoint >= 0 && board[jumpEndPoint] == Board::EMPTY)
                {
                    canJump = true;
                    int start = jumpMovement->GetStartPosition();
                    auto newJump = make_shared<JumpMovement>(start, jumpEndPoint, opponentPosition);
                    newJump->AddJumpedPieces(std::move(jumpMovement->GetJumpedPieces()));
                    jumpMoves = GenerateJumps(jumpMoves, board, newJump, opponentColor);
                }
            }
            if (canJump == false)
            {
                jumpMoves.push_back(jumpMovement);
            }
        }
    }
    return jumpMoves; 
}