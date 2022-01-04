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

    result[LL("EMPTY")] = LL('-');

    result[LL("FLOOR")] = LL('.');

    result[LL("ANGLE_IN_LEFT")] = LL('╔');

    result[LL("WALL_FRONT")] = LL('═');

    result[LL("ANGLE_IN_RIGHT")] = LL('┐');

    result[LL("WALL_RIGHT")] = LL('│');

    result[LL("ANGLE_BACK_RIGHT")] = LL('┘');

    result[LL("WALL_BACK")] = LL('─');

    result[LL("ANGLE_BACK_LEFT")] = LL('└');

    result[LL("WALL_LEFT")] = LL('║');

    result[LL("WALL_BACK_ANGLE_LEFT")] = LL('┌');

    result[LL("WALL_BACK_ANGLE_RIGHT")] = LL('╗');

    result[LL("ANGLE_OUT_RIGHT")] = LL('╝');

    result[LL("ANGLE_OUT_LEFT")] = LL('╚');

    result[LL("SPACE")] = LL(' ');

    result[LL("FORCE1")] = LL('♥');

    result[LL("FORCE2")] = LL('♦');

    result[LL("FORCE3")] = LL('♣');

    result[LL("FORCE4")] = LL('♠');

    result[LL("EXIT")] = LL('E');

    result[LL("HOLE")] = LL('O');

    result[LL("BREAK")] = LL('B');

    result[LL("GOLD")] = LL('$');

    result[LL("BASE1")] = LL('1');

    result[LL("BASE2")] = LL('2');

    result[LL("BASE3")] = LL('3');

    result[LL("BASE4")] = LL('4');

    result[LL("FOG")] = LL('F');

    result[LL("BACKGROUND")] = LL('G');

    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();
