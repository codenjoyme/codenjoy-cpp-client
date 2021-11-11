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

        // Stone.

    result[LL("BAD_APPLE")] = LL('☻');

        // Having eaten it, you shorten it in length. If it is not long
        // enough, you die.

    result[LL("GOOD_APPLE")] = LL('☺');

        // An obstacle that cannot be passed. It is also the border of
        // the field.

    result[LL("BREAK")] = LL('☼');

        // An empty place in the field where the snake can go.

    result[LL("NONE")] = LL(' ');

        // Snake head is pointing down.

    result[LL("HEAD_DOWN")] = LL('▼');

        // Snake head is pointing left.

    result[LL("HEAD_LEFT")] = LL('◄');

        // Snake head is pointing right.

    result[LL("HEAD_RIGHT")] = LL('►');

        // Snake head is pointing up.

    result[LL("HEAD_UP")] = LL('▲');

        // Horizontal part of the body.

    result[LL("TAIL_HORIZONTAL")] = LL('═');

        // Vertical part of the body.

    result[LL("TAIL_VERTICAL")] = LL('║');

        // Turning the snake body from left to down.

    result[LL("TAIL_LEFT_DOWN")] = LL('╗');

        // Turning the snake body from left to up.

    result[LL("TAIL_LEFT_UP")] = LL('╝');

        // Turning the snake body from right to down.

    result[LL("TAIL_RIGHT_DOWN")] = LL('╔');

        // Turning the snake body from right to up.

    result[LL("TAIL_RIGHT_UP")] = LL('╚');

        // Down tail.

    result[LL("TAIL_END_DOWN")] = LL('╙');

        // Left tail.

    result[LL("TAIL_END_LEFT")] = LL('╘');

        // Up tail.

    result[LL("TAIL_END_UP")] = LL('╓');

        // Right tail.

    result[LL("TAIL_END_RIGHT")] = LL('╕');

    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();
