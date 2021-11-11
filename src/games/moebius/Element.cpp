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

        // Труба повернута слева вверх.

    result[LL("LEFT_UP")] = LL('╝');

        // Труба повернута сверху направо.

    result[LL("UP_RIGHT")] = LL('╚');

        // Труба повернута справа вниз.

    result[LL("RIGHT_DOWN")] = LL('╔');

        // Труба повернута снизу влево.

    result[LL("DOWN_LEFT")] = LL('╗');

        // Прямая труба слева направо.

    result[LL("LEFT_RIGHT")] = LL('═');

        // Прямая труба сверху вниз.

    result[LL("UP_DOWN")] = LL('║');

        // Две пересеченные прямые трубы, одна сверху вниз, другая
        // слева направо.

    result[LL("CROSS")] = LL('╬');

        // Пустое место на поле.

    result[LL("EMPTY")] = LL(' ');

    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();
