#include "engine/AbstractBoard.h"
#include "Element.h"

class Board : public AbstractBoard
{
public:
	explicit Board(String boardString = LL("")) : AbstractBoard(boardString) { }

	String toString() const;

	Point getHero() const;
	PointList getOtherHeroes() const;
	PointList getEnemyHeroes() const;
	PointList getRobbers() const;
	bool isMyHeroDead() const;

	PointList getBarriers() const;
	bool isBarrierAt(int x, int y) const;

	PointList getPits() const;
	PointList getClues() const;
	PointList getBackways() const;
	PointList getPotions() const;

protected:
	virtual CharElement* valueOf(Char ch) const override;
};

