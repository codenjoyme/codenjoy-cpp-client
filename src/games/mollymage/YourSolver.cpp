#include <iostream>
#include "YourSolver.h"


String YourSolver::get(String boardString)
{
	Board board(boardString);
	String b = board.toString();
	std::wcout << b;
	return L"ACT";
}
