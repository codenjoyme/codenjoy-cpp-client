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

        // An empty space where hero can move.

    result[LL("WATER")] = LL(' ');

        // Underwater reefs. They cannot be destroyed without prize
        // PRIZE_BREAKING_BAD.

    result[LL("REEFS")] = LL('☼');

        // Explosion site. It disappears in a second.

    result[LL("EXPLOSION")] = LL('Ѡ');

        // Oil leak, hitting which the hero partially loses control.
        // During the passage, the field of view is limited and the
        // hero will repeat the old commands for several ticks in a
        // row, ignoring the current commands.

    result[LL("OIL")] = LL('#');

        // Seaweed hide heroes which can continue to shoot at the same
        // time. The fired shells are also not visible under the weed.
        // Only prizes can be seen from behind seaweed.

    result[LL("SEAWEED")] = LL('%');

        // Fishnet does not allow to pass through itself without the
        // PRIZE_WALKING_ON_FISHNET prize, but the shells fly freely
        // through the water. Hero stuck in the middle of the fishnet,
        // after canceling the PRIZE_WALKING_ON_FISHNET prize, can move
        // 1 cell in the fishnet only every N ticks.

    result[LL("FISHNET")] = LL('~');

        // An iceberg that hasn't been shot yet. It takes 3 shots to
        // completely destroy.

    result[LL("ICEBERG_HUGE")] = LL('╬');

        // Partially destroyed iceberg. For complete destruction, 2
        // shot is required.

    result[LL("ICEBERG_MEDIUM_DOWN")] = LL('╩');

        // Partially destroyed iceberg. For complete destruction, 2
        // shot is required.

    result[LL("ICEBERG_MEDIUM_UP")] = LL('╦');

        // Partially destroyed iceberg. For complete destruction, 2
        // shot is required.

    result[LL("ICEBERG_MEDIUM_LEFT")] = LL('╠');

        // Partially destroyed iceberg. For complete destruction, 2
        // shot is required.

    result[LL("ICEBERG_MEDIUM_RIGHT")] = LL('╣');

        // Almost destroyed iceberg. For complete destruction, 1 shot
        // is required.

    result[LL("ICEBERG_SMALL_DOWN_DOWN")] = LL('╨');

        // Almost destroyed iceberg. For complete destruction, 1 shot
        // is required.

    result[LL("ICEBERG_SMALL_UP_UP")] = LL('╥');

        // Almost destroyed iceberg. For complete destruction, 1 shot
        // is required.

    result[LL("ICEBERG_SMALL_LEFT_LEFT")] = LL('╞');

        // Almost destroyed iceberg. For complete destruction, 1 shot
        // is required.

    result[LL("ICEBERG_SMALL_RIGHT_RIGHT")] = LL('╡');

        // Almost destroyed iceberg. For complete destruction, 1 shot
        // is required.

    result[LL("ICEBERG_SMALL_LEFT_RIGHT")] = LL('│');

        // Almost destroyed iceberg. For complete destruction, 1 shot
        // is required.

    result[LL("ICEBERG_SMALL_UP_DOWN")] = LL('─');

        // Almost destroyed iceberg. For complete destruction, 1 shot
        // is required.

    result[LL("ICEBERG_SMALL_UP_LEFT")] = LL('┌');

        // Almost destroyed iceberg. For complete destruction, 1 shot
        // is required.

    result[LL("ICEBERG_SMALL_UP_RIGHT")] = LL('┐');

        // Almost destroyed iceberg. For complete destruction, 1 shot
        // is required.

    result[LL("ICEBERG_SMALL_DOWN_LEFT")] = LL('└');

        // Almost destroyed iceberg. For complete destruction, 1 shot
        // is required.

    result[LL("ICEBERG_SMALL_DOWN_RIGHT")] = LL('┘');

        // Completely destroyed iceberg. No different from WATER. A new
        // one will appear at this place soon.

    result[LL("ICEBERG_DESTROYED")] = LL(' ');

        // Torpedo - is a self-propelled underwater missile designed to
        // be fired from a submarine and to explode on reaching a
        // target. The target can be an iceberg, another submarine and
        // other elements under water.

    result[LL("TORPEDO")] = LL('•');

        // Your hero is pointing up.

    result[LL("HERO_UP")] = LL('▲');

        // Your hero is pointing right.

    result[LL("HERO_RIGHT")] = LL('►');

        // Your hero is pointing down.

    result[LL("HERO_DOWN")] = LL('▼');

        // Your hero is pointing left.

    result[LL("HERO_LEFT")] = LL('◄');

        // Enemy hero is pointing up.

    result[LL("OTHER_HERO_UP")] = LL('˄');

        // Enemy hero is pointing right.

    result[LL("OTHER_HERO_RIGHT")] = LL('˃');

        // Enemy hero is pointing down.

    result[LL("OTHER_HERO_DOWN")] = LL('˅');

        // Enemy hero is pointing left.

    result[LL("OTHER_HERO_LEFT")] = LL('˂');

        // AI is pointing up.

    result[LL("AI_UP")] = LL('?');

        // AI is pointing right.

    result[LL("AI_RIGHT")] = LL('»');

        // AI is pointing down.

    result[LL("AI_DOWN")] = LL('¿');

        // AI is pointing left.

    result[LL("AI_LEFT")] = LL('«');

        // AI can also be a prize, then it is highlighted by this
        // sprite every few ticks.

    result[LL("AI_PRIZE")] = LL('◘');

        // The dropped prize after the destruction of the prize AI
        // flickers on the field every even tick of the game with this
        // sprite.

    result[LL("PRIZE")] = LL('!');

        // A prize that gives the hero temporary invulnerability.

    result[LL("PRIZE_IMMORTALITY")] = LL('1');

        // A prize that allows you to temporarily destroy any icebergs
        // and underwater reefs (but not the border of the field) with
        // 1 shot.

    result[LL("PRIZE_BREAKING_BAD")] = LL('2');

        // A prize that allows the hero to temporarily walk on fishnet.

    result[LL("PRIZE_WALKING_ON_FISHNET")] = LL('3');

        // A prize that allows the hero to temporarily see all enemies
        // and their bullets under the seaweed.

    result[LL("PRIZE_VISIBILITY")] = LL('4');

        // A prize that allows the hero to temporarily not slide on the
        // ice.

    result[LL("PRIZE_NO_SLIDING")] = LL('5');

    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();
