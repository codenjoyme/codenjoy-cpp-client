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
	ss << LL("Board:\n") << AbstractBoard::boardAsString() << LL("\n")
		<< LL("Bomberman at: ") << getBomberman().toString() << LL("\n")
		<< LL("Other Bombermans at: ") << pointListToString(getOtherBombermans()) << LL("\n")
		<< LL("Meat choppers at: ") << pointListToString(getMeatChoppers()) << LL("\n")
		<< LL("Destroy walls at: ") << pointListToString(getDestoyWalls()) << LL("\n")
		<< LL("Bombs at: ") << pointListToString(getBombs()) << LL("\n")
		<< LL("Blasts: ") << pointListToString(getBlasts()) << LL("\n")
		<< LL("Expected blasts at: ") << pointListToString(getFutureBlasts()) << LL("\n");
	return ss.str();
}

CharElement* Board::valueOf(Char ch) const {
	return new Element(ch);
}

Point Board::getBomberman() const {
	PointList rslt;
	rslt.splice(rslt.end(), findAll(new Element(LL("BOMBERMAN"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("BOMB_BOMBERMAN"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("DEAD_BOMBERMAN"))));
	return rslt.front();
}

PointList Board::getOtherBombermans() const {
	PointList rslt;
	rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_BOMBERMAN"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_BOMB_BOMBERMAN"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_DEAD_BOMBERMAN"))));
	return rslt;
}

bool Board::isMyBombermanDead() const {
	return board.find(Element(LL("DEAD_BOMBERMAN")).getChar()) != String::npos;
}

PointList Board::getBarriers() const {
	PointList rslt = getMeatChoppers();
	rslt.splice(rslt.end(), getWalls());
	rslt.splice(rslt.end(), getBombs());
	rslt.splice(rslt.end(), getDestoyWalls());
	rslt.splice(rslt.end(), getOtherBombermans());
	return removeDuplicates(rslt);
}

PointList Board::getMeatChoppers() const {
	return findAll(new Element(LL("MEAT_CHOPPER")));
}

PointList Board::getWalls() const {
	return findAll(new Element(LL("WALL")));
}

PointList Board::getDestoyWalls() const {
	return findAll(new Element(LL("DESTROY_WALL")));
}

PointList Board::getBombs() const {
	PointList rslt;
	rslt.splice(rslt.end(), findAll(new Element(LL("BOMB_TIMER_1"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("BOMB_TIMER_2"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("BOMB_TIMER_3"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("BOMB_TIMER_4"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("BOMB_TIMER_5"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("BOMB_BOMBERMAN"))));
	return rslt;
}

PointList Board::getBlasts() const {
	return findAll(new Element(LL("BOOM")));
}

PointList Board::getFutureBlasts() const {
	PointList bombs = getBombs();
	bombs.splice(bombs.end(), findAll(new Element(LL("OTHER_BOMB_BOMBERMAN"))));
	bombs.splice(bombs.end(), findAll(new Element(LL("BOMB_BOMBERMAN"))));

	PointList rslt;
	PointList walls = getWalls();
	for (auto bmb : bombs) {
		rslt.push_back(bmb);
		PointList bombSurrs = bmb.getSurrounds(size);
		for (auto surr : bombSurrs) {
			if (std::find(walls.begin(), walls.end(), surr) == walls.end()) {
				rslt.push_back(surr);
			}
		}
	}

	return removeDuplicates(rslt);
}

PointList Board::removeDuplicates(PointList lst) const {
	PointList res;
	for (auto pt : lst) {
		if (std::find(res.begin(), res.end(), pt) == res.end()) {
			res.push_back(pt);
		}
	}
	return res;
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

