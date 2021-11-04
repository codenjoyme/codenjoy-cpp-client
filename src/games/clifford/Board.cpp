/*-
 * #%L
 * Codenjoy - it's a dojo-like platform from developers to developers.
 * %%
 * Copyright (C) 2021 Codenjoy
 * %%
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/gpl-3.0.html>.
 * #L%
 */

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
        << LL("Robbers at: ") << pointListToString(getRobbers()) << LL("\n")
        << LL("Mask potions at: ") << pointListToString(getPotions()) << LL("\n");
        << LL("Keys at: ") << pointListToString(getKeys()) << LL("\n");
    return ss.str();
}

CharElement* Board::valueOf(Char ch) const {
    return new Element(ch);
}

Point Board::getHero() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_CRACK_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_CRACK_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_LADDER"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_FALL_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_FALL_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_PIPE_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_PIPE_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_DIE"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_PIT_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_PIT_RIGHT"))));

    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_CRACK_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_CRACK_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_LADDER"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_FALL_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_FALL_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_PIPE_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_PIPE_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_DIE"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_PIT_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("HERO_MASK_PIT_RIGHT"))));
    return rslt.front();
}

PointList Board::getOtherHeroes() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_DIE"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_CRACK_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_CRACK_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_LADDER"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_FALL_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_FALL_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_PIPE_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_PIPE_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_PIT_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_PIT_RIGHT"))));

    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_DIE"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_CRACK_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_CRACK_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_LADDER"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_FALL_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_FALL_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_PIPE_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_PIPE_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_PIT_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OTHER_HERO_MASK_PIT_RIGHT"))));
    return rslt;
}

PointList Board::getEnemyHeroes() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_DIE"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_CRACK_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_CRACK_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_LADDER"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_FALL_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_FALL_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_PIPE_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_PIPE_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_PIT_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_PIT_RIGHT"))));

    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_DIE"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_CRACK_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_CRACK_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_LADDER"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_FALL_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_FALL_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_PIPE_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_PIPE_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_PIT_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ENEMY_HERO_MASK_PIT_RIGHT"))));
    return rslt;
}

PointList Board::getRobbers() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("ROBBER_LADDER"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ROBBER_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ROBBER_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ROBBER_FALL_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ROBBER_FALL_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ROBBER_PIPE_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ROBBER_PIPE_RIGHT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ROBBER_PIT_LEFT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("ROBBER_PIT_RIGHT"))));
    return rslt;
}

bool Board::isMyHeroDead() const {
    return board.find(Element(LL("HERO_DIE")).getChar()) != String::npos &&
           board.find(Element(LL("HERO_MASK_DIE")).getChar()) != String::npos;
}

PointList Board::getBarriers() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("BRICK"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("STONE"))));
    return rslt;
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

PointList Board::getPits() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("CRACK_PIT"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("PIT_FILL_1"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("PIT_FILL_2"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("PIT_FILL_3"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("PIT_FILL_4"))));
    return rslt;
}

PointList Board::getClues() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("CLUE_KNIFE"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("CLUE_GLOVE"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("CLUE_RING"))));
    return rslt;
}

PointList Board::getBackways() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("BACKWAY"))));
    return rslt;
}

PointList Board::getPotions() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("MASK_POTION"))));
    return rslt;
}

PointList Board::getDoors() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("OPENED_DOOR_GOLD"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OPENED_DOOR_SILVER"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("OPENED_DOOR_BRONZE"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("CLOSED_DOOR_GOLD"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("CLOSED_DOOR_SILVER"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("CLOSED_DOOR_BRONZE"))));
    return rslt;
}

PointList Board::getKeys() const {
    PointList rslt;
    rslt.splice(rslt.end(), findAll(new Element(LL("KEY_GOLD"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("KEY_SILVER"))));
    rslt.splice(rslt.end(), findAll(new Element(LL("KEY_BRONZE"))));
    return rslt;
}