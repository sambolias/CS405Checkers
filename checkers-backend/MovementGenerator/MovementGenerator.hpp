#ifndef MOVEMENT_GENERATOR_H_INCLUDED
#define MOVEMENT_GENERATOR_H_INCLUDED

#include "../Board.hpp"
#include "../Movement/Movement.hpp"
#include "../Movement/RegularMovement.hpp"
#include "../Movement/JumpMovement.hpp"
#include <vector>
#include <unordered_map>
#include <memory>
#include <utility>

class MovementGenerator
{
protected:
    std::unordered_map<int,std::vector<int>> _legalRegularMoves;
    std::unordered_map<int,std::vector<int>> _legalJumpMoves;
public:
    // Generates a list of moves (needs to still generate jump moves)
    std::vector<std::shared_ptr<Movement>> GenerateMoves(int startPoint, Board & board, char opponentColor);
    int GetJumpEndPoint(int playerStartPoint, int opponentStartPoint);
    std::vector<std::shared_ptr<Movement>> & GenerateJumps(std::vector<std::shared_ptr<Movement>> & jumpMoves,
                                                                    Board & board, 
                                                                    std::shared_ptr<JumpMovement> jumpMovement, 
                                                                    char opponentColor);
};

#endif