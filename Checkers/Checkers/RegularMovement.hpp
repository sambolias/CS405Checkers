#ifndef REGULAR_MOVEMENT_H_INCLUDED
#define REGULAR_MOVEMENT_H_INCLUDED

#include "Movement.hpp"
#include <string>

class RegularMovement : public Movement
{
private:
    int _start;
    int _end;
public:
    RegularMovement(int start, int end) : _start(start), _end(end) {}
    Board & ExecuteMovement(Board & board) override;
    std::string ToString() override;
};

#endif