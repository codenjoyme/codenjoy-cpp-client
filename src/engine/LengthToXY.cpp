#include "LengthToXY.h"


LengthToXY::LengthToXY(int _boardSize) : boardSize(_boardSize) {
}

Point LengthToXY::getXY(int length) const {
    if (length < 0) {
        throw std::invalid_argument("LengthToXY::getXY(int length): length cant be <= 0!");
    }
    return Point(length % boardSize, (boardSize - length / boardSize) - 1);
}

int LengthToXY::getLength(int _x, int _y) const {
    return (boardSize - 1 - _y) * boardSize + _x;
}
