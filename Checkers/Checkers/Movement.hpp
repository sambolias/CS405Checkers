#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED

#include "Board.hpp"
#include <string>

class Movement
{
public:
    virtual Board & ExecuteMovement(Board & board) = 0;
	virtual std::string ToString() { return ""; }
};

#endif