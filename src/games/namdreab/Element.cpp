/*-
 * #%L
 * Codenjoy - it's a dojo-like platform from developers to developers.
 * %%
 * Copyright (C) 2012 - 2022 Codenjoy
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

//include "Element.h"

Element::Element(Char el) {
    elem.first = valueOf(el);
    elem.second = el;
}

Element::Element(String name) {
    elem.second = Elements.at(name);
    elem.first = name;
}

Char Element::ch() {
    return elem.second;
}

String Element::name() {
    return elem.first;
}

Char Element::getChar() const {
    return elem.second;
}

String Element::valueOf(Char ch) const {
    for (auto i : Elements) {
        if (i.second == ch) return i.first;
    }
    throw std::invalid_argument("Element::valueOf(Char ch): No such Element for " + ch);
}

bool Element::operator==(const Element& el) const {
    return elem == el.elem;
}

ElementMap Element::initialiseElements() {
    ElementMap result;

        // Empty space - space where the hero can move.

    result[LL("NONE")] = LL(' ');

        // Impenetrable wall.

    result[LL("WALL")] = LL('☼');

        // Respawn point from which the hero starts its movement.

    result[LL("START_FLOOR")] = LL('#');

        // .

    result[LL("OTHER")] = LL('?');

        // Apple.

    result[LL("APPLE")] = LL('○');

        // Stone.

    result[LL("STONE")] = LL('●');

        // Flying pill/Angel's wings.

    result[LL("FLYING_PILL")] = LL('©');

        // Fury pill/Devil's mask.

    result[LL("FURY_PILL")] = LL('®');

        // Gold.

    result[LL("GOLD")] = LL('$');

        // Your hero head pointing down.

    result[LL("HEAD_DOWN")] = LL('▼');

        // Your hero head pointing left.

    result[LL("HEAD_LEFT")] = LL('◄');

        // Your hero head pointing right.

    result[LL("HEAD_RIGHT")] = LL('►');

        // Your hero head pointing up.

    result[LL("HEAD_UP")] = LL('▲');

        // Your hero is dead.

    result[LL("HEAD_DEAD")] = LL('☻');

        // Your hero head under influence Fury pill/Devils mask.

    result[LL("HEAD_EVIL")] = LL('♥');

        // Your hero head under influence Flying pill/Angels wings.

    result[LL("HEAD_FLY")] = LL('♠');

        // Your hero head when hero is inactive.

    result[LL("HEAD_SLEEP")] = LL('&');

        // Body of your hero is directed horizontally.

    result[LL("BODY_HORIZONTAL")] = LL('═');

        // Body of your hero is directed vertically.

    result[LL("BODY_VERTICAL")] = LL('║');

        // Turning your hero body from left to down.

    result[LL("BODY_LEFT_DOWN")] = LL('╗');

        // Turning your hero body from left to up.

    result[LL("BODY_LEFT_UP")] = LL('╝');

        // Turning your hero body from right to down.

    result[LL("BODY_RIGHT_DOWN")] = LL('╔');

        // Turning your hero body from left to up.

    result[LL("BODY_RIGHT_UP")] = LL('╚');

        // Your hero tail (end) pointing down.

    result[LL("TAIL_END_DOWN")] = LL('╙');

        // Your hero tail (end) pointing left.

    result[LL("TAIL_END_LEFT")] = LL('╘');

        // Your hero tail (end) pointing up.

    result[LL("TAIL_END_UP")] = LL('╓');

        // Your hero tail (end) pointing right.

    result[LL("TAIL_END_RIGHT")] = LL('╕');

        // Your hero tail (end) when hero is inactive.

    result[LL("TAIL_INACTIVE")] = LL('~');

        // Enemy hero head pointing down.

    result[LL("ENEMY_HEAD_DOWN")] = LL('˅');

        // Enemy hero head pointing left.

    result[LL("ENEMY_HEAD_LEFT")] = LL('<');

        // Enemy hero head pointing right.

    result[LL("ENEMY_HEAD_RIGHT")] = LL('>');

        // Enemy hero head pointing up.

    result[LL("ENEMY_HEAD_UP")] = LL('˄');

        // Enemy hero is dead.

    result[LL("ENEMY_HEAD_DEAD")] = LL('☺');

        // Enemy hero head under influence Fury pill/Devils mask.

    result[LL("ENEMY_HEAD_EVIL")] = LL('♣');

        // Enemy hero head under influence Flying pill/Angels wings.

    result[LL("ENEMY_HEAD_FLY")] = LL('♦');

        // Enemy hero head when hero is inactive.

    result[LL("ENEMY_HEAD_SLEEP")] = LL('ø');

        // Body of enemy hero is directed horizontally.

    result[LL("ENEMY_BODY_HORIZONTAL")] = LL('─');

        // Body of enemy hero is directed vertically.

    result[LL("ENEMY_BODY_VERTICAL")] = LL('│');

        // Turning enemy hero body from left to down.

    result[LL("ENEMY_BODY_LEFT_DOWN")] = LL('┐');

        // Turning enemy hero body from left to up.

    result[LL("ENEMY_BODY_LEFT_UP")] = LL('┘');

        // Turning enemy hero body from right to down.

    result[LL("ENEMY_BODY_RIGHT_DOWN")] = LL('┌');

        // Turning enemy hero body from left to up.

    result[LL("ENEMY_BODY_RIGHT_UP")] = LL('└');

        // Enemy hero tail (end) pointing down.

    result[LL("ENEMY_TAIL_END_DOWN")] = LL('¤');

        // Enemy hero tail (end) pointing left.

    result[LL("ENEMY_TAIL_END_LEFT")] = LL('×');

        // Enemy hero tail (end) pointing up.

    result[LL("ENEMY_TAIL_END_UP")] = LL('æ');

        // Enemy hero tail (end) pointing right.

    result[LL("ENEMY_TAIL_END_RIGHT")] = LL('ö');

        // Enemy hero tail (end) when hero is inactive.

    result[LL("ENEMY_TAIL_INACTIVE")] = LL('*');

    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();
