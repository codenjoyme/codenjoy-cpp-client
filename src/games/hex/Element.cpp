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

        // Пустое поле на карте. Сюда можно перемещать свои войска.

    result[LL("NONE")] = LL(' ');

        // Непроходимое препятствие. Обычно граница поля, но может
        // появиться в месте, куда два героя одновременно отправят вои
        // войска.

    result[LL("WALL")] = LL('☼');

        // Твои войска.

    result[LL("MY_HERO")] = LL('☺');

        // Войска противника 1.

    result[LL("HERO1")] = LL('☻');

        // Войска противника 2.

    result[LL("HERO2")] = LL('♥');

        // Войска противника 3.

    result[LL("HERO3")] = LL('♦');

        // Войска противника 4.

    result[LL("HERO4")] = LL('♣');

        // Войска противника 5.

    result[LL("HERO5")] = LL('♠');

        // Войска противника 6.

    result[LL("HERO6")] = LL('•');

        // Войска противника 7.

    result[LL("HERO7")] = LL('◘');

        // Войска противника 8.

    result[LL("HERO8")] = LL('○');

        // Войска противника 9.

    result[LL("HERO9")] = LL('◙');

        // Войска противника 10.

    result[LL("HERO10")] = LL('♂');

        // Войска противника 11.

    result[LL("HERO11")] = LL('♀');

    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();