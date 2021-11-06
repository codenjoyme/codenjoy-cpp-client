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

        // Empty space - where the hero can move.

    result[LL("NONE")] = LL(' ');

        // A wall where you can shoot a hole.

    result[LL("BRICK")] = LL('#');

        // The wall is restored over time. When the process begins, we
        // see a timer.

    result[LL("PIT_FILL_1")] = LL('1');

        // The wall is restored over time. When the process begins, we
        // see a timer.

    result[LL("PIT_FILL_2")] = LL('2');

        // The wall is restored over time. When the process begins, we
        // see a timer.

    result[LL("PIT_FILL_3")] = LL('3');

        // The wall is restored over time. When the process begins, we
        // see a timer.

    result[LL("PIT_FILL_4")] = LL('4');

        // Indestructible wall - It cannot be destroyed with a shot.

    result[LL("STONE")] = LL('☼');

        // At the moment of the shot, we see the wall like this.

    result[LL("CRACK_PIT")] = LL('*');

        // Clue knife. Collect a series of clues to get the maximum
        // points.

    result[LL("CLUE_KNIFE")] = LL('$');

        // Clue glove. Collect a series of clues to get the maximum
        // points.

    result[LL("CLUE_GLOVE")] = LL('&');

        // Clue ring. Collect a series of clues to get the maximum
        // points.

    result[LL("CLUE_RING")] = LL('@');

        // Your hero is dead. In the next tick, it will disappear and
        // appear in a new location.

    result[LL("HERO_DIE")] = LL('Ѡ');

        // Your hero is climbing the ladder.

    result[LL("HERO_LADDER")] = LL('Y');

        // Your hero runs to the left.

    result[LL("HERO_LEFT")] = LL('◄');

        // Your hero runs to the right.

    result[LL("HERO_RIGHT")] = LL('►');

        // Your hero is falling.

    result[LL("HERO_FALL")] = LL(']');

        // Your hero is crawling along the pipe.

    result[LL("HERO_PIPE")] = LL('{');

        // Your hero in the pit.

    result[LL("HERO_PIT")] = LL('⍃');

        // Your shadow-hero is dead. In the next tick, it will
        // disappear and appear in a new location.

    result[LL("HERO_MASK_DIE")] = LL('x');

        // Your shadow-hero is climbing the ladder.

    result[LL("HERO_MASK_LADDER")] = LL('⍬');

        // Your shadow-hero runs to the left.

    result[LL("HERO_MASK_LEFT")] = LL('⊲');

        // Your shadow-hero runs to the right.

    result[LL("HERO_MASK_RIGHT")] = LL('⊳');

        // Your shadow-hero is falling.

    result[LL("HERO_MASK_FALL")] = LL('⊅');

        // Your shadow-hero is crawling along the pipe.

    result[LL("HERO_MASK_PIPE")] = LL('⋜');

        // Your shadow-hero in the pit.

    result[LL("HERO_MASK_PIT")] = LL('ᐊ');

        // Other hero is dead. In the next tick, it will disappear and
        // appear in a new location.

    result[LL("OTHER_HERO_DIE")] = LL('Z');

        // Other hero is climbing the ladder.

    result[LL("OTHER_HERO_LADDER")] = LL('U');

        // Other hero runs to the left.

    result[LL("OTHER_HERO_LEFT")] = LL(')');

        // Other hero runs to the right.

    result[LL("OTHER_HERO_RIGHT")] = LL('(');

        // Other hero is falling.

    result[LL("OTHER_HERO_FALL")] = LL('⊐');

        // Other hero is crawling along the pipe.

    result[LL("OTHER_HERO_PIPE")] = LL('Э');

        // Other hero in the pit.

    result[LL("OTHER_HERO_PIT")] = LL('ᗉ');

        // Other shadow-hero is dead. In the next tick, it will
        // disappear and appear in a new location.

    result[LL("OTHER_HERO_MASK_DIE")] = LL('⋈');

        // Other shadow-hero is climbing the ladder.

    result[LL("OTHER_HERO_MASK_LADDER")] = LL('⋕');

        // Other shadow-hero runs to the left.

    result[LL("OTHER_HERO_MASK_LEFT")] = LL('⋊');

        // Other shadow-hero runs to the right.

    result[LL("OTHER_HERO_MASK_RIGHT")] = LL('⋉');

        // Other shadow-hero is falling.

    result[LL("OTHER_HERO_MASK_FALL")] = LL('⋣');

        // Other shadow-hero is crawling along the pipe.

    result[LL("OTHER_HERO_MASK_PIPE")] = LL('⊣');

        // Other shadow-hero in the pit.

    result[LL("OTHER_HERO_MASK_PIT")] = LL('ᗏ');

        // Enemy hero is dead. In the next tick, it will disappear and
        // appear in a new location.

    result[LL("ENEMY_HERO_DIE")] = LL('Ž');

        // Enemy hero is climbing the ladder.

    result[LL("ENEMY_HERO_LADDER")] = LL('Ǔ');

        // Enemy hero runs to the left.

    result[LL("ENEMY_HERO_LEFT")] = LL('❫');

        // Enemy hero runs to the right.

    result[LL("ENEMY_HERO_RIGHT")] = LL('❪');

        // Enemy hero is falling.

    result[LL("ENEMY_HERO_FALL")] = LL('⋥');

        // Enemy hero is crawling along the pipe.

    result[LL("ENEMY_HERO_PIPE")] = LL('Ǯ');

        // Enemy hero in the pit.

    result[LL("ENEMY_HERO_PIT")] = LL('⇇');

        // Enemy shadow-hero is dead. In the next tick, it will
        // disappear and appear in a new location.

    result[LL("ENEMY_HERO_MASK_DIE")] = LL('⧓');

        // Enemy shadow-hero is climbing the ladder.

    result[LL("ENEMY_HERO_MASK_LADDER")] = LL('≠');

        // Enemy shadow-hero runs to the left.

    result[LL("ENEMY_HERO_MASK_LEFT")] = LL('⧒');

        // Enemy shadow-hero runs to the right.

    result[LL("ENEMY_HERO_MASK_RIGHT")] = LL('⧑');

        // Enemy shadow-hero is falling.

    result[LL("ENEMY_HERO_MASK_FALL")] = LL('⌫');

        // Enemy shadow-hero is crawling along the pipe.

    result[LL("ENEMY_HERO_MASK_PIPE")] = LL('❵');

        // Enemy shadow-hero in the pit.

    result[LL("ENEMY_HERO_MASK_PIT")] = LL('⬱');

        // Robber is climbing the ladder.

    result[LL("ROBBER_LADDER")] = LL('Q');

        // Robber runs to the left. Robber picks up the nearest prey
        // and hunts for it until it overtakes it.

    result[LL("ROBBER_LEFT")] = LL('«');

        // Robber runs to the right. Robber picks up the nearest prey
        // and hunts for it until it overtakes it.

    result[LL("ROBBER_RIGHT")] = LL('»');

        // Robber is falling.

    result[LL("ROBBER_FALL")] = LL('‹');

        // Robber is crawling along the pipe.

    result[LL("ROBBER_PIPE")] = LL('<');

        // Robber in the pit.

    result[LL("ROBBER_PIT")] = LL('⍇');

        // Opened golden gates. Can only be locked with a golden key.

    result[LL("OPENED_DOOR_GOLD")] = LL('⍙');

        // Opened silver gates. Can only be locked with a silver key.

    result[LL("OPENED_DOOR_SILVER")] = LL('⍚');

        // Opened bronze gates. Can only be locked with a bronze key.

    result[LL("OPENED_DOOR_BRONZE")] = LL('⍜');

        // Closed golden gates. Can only be opened with a golden key.

    result[LL("CLOSED_DOOR_GOLD")] = LL('⍍');

        // Closed silver gates. Can only be opened with a silver key.

    result[LL("CLOSED_DOOR_SILVER")] = LL('⌺');

        // Closed bronze gates. Can only be opened with a bronze key.

    result[LL("CLOSED_DOOR_BRONZE")] = LL('⌼');

        // Bronze key. Helps open/close golden gates. The key can only
        // be used once.

    result[LL("KEY_GOLD")] = LL('✦');

        // Silver key. Helps open/close silver gates. The key can only
        // be used once.

    result[LL("KEY_SILVER")] = LL('✼');

        // Bronze key. Helps open/close bronze gates. The key can only
        // be used once.

    result[LL("KEY_BRONZE")] = LL('⍟');

        // Bullet. After the shot by the hero, the bullet flies until
        // it meets an obstacle. The bullet kills the hero. It
        // ricochets from the indestructible wall (no more than 1
        // time). The bullet destroys the destructible wall.

    result[LL("BULLET")] = LL('•');

        // Ladder - the hero can move along the level along it.

    result[LL("LADDER")] = LL('H');

        // Pipe - the hero can also move along the level along it, but
        // only horizontally.

    result[LL("PIPE")] = LL('~');

        // Back door - allows the hero to secretly move to another
        // random place on the map.

    result[LL("BACKWAY")] = LL('⊛');

        // Disguise potion - endow the hero with additional abilities.
        // The hero goes into shadow mode.

    result[LL("MASK_POTION")] = LL('S');

    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();
