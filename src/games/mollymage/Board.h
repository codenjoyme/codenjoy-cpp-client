#include "engine/AbstractBoard.h"
#include "Element.h"

class Board : public AbstractBoard
{
public:
	explicit Board(String boardString = LL("")) : AbstractBoard(boardString) { }

	String toString() const;

	Point getHero() const;
	PointList getOtherHeroes() const;
	bool isMyHeroDead() const;

	PointList getBarriers() const;

	PointList getGhosts() const;

	PointList getWalls() const;
	PointList getTreasureBoxes() const;
	PointList getPotions() const;
	PointList getBlasts() const;

	PointList getFutureBlasts() const;

	bool isBarrierAt(int x, int y) const;

protected:
	virtual CharElement* valueOf(Char ch) const override;

private:
	PointList removeDuplicates(PointList lst) const;
};

