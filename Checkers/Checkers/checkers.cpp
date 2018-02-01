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
Piece::Piece(int r, int c): row(r), col(c), king(false)
{}
vec2 Piece::getPos()
{
    return {row, col};
}
void Piece::move(vec2 to)
{
    row = to.first;
    col = to.second;
}

/*** Player Class Definitions ***/
Player::Player(int c): color(c)
{
    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            //skip if red square
            if(!(row%2) && !(col%2))  //even rows have even red spaces
                continue; 
            if((row%2) && (col%2))  //odd rows have odd red spaces
                continue; 

            if(c == 0 && row <= 2) //red gets top 3 rows
                pieces.push_back(Piece(row, col));
            if(c == 1 && row >= 5)  //black gets bottom 3
                pieces.push_back(Piece(row, col));
        }
    }
}
vector<vector<char>> Player::getMoves(const Board & board)
{
    vector<pair<vec2,vec2>> coords;
    vector<vector<char>> boards;
    int direction = (color) ? -1 : 1;
    for(auto piece : pieces)
    {
        vec2 from = piece.getPos();
        vec2 to = { from.first + direction,
                    from.second + 1};
        //TODO add jump logic
        if(board.checkMove(from, to))
        {
            coords.push_back(pair<vec2,vec2>(from, to));
            boards.push_back(board.getTranslatedArray(from, to));
        }
        //sloppy
        to = { from.first + direction,
                    from.second - 1};
        //TODO add jump logic
        if(board.checkMove(from, to))
        {
            coords.push_back(pair<vec2,vec2>(from, to));
            boards.push_back(board.getTranslatedArray(from, to));
        }
    }
    moves = coords;
    return boards;
}

void Player::selectMove(int move)
{
    for(int i = 0; i < pieces.size(); i++)
    {
        if(moves[move].first == pieces[i].getPos())
        {
            pieces[i].move(moves[move].second);
        }
    }
}
// //TODO delete this function
// void Player::move(int piece, vec2 to)
// {

// }


/*** Board Class Definitions ***/
Board::Board()
{
    squares = matrix(8, vector<char>(8, '-'));
}
Board::Board(const vector<Player> & players)
{
    squares = matrix(8, vector<char>(8, '-'));
    for(auto player : players)
    {
        char color = (player.color)? 'b' : 'r'; //red is 0
        for(auto piece : player.pieces)
        {
            vec2 pos = piece.getPos();
            squares[pos.first][pos.second] = color;
        }
    }
}
void Board::updateBoard(const vector<char> &move)
{
    cout<<move.size()<<"\n";
    int i = 0;
    int r = 0;
    int c = 0;
    for(auto row : squares)
    {   c=0;
        for(auto col : row)
        {
            //skip if red square
            if(!(r%2) && !(c%2))  //even rows have even red spaces
             { c++; continue; }
            if((r%2) && (c%2))  //odd rows have odd red spaces
             { c++; continue; }

            char square = move[i];
            if(square == ' ')
                square = '-';
            squares[r][c] = square;
            i++;
            c++;
        }
        r++;
    }
}
bool Board::checkMove(vec2 from, vec2 to) const
{
    int r1 = from.first;
    int c1 = from.second;
    int r2 = to.first;
    int c2 = to.second;

    //off board
    if(r2 > 7 || r2 < 0)
        return false;
    if(c2 > 7 || c2 < 0)
        return false;

    if(squares[r2][c2] != '-')  //blank space
        return false;
    //TODO add jump logic
    //TODO check to see if black space **or opponent could cheat**
    return true;
}
//TODO this function needs to consider jumps, or they need considered elsewhere in process
vector<char> Board::getTranslatedArray(vec2 from, vec2 to) const
{
    vector<char> translated;
    //this iteration through board will be repeated, iterator?
    int r = 0;
    int c = 0;
    char movedColor = squares[from.first][from.second];
    for(auto row : squares)
    {
        c=0;
        for(auto col : row)
        {
            char square = col;
            if(square == '-')
                square = ' ';
            if(r == from.first && c == from.second)
                square = ' ';
            if(r == to.first && c == to.second)
                square = movedColor;
            //write if black square
            if(!(r%2) && (c%2))  //even rows have odd black spaces
                translated.push_back(square);
            if((r%2) && !(c%2))  //odd rows have even black spaces
                translated.push_back(square);
            c++;
        }
        r++;
    }
    return translated;
}
matrix Board::getBoard()
{
    return squares;
}


/*** Game Class Definitions ***/
enum class COLOR { RED, BLACK };
Game::Game()
{  
    players.push_back(Player(int(COLOR::RED)));
    players.push_back(Player(int(COLOR::BLACK)));
    board = Board(players);
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

//TODO delete this function
// vector<vector<char>> Game::getMoves(Player & player)
// {
//     return player.getMoves(board);
// }

void Game::play()
{
    int turn = 0; //player 0 is RED 
    draw();
    system("sleep 1");
    
    while(true)
    {
        vector<vector<char>> moves;
        moves = players[turn].getMoves(board);
        //if no moves possible game over
        if(moves.size() == 0)
            break;
        //otherwise choose random move
        int choice = rand() % moves.size();
        //TODO when jump logic goes in 
        //taken pieces need removed at this point
        players[turn].selectMove(choice);
        board.updateBoard(moves[choice]);
        system("clear");
        draw();
        cout<<moves.size()<<"\n";
        if(turn < 1)
            turn++;
        else turn = 0;
        system("sleep 2");
        
    }

    cout<<"GAME OVER - "<<((turn!=0)?"RED":"BLACK")<<" won\n";

}

void Game::calculateMoves()
{
	moves = players[turn].getMoves(board);
	//if no moves possible game over
	if (moves.size() == 0)
	{
		gameOver = true;
		return;
	}
	//otherwise choose random move
	int choice = rand() % moves.size();
	//TODO when jump logic goes in 
	//taken pieces need removed at this point
	players[turn].selectMove(choice);
	board.updateBoard(moves[choice]);
}



bool Game::selectMove(std::pair<int, int> from, std::pair<int, int> to)
{
	return false;
}

void Game::nextTurn()
{
	if (turn < 1)
		turn++;
	else turn = 0;
}

std::vector<std::vector<char>> Game::getBoard()
{
	return board.getBoard();
}

/*int main()
{
    Game game = Game();
    game.play();
    return 0;
}*/
 