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

#include "Element.h"

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

    /// your Molly
    result[LL("HERO")] = LL('☺');                      // This is what she usually looks like
    result[LL("POTION_HERO")] = LL('☻');              // This is if she is sitting on own potion
    result[LL("DEAD_HERO")] = LL('Ѡ');                 // Oops, your Molly is dead (don't worry, she will appear somewhere in next move).
                                                              // You're getting penalty points for each death.

    /// other players heroes
    result[LL("OTHER_HERO")] = LL('♥');                // This is what other heroes looks like.
    result[LL("OTHER_POTION_HERO")] = LL('♠');         // This is if other hero is sitting on own potion.
    result[LL("OTHER_DEAD_HERO")] = LL('♣');           // Other hero corpse (it will disappear shortly,
                                                              // right on the next move).
                                                              // If you've done it you'll get score points.

    /// enemy players heroes

    result[LL("ENEMY_HERO")] = LL('ö');                // This is what enemy heroes looks like.
    result[LL("ENEMY_POTION_HERO")] = LL('Ö');         // This is if enemy hero is sitting on own potion.
    result[LL("ENEMY_DEAD_HERO")] = LL('ø');           // Enemy hero corpse (it will disappear shortly,
                                                              // right on the next move).
                                                              // If you've done it you'll get score points.

    /// the potions
    result[LL("POTION_TIMER_5")] = LL('5');            // After Molly set the potion, the timer starts (5 ticks).
    result[LL("POTION_TIMER_4")] = LL('4');            // This will blow up after 4 ticks.
    result[LL("POTION_TIMER_3")] = LL('3');            // This after 3...
    result[LL("POTION_TIMER_2")] = LL('2');            // Two..
    result[LL("POTION_TIMER_1")] = LL('1');            // One.
    result[LL("BOOM")] = LL('҉');                      // Boom! this is what is potion does everything that is destroyable got destroyed

    /// walls
    result[LL("WALL")] = LL('☼');                      // Indestructible wall - it will not fall from potion.
    result[LL("TREASURE_BOX")] = LL('#');              // This is a treasure box, it opens with an explosion.
    result[LL("OPENING_TREASURE_BOX")] = LL('H');      // this is like a treasure box opens looks like, it will disappear on next move.
                                                              // if it's you did it - you'll get score points. Perhaps a prize will appear.

    /// soulless creatures
    result[LL("GHOST")] = LL('&');                      // This guys runs over the board randomly and gets in the way all the time.
                                                              // If it will touch Molly - she will die. You'd better kill this piece of ... soul,
                                                              // you'll get score points for it.
    result[LL("DEAD_GHOST")] = LL('x');                  // this is ghost corpse

    /// perks
    result[LL("POTION_BLAST_RADIUS_INCREASE")] = LL('+'); // Potion blast radius increase. Applicable only to new potions. The perk is temporary.
    result[LL("POTION_COUNT_INCREASE")] = LL('c');         // Increase available potions count. Number of extra potions can be set in settings. Temporary.
    result[LL("POTION_REMOTE_CONTROL")] = LL('r');         // Potion blast not by timer but by second act. Number of RC triggers is limited and can be set in settings.
    result[LL("POTION_IMMUNE")] = LL('i');                 // Do not die after potion blast (own potion and others as well). Temporary.
    result[LL("POISON_THROWER")] = LL('T');                 // Hero can shoot by poison cloud. Temporary.
    result[LL("POTION_EXPLODER")] = LL('A');                 // Hero can explode all potions on the field. Temporary.

    /// a void
    result[LL("NONE")] = LL(' ');                         // This is the only place where you can move your Molly.
    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();
