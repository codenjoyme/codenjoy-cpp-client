#ifndef BOARD_H
#define BOARD_H

#include "utils.h"

#include "Point.h"
#include "LengthToXY.h"
#include "CharElement.h"

class AbstractBoard {
public:
    AbstractBoard(String boardString = LL(""));

    CharElement* getAt(int x, int y) const;
    bool isAt(int x, int y, CharElement* el) const;
    bool isAt(int x, int y, std::list<CharElement*> els) const;

    int boardSize() const;

    bool isNear(int x, int y, CharElement* el) const;
    int countNear(int x, int y, CharElement* el) const;

protected:
    PointList findAll(CharElement* el) const;
    String boardAsString() const;
    virtual CharElement* valueOf(Char ch) const = 0;

    String board;
    int size;
    LengthToXY xyl;
};

#endif
