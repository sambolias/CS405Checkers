#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Board.hpp"
#include "MovementGenerator/MovementGenerator.hpp"
#include "MovementGenerator/RedMovementGenerator.hpp"
#include "MovementGenerator/BlackMovementGenerator.hpp"
#include <vector>
#include <memory>
#include <iostream>

class Player
{
private:
    char _color;
    char _opponentColor;
    bool _moved;
    std::shared_ptr<MovementGenerator> _movementGenerator;
public:
    Player(char color);
    std::vector<std::shared_ptr<Movement>> GenerateMoves(Board & board);
    Board & TakeTurn(Board & board, std::vector<std::shared_ptr<Movement>> & moves);
};

#endif