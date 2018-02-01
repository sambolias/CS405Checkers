#ifndef REGULAR_MOVEMENT_H_INCLUDED
#define REGULAR_MOVEMENT_H_INCLUDED

#include "Movement.hpp"

class RegularMovement : public Movement
{
private:
    int _start;
    int _end;
public:
    RegularMovement(int start, int end) : _start(start), _end(end) {}
    Board & ExecuteMovement(Board & board) override;
    void Print() override;
};

#endif