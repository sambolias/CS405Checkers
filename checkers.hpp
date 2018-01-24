#pragma once
#include<vector>
#include<utility>

class Piece
{
    bool king;
    int row, col;
public:
    Piece(int r, int c);
    void move(int r, int c);
};


class Player
{
    std::vector<Piece> pieces;
public:
    Player(int color);
    void move(std::pair<int, int> from, std::pair<int, int> to);
};

class Board
{
    std::vector<std::vector<char>> squares;
    
public:
    Board();
    //board(std::vector<std::vector<char>> & saved) for save

    void updateBoard(Player &a, Player &b);
    bool checkMove(std::pair<int, int> from, std::pair<int, int> to);
    std::vector<std::vector<char>> getBoard();
};

class Game
{
    std::vector<Player> players;
    Board board;
    
    void draw();
    std::pair<std::pair<int, int>, std::pair<int, int>> getMove();

public:
    Game();
    void play();

};

