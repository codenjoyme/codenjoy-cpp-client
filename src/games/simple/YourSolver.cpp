#include <iostream>
#include "YourSolver.h"


String YourSolver::get(String boardString)
{
    Board board(boardString);
    std::wcout << board.toString();
    return L"ACT";
}
