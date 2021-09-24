#include "AbstractBoard.h"

AbstractBoard::AbstractBoard(String boardString) {
    for (auto i_str = boardString.find(LL('\n')); i_str != String::npos; i_str = boardString.find(LL('\n'))) {
        boardString.replace(i_str, 1, LL(""));
    }
    board = boardString;
    size = boardSize();
    xyl = LengthToXY(size);
}

CharElement* AbstractBoard::getAt(int x, int y) const {
    int index = xyl.getLength(x, y);
    return valueOf(board.at(index));
}

bool AbstractBoard::isAt(int x, int y, CharElement* el) const {
    if (Point(x, y).isBad(size)) return false;
    return getAt(x, y)->ch() == el->ch();
}

bool AbstractBoard::isAt(int x, int y, std::list<CharElement*> els) const {
    for (auto i : els) {
        if (isAt(x, y, i)) return true;
    }
    return false;
}

PointList AbstractBoard::findAll(CharElement* el) const {
    PointList rslt;
    for (auto i = 0; i < size * size; ++i) {
        Point pt = xyl.getXY(i);
        if (isAt(pt.getX(), pt.getY(), el)) {
            rslt.push_back(pt);
        }
    }
    return rslt;
}

int AbstractBoard::boardSize() const {
    return std::sqrt(board.length());
}

String AbstractBoard::boardAsString() const {
    StringStream ss;
    for (auto i = 0; i < board.length(); ++i) {
        ss << board.at(i);
        if ((i + 1) % size == 0) {
            ss << LL('\n');
        }
    }
    return ss.str();
}

bool AbstractBoard::isNear(int x, int y, CharElement* el) const {
    if (Point(x, y).isBad(size)) return false;
    PointList nears = Point(x, y).getSurrounds(size);
    bool res = false;
    for (auto pt : nears) {
        res = res || isAt(pt.getX(), pt.getY(), el);
    }
    return res;
}

int AbstractBoard::countNear(int x, int y, CharElement* el) const {
    PointList nearp = Point(x, y).getSurrounds(size);
    int count = 0;
    for (auto p : nearp) {
        if (isAt(p.getX(), p.getY(), el)) {
            ++count;
        }
    }
    return count;
}
