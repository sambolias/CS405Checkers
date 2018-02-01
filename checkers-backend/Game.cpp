#include "Game.hpp"
using std::vector;
using std::string;
using std::cout;

Game::Game()
{
    _players.push_back(Player(Board::RED));
    _players.push_back(Player(Board::BLACK));
}

void Game::Play()
{
    int turn = 0;
    const string BLACK("BLACK");
    const string RED("RED");
    while(true)
    {
        // Get moves list for current player
        auto moves = _players[turn].GenerateMoves(_board);
        // If moves exist, player takes turn
        if (moves.size())
        {
            string currentPlayerColor = (turn) ? BLACK : RED;
            cout << currentPlayerColor << "\'s turn.\n";

            _board = _players[turn].TakeTurn(_board, moves);
            turn = (turn) ? 0 : 1;
            _board.Print();
            cout << "\n\n";
        } 
        // If moves don't exist, the current player loses
        else
        {
            auto winner = (turn) ? RED : BLACK;
            auto loser = (turn) ? BLACK : RED;
            cout << loser << " cannot move.\n";
            cout << winner << " has won.\n";
            break;
        }
    }
}