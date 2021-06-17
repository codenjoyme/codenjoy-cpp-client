#ifndef DIRECTIONSOLVER_H
#define DIRECTIONSOLVER_H

#include "utils.h"
#include "AbstractBoard.h"

class DirectionSolver {
public:
	virtual String get(String board) = 0;
};

#endif
