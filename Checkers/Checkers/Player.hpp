#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Board.hpp"
#include "MovementGenerator.hpp"
#include <vector>
#include <memory>
#include <iostream>

class Player
{
private:
    char _color;
    bool _moved;
    MovementGenerator _movementGenerator;
public:
    Player(char color);
    std::vector<std::shared_ptr<Movement>> GenerateMoves(Board & board);
    Board & TakeTurn(Board & board, std::vector<std::shared_ptr<Movement>> & moves);
};

#endif