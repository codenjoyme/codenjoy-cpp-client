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
		<< LL("Hero at: ") << getHero().toString() << LL("\n")
		<< LL("Other Heroes at: ") << pointListToString(getOtherHeroes()) << LL("\n")
		<< LL("Enemy Heroes at: ") << pointListToString(getEnemyHeroes()) << LL("\n")
		<< LL("Ghosts at: ") << pointListToString(getGhosts()) << LL("\n")
		<< LL("Treasure Boxes at : ") << pointListToString(getTreasureBoxes()) << LL("\n")
		<< LL("Potions at: ") << pointListToString(getPotions()) << LL("\n")
		<< LL("Blasts: ") << pointListToString(getBlasts()) << LL("\n")
		<< LL("Expected blasts at: ") << pointListToString(getFutureBlasts()) << LL("\n");
	return ss.str();
}

CharElement* Board::valueOf(Char ch) const {
	return new Element(ch);
}

Point Board::getHero() const {
	PointList rslt;
	rslt.splice(rslt.end(), findAll(new Element(LL("HERO"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("POTION_HERO"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("DEAD_HERO"))));
	return rslt.front();
}

PointList Board::getOtherHeroes() const {
	PointList rslt;
	rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_POTION_HERO"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_DEAD_HERO"))));
	return rslt;
}

PointList Board::getEnemyHeroes() const {
	PointList rslt;
	rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_POTION_HERO"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_DEAD_HERO"))));
	return rslt;
}

bool Board::isMyHeroDead() const {
	return board.find(Element(LL("DEAD_HERO")).getChar()) != String::npos;
}

PointList Board::getBarriers() const {
	PointList rslt = getGhosts();
	rslt.splice(rslt.end(), getWalls());
	rslt.splice(rslt.end(), getPotions());
	rslt.splice(rslt.end(), getTreasureBoxes());
	rslt.splice(rslt.end(), getOtherHeroes());
	rslt.splice(rslt.end(), getEnemyHeroes());
	return removeDuplicates(rslt);
}

PointList Board::getGhosts() const {
	return findAll(new Element(LL("GHOST")));
}

PointList Board::getWalls() const {
	return findAll(new Element(LL("WALL")));
}

PointList Board::getTreasureBoxes() const {
	return findAll(new Element(LL("TREASURE_BOX")));
}

PointList Board::getPotions() const {
	PointList rslt;
	rslt.splice(rslt.end(), findAll(new Element(LL("POTION_TIMER_1"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("POTION_TIMER_2"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("POTION_TIMER_3"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("POTION_TIMER_4"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("POTION_TIMER_5"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("POTION_HERO"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_POTION_HERO"))));
	rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_POTION_HERO"))));
	return rslt;
}

PointList Board::getBlasts() const {
	return findAll(new Element(LL("BOOM")));
}

PointList Board::getFutureBlasts() const {
	PointList potions = getPotions();
	potions.splice(potions.end(), findAll(new Element(LL("OTHER_POTION_HERO"))));
	potions.splice(potions.end(), findAll(new Element(LL("ENEMY_POTION_HERO"))));
	potions.splice(potions.end(), findAll(new Element(LL("POTION_HERO"))));

	PointList rslt;
	PointList walls = getWalls();
	for (auto ptn : potions) {
		rslt.push_back(ptn);
		PointList potionSurrounds = ptn.getSurrounds(size);
		for (auto surr : potionSurrounds) {
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

