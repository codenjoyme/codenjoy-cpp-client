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

        // An empty space where a tank can move.

    result[LL("NONE")] = LL(' ');

        // The undestroyable wall.

    result[LL("BATTLE_WALL")] = LL('☼');

        // A destroyed enemy’s tank. A new appears just in a second.

    result[LL("BANG")] = LL('Ѡ');

        // Ice, having driven onto which the tank will begin to drift.
        // During a skid, the tank will repeat the old commands for
        // several ticks in a row, ignoring the current commands.

    result[LL("ICE")] = LL('#');

        // The trees hide tanks which can continue to shoot at the same
        // time. The fired shells are also not visible under the trees.
        // Only prizes can be seen from behind the trees.

    result[LL("TREE")] = LL('%');

        // The river does not allow to pass through itself without the
        // PRIZE_WALKING_ON_WATER prize, but the shells fly freely
        // through the water. A tank stuck in the middle of the water,
        // after canceling the PRIZE_WALKING_ON_WATER prize, can move 1
        // cell in the water only every N ticks.

    result[LL("RIVER")] = LL('~');

        // A wall that hasn't been shot yet. It takes 3 shots to
        // completely destroy.

    result[LL("WALL")] = LL('╬');

        // Partially destroyed wall. For complete destruction, 2 shot
        // is required.

    result[LL("WALL_DESTROYED_DOWN")] = LL('╩');

        // Partially destroyed wall. For complete destruction, 2 shot
        // is required.

    result[LL("WALL_DESTROYED_UP")] = LL('╦');

        // Partially destroyed wall. For complete destruction, 2 shot
        // is required.

    result[LL("WALL_DESTROYED_LEFT")] = LL('╠');

        // Partially destroyed wall. For complete destruction, 2 shot
        // is required.

    result[LL("WALL_DESTROYED_RIGHT")] = LL('╣');

        // Partially destroyed wall. For complete destruction, 1 shot
        // is required.

    result[LL("WALL_DESTROYED_DOWN_TWICE")] = LL('╨');

        // Partially destroyed wall. For complete destruction, 1 shot
        // is required.

    result[LL("WALL_DESTROYED_UP_TWICE")] = LL('╥');

        // Partially destroyed wall. For complete destruction, 1 shot
        // is required.

    result[LL("WALL_DESTROYED_LEFT_TWICE")] = LL('╞');

        // Partially destroyed wall. For complete destruction, 1 shot
        // is required.

    result[LL("WALL_DESTROYED_RIGHT_TWICE")] = LL('╡');

        // Partially destroyed wall. For complete destruction, 1 shot
        // is required.

    result[LL("WALL_DESTROYED_LEFT_RIGHT")] = LL('│');

        // Partially destroyed wall. For complete destruction, 1 shot
        // is required.

    result[LL("WALL_DESTROYED_UP_DOWN")] = LL('─');

        // Partially destroyed wall. For complete destruction, 1 shot
        // is required.

    result[LL("WALL_DESTROYED_UP_LEFT")] = LL('┌');

        // Partially destroyed wall. For complete destruction, 1 shot
        // is required.

    result[LL("WALL_DESTROYED_RIGHT_UP")] = LL('┐');

        // Partially destroyed wall. For complete destruction, 1 shot
        // is required.

    result[LL("WALL_DESTROYED_DOWN_LEFT")] = LL('└');

        // Partially destroyed wall. For complete destruction, 1 shot
        // is required.

    result[LL("WALL_DESTROYED_DOWN_RIGHT")] = LL('┘');

        // Partially destroyed wall. For complete destruction, 2 shot
        // is required.

    result[LL("WALL_DESTROYED")] = LL(' ');

        // Completely destroyed wall. Wall will recover over time.

    result[LL("BULLET")] = LL('•');

        // Your tank is pointing up.

    result[LL("TANK_UP")] = LL('▲');

        // Your tank is pointing right.

    result[LL("TANK_RIGHT")] = LL('►');

        // Your tank is pointing down.

    result[LL("TANK_DOWN")] = LL('▼');

        // Your tank is pointing left.

    result[LL("TANK_LEFT")] = LL('◄');

        // Enemy tank is pointing up.

    result[LL("OTHER_TANK_UP")] = LL('˄');

        // Enemy tank is pointing right.

    result[LL("OTHER_TANK_RIGHT")] = LL('˃');

        // Enemy tank is pointing down.

    result[LL("OTHER_TANK_DOWN")] = LL('˅');

        // Enemy tank is pointing left.

    result[LL("OTHER_TANK_LEFT")] = LL('˂');

        // AI-tank is pointing up.

    result[LL("AI_TANK_UP")] = LL('?');

        // AI-tank is pointing right.

    result[LL("AI_TANK_RIGHT")] = LL('»');

        // AI-tank is pointing down.

    result[LL("AI_TANK_DOWN")] = LL('¿');

        // AI-tank is pointing left.

    result[LL("AI_TANK_LEFT")] = LL('«');

        // AI-tank can also be a prize, then it is highlighted by this
        // sprite every few ticks.

    result[LL("AI_TANK_PRIZE")] = LL('◘');

        // The dropped prize after the destruction of the prize tank
        // flickers on the field every even tick of the game with this
        // sprite.

    result[LL("PRIZE")] = LL('!');

        // A prize that gives the hero temporary invulnerability.

    result[LL("PRIZE_IMMORTALITY")] = LL('1');

        // A prize that allows you to temporarily destroy any walls
        // with 1 shot, even indestructible ones (but not the border of
        // the field).

    result[LL("PRIZE_BREAKING_WALLS")] = LL('2');

        // A prize that allows the hero to temporarily walk on water.

    result[LL("PRIZE_WALKING_ON_WATER")] = LL('3');

        // A prize that allows the hero to temporarily see all enemies
        // under the trees.

    result[LL("PRIZE_VISIBILITY")] = LL('4');

        // A prize that allows the hero to temporarily not slide on the
        // ice.

    result[LL("PRIZE_NO_SLIDING")] = LL('5');

    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();
