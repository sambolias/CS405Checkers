#ifndef JUMP_MOVEMENT_H_INCLUDED
#define JUMP_MOVEMENT_H_INCLUDED

#include "Movement.hpp"
#include <map>

class JumpMovement : public Movement
{
private:
    int _start;
    int _end;
    std::map<int,bool> _jumpedPieces;
    bool isValidJumpedPiece(int jumpedPiece);
public:
    JumpMovement(int start, int end) : _start(start), _end(end) {}
    JumpMovement(int start, int end, int jumpedPiece);
    int GetStartPosition();
    int GetEndPosition();
    std::map<int,bool> GetJumpedPieces();
    void SetStartPosition(int startPosition);
    void SetEndPosition(int endPosition);
    void AddJumpedPiece(int jumpedPiece);
    void AddJumpedPieces(std::map<int,bool> && jumpedPieces);
    bool ContainsJumpedPiece(int jumpedPiece);
    Board & ExecuteMovement(Board & board) override;
    void Print() override;
};

#endif