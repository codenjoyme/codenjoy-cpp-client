#include "engine/AbstractBoard.h"
#include "Element.h"

class Board : public AbstractBoard
{
public:
    explicit Board(String boardString = LL("")) : AbstractBoard(boardString) { }

    String toString() const;

    bool isBarrierAt(int x, int y) const;

protected:
    virtual CharElement* valueOf(Char ch) const override;

private:
    PointList removeDuplicates(PointList lst) const;
};

