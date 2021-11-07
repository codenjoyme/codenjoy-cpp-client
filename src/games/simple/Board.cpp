#include "Board.h"

String pointListToString(PointList lst) {
    StringStream ss;
    for (Point i : lst) {
        ss << i.toString() << " ";
    }
    return ss.str();
}

String Board::toString() const {
    StringStream ss;
    ss << LL("Board:\n") << AbstractBoard::boardAsString() << LL("\n");
    return ss.str();
}

CharElement* Board::valueOf(Char ch) const {
    return new Element(ch);
}

bool Board::isBarrierAt(int x, int y) const {
    Point p(x, y);
    if (p.isBad(size)) return false;

    PointList barriers = getBarriers();
    for (auto b : barriers) {
        if (b == p) return true;
    }
    return false;
}

