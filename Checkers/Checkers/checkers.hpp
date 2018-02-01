#pragma once
#include<vector>
#include<utility>

class Piece
{
    bool king;
    int row, col;
public:
    Piece(int r, int c);
    std::pair<int, int> getPos();
    void move(std::pair<int, int> to);
};

class Board;
class Player
{
public: //bad
    int color;                  //from              //to
    std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> moves;

    std::vector<Piece> pieces;    //needs interface with board so this can be private 
    Player(int color);
    std::vector<std::vector<char>> getMoves(const Board & board);
    void selectMove(int move);
    //void move(int piece, std::pair<int, int> to);
};

class Board
{
    std::vector<std::vector<char>> squares;
    
public:
    Board();
    Board(const std::vector<Player> &players);
    //board(std::vector<char> & saved) for save

    void updateBoard(const std::vector<char> &move);
    bool checkMove(std::pair<int, int> from, std::pair<int, int> to) const;
    std::vector<char> getTranslatedArray(std::pair<int, int> from, std::pair<int, int> to) const;
    std::vector<std::vector<char>> getBoard();
    //std::vector<char> getArray();
};

class Game
{
    std::vector<Player> players;
    
    Board board;
    
    void draw();
    //std::vector<std::vector<char>> getMoves(Player & player);

public:
	//public for now
	int turn = 0;
	bool gameOver = false;
	std::vector<std::vector<char>> moves;
	//

    Game();
    void play();
	//replacing play() as main loop must be in display main
	void calculateMoves();
	//we may want to make this return an int to indicate bad move or incomplete move (jumping)
	bool selectMove(std::pair<int, int> from, std::pair<int, int> to);
	void nextTurn();

	std::vector<std::vector<char>> getBoard();

};

