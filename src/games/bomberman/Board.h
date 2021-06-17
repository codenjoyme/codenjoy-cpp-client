#include "engine/AbstractBoard.h"
#include "Element.h"

class Board : public AbstractBoard
{
public:
	explicit Board(String boardString = LL("")) : AbstractBoard(boardString) { }

	String toString() const;

	Point getBomberman() const;
	PointList getOtherBombermans() const;
	bool isMyBombermanDead() const;

	PointList getBarriers() const;

	PointList getMeatChoppers() const;

	PointList getWalls() const;
	PointList getDestoyWalls() const;
	PointList getBombs() const;
	PointList getBlasts() const;

	PointList getFutureBlasts() const;

	bool isBarrierAt(int x, int y) const;

protected:
	virtual CharElement* valueOf(Char ch) const override;

private:
	PointList removeDuplicates(PointList lst) const;
};

