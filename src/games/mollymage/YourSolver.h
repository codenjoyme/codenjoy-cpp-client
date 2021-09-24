#ifndef YOURDIRECTIONSOLVER_H
#define YOURDIRECTIONSOLVER_H

#include "engine/utils.h"

#include "Element.h"
#include "Board.h"

#include "engine/DirectionSolver.h"
#include "engine/Direction.h"
#include "engine/Dice.h"
#include "engine/Point.h"

class YourSolver : public DirectionSolver
{
public:
    YourSolver(Dice* d) : dice(d) {}

    // From DirectionSolver
    virtual String get(String boardString);

private:
    Dice* dice;
};

#endif
