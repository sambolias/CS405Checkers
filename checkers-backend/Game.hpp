#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Board.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>
#include <string>

class Game
{
private:
    Board _board;
    std::vector<Player> _players;
public:
    Game();
    void Play();
};

#endif