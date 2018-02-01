#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED

#include "Board.hpp"

class Movement
{
public:
    virtual Board & ExecuteMovement(Board & board) = 0;
    virtual void Print() {}
};

#endif