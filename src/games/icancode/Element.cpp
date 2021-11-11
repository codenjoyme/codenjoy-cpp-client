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

    result[LL("LASER_MACHINE_CHARGING_LEFT")] = LL('˂');

    result[LL("LASER_MACHINE_CHARGING_RIGHT")] = LL('˃');

    result[LL("LASER_MACHINE_CHARGING_UP")] = LL('˄');

    result[LL("LASER_MACHINE_CHARGING_DOWN")] = LL('˅');

    result[LL("LASER_MACHINE_READY_LEFT")] = LL('◄');

    result[LL("LASER_MACHINE_READY_RIGHT")] = LL('►');

    result[LL("LASER_MACHINE_READY_UP")] = LL('▲');

    result[LL("LASER_MACHINE_READY_DOWN")] = LL('▼');

    result[LL("START")] = LL('S');

    result[LL("EXIT")] = LL('E');

    result[LL("HOLE")] = LL('O');

    result[LL("BOX")] = LL('B');

    result[LL("ZOMBIE_START")] = LL('Z');

    result[LL("GOLD")] = LL('$');

    result[LL("UNSTOPPABLE_LASER_PERK")] = LL('l');

    result[LL("DEATH_RAY_PERK")] = LL('r');

    result[LL("UNLIMITED_FIRE_PERK")] = LL('f');

    result[LL("FIRE_PERK")] = LL('a');

    result[LL("JUMP_PERK")] = LL('j');

    result[LL("MOVE_BOXES_PERK")] = LL('m');

    result[LL("ROBO")] = LL('☺');

    result[LL("ROBO_FALLING")] = LL('o');

    result[LL("ROBO_FLYING")] = LL('*');

    result[LL("ROBO_LASER")] = LL('☻');

    result[LL("ROBO_OTHER")] = LL('X');

    result[LL("ROBO_OTHER_FALLING")] = LL('x');

    result[LL("ROBO_OTHER_FLYING")] = LL('^');

    result[LL("ROBO_OTHER_LASER")] = LL('&');

    result[LL("LASER_LEFT")] = LL('←');

    result[LL("LASER_RIGHT")] = LL('→');

    result[LL("LASER_UP")] = LL('↑');

    result[LL("LASER_DOWN")] = LL('↓');

    result[LL("FEMALE_ZOMBIE")] = LL('♀');

    result[LL("MALE_ZOMBIE")] = LL('♂');

    result[LL("ZOMBIE_DIE")] = LL('✝');

    result[LL("FOG")] = LL('F');

    result[LL("BACKGROUND")] = LL('G');

    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();
