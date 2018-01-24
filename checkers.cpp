#include<vector>
using std::vector;  
using matrix = std::vector<std::vector<char>>;
#include<utility>
using std::pair;
using vec2 = pair<int, int>;
#include<iostream>
using std::cout;
#include"checkers.hpp"


/*** Piece Class Definitions ***/
Piece::Piece(int r, int c)
{

}
void Piece::move(int r, int c)
{

}

/*** Player Class Definitions ***/
Player::Player(int color)
{

}
void Player::move(vec2 from, vec2 to)
{

}


/*** Board Class Definitions ***/
Board::Board()
{
    squares = matrix(8, vector<char>(8, '-'));
}
void Board::updateBoard(Player &a, Player &b)
{

}
bool Board::checkMove(vec2 from, vec2 to)
{
    return false;
}
matrix Board::getBoard()
{
    return squares;
}


/*** Game Class Definitions ***/
enum class COLOR { RED, BLACK };
Game::Game()
{
    board = Board();
    players.push_back(Player(int(COLOR::RED)));
    players.push_back(Player(int(COLOR::BLACK)));
}
void Game::draw()
{
    matrix m = board.getBoard();
    for(auto row : m)
    {
        for(auto col : row)
        {
            cout<<col;
        }
        cout<<"\n";
    }
}
pair<vec2, vec2> getMove()
{
    //dummy
    return pair<vec2, vec2>(vec2(0,0), vec2(0,0));
}
void Game::play()
{
    draw();
}

int main()
{
    Game game = Game();
    game.play();
    return 0;
}
 