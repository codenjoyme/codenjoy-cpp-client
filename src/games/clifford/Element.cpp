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
    result[LL("NONE")] = LL(' ');                     // Пустое место – по которому может двигаться детектив

    result[LL("BRICK")] = LL('#');                    // Cтена в которой можно прострелить дырочку слева или справа от детектива
                                                             // (в зависимости от того, куда он сейчас смотрит)

    result[LL("PIT_FILL_1")] = LL('1');               // Стена со временем зарастает. Когда процес начинается - мы видим таймер
    result[LL("PIT_FILL_2")] = LL('2');
    result[LL("PIT_FILL_3")] = LL('3');
    result[LL("PIT_FILL_4")] = LL('4');

    result[LL("STONE")] = LL('☼');                    // Неразрушаемая стена - в ней ничего прострелить не получится

    result[LL("CRACK_PIT")] = LL('*');                // В момент выстрела мы видим процесс так

    result[LL("CLUE_KNIFE")] = LL('$');               // Улика нож
    result[LL("CLUE_GLOVE")] = LL('&');               // Улика перчатка
    result[LL("CLUE_RING")] = LL('@');                // Улика кольцо

    // Твой детектив в зависимости от того, чем он сейчас занят отображается следующими символами
    result[LL("HERO_DIE")] = LL('Ѡ');                 // Детектив переживает процесс умирания
    result[LL("HERO_CRACK_LEFT")] = LL('Я');          // Детектив простреливает слева от себя
    result[LL("HERO_CRACK_RIGHT")] = LL('R');         // Детектив простреливает справа от себя
    result[LL("HERO_LADDER")] = LL('Y');              // Детектив находится на лестнице
    result[LL("HERO_LEFT")] = LL('◄');                // Детектив бежит влево
    result[LL("HERO_RIGHT")] = LL('►');               // Детектив бежит вправо
    result[LL("HERO_FALL")] = LL(']');                // Детектив падает
    result[LL("HERO_PIPE_LEFT")] = LL('{');           // Детектив ползёт по трубе влево
    result[LL("HERO_PIPE_RIGHT")] = LL('}');          // Детектив ползёт по трубе вправо
    result[LL("HERO_PIT")] = LL('⍃');                 // Детектив в яме

    // Тоже твой детектив, но под маскировкой:
    result[LL("HERO_MASK_DIE")] = LL('x');          // Детектив-маскировка переживает процесс умирания // TODO test me
    result[LL("HERO_MASK_CRACK_LEFT")] = LL('⊰');   // Детектив-маскировка простреливает слева от себя
    result[LL("HERO_MASK_CRACK_RIGHT")] = LL('⊱');  // Детектив-маскировка простреливает справа от себя
    result[LL("HERO_MASK_LADDER")] = LL('⍬');       // Детектив-маскировка находится на лестнице
    result[LL("HERO_MASK_LEFT")] = LL('⊲');         // Детектив-маскировка бежит влево
    result[LL("HERO_MASK_RIGHT")] = LL('⊳');        // Детектив-маскировка бежит вправо
    result[LL("HERO_MASK_FALL")] = LL('⊅');         // Детектив-маскировка падает
    result[LL("HERO_MASK_PIPE_LEFT")] = LL('⋜');    // Детектив-маскировка ползёт по трубе влево
    result[LL("HERO_MASK_PIPE_RIGHT")] = LL('⋝');   // Детектив-маскировка ползёт по трубе вправо
    result[LL("HERO_MASK_PIT")] = LL('ᐊ');          // Детектив-маскировка в яме

    // Детективы других игроков отображаются так
    result[LL("OTHER_HERO_DIE")] = LL('Z');           // Другой детектив переживает процесс умирания
    result[LL("OTHER_HERO_CRACK_LEFT")] = LL('⌋');    // Другой детектив простреливает слева от себя       // TODO test me
    result[LL("OTHER_HERO_CRACK_RIGHT")] = LL('⌊');   // Другой детектив простреливает справа от себя      // TODO test me
    result[LL("OTHER_HERO_LADDER")] = LL('U');        // Другой детектив находится на лестнице
    result[LL("OTHER_HERO_LEFT")] = LL(')');          // Другой детектив бежит влево
    result[LL("OTHER_HERO_RIGHT")] = LL('(');         // Другой детектив бежит вправо
    result[LL("OTHER_HERO_FALL")] = LL('⊐');          // Другой детектив падает        // TODO test me
    result[LL("OTHER_HERO_PIPE_LEFT")] = LL('Э');     // Другой детектив ползёт по трубе влево
    result[LL("OTHER_HERO_PIPE_RIGHT")] = LL('Є');    // Другой детектив ползёт по трубе вправо
    result[LL("OTHER_HERO_PIT")] = LL('ᗉ');           // Другой детектив в яме

    // А если детективы других игроков под маскировкой, то так
    result[LL("OTHER_HERO_MASK_DIE")] = LL('⋈');          // Другой детектив-маскировка переживает процесс умирания
    result[LL("OTHER_HERO_MASK_CRACK_LEFT")] = LL('⋰');   // Другой детектив-маскировка простреливает слева от себя       // TODO test me
    result[LL("OTHER_HERO_MASK_CRACK_RIGHT")] = LL('⋱');  // Другой детектив-маскировка простреливает справа от себя      // TODO test me
    result[LL("OTHER_HERO_MASK_LEFT")] = LL('⋊');         // Другой детектив-маскировка находится на лестнице
    result[LL("OTHER_HERO_MASK_RIGHT")] = LL('⋉');        // Другой детектив-маскировка бежит влево
    result[LL("OTHER_HERO_MASK_LADDER")] = LL('⋕');       // Другой детектив-маскировка бежит вправо
    result[LL("OTHER_HERO_MASK_FALL")] = LL('⋣');         // Другой детектив-маскировка падает        // TODO test me
    result[LL("OTHER_HERO_MASK_PIPE_LEFT")] = LL('⊣');    // Другой детектив-маскировка ползёт по трубе влево
    result[LL("OTHER_HERO_MASK_PIPE_RIGHT")] = LL('⊢');   // Другой детектив-маскировка ползёт по трубе вправо
    result[LL("OTHER_HERO_MASK_PIT")] = LL('ᗏ');          // Другой детектив-маскировка в яме

    // Вражеские детективы других игроков отображаются так
    result[LL("ENEMY_HERO_DIE")] = LL('Ž');           // Вражеский детектив переживает процесс умирания       // TODO test me
    result[LL("ENEMY_HERO_CRACK_LEFT")] = LL('⟧');    // Вражеский детектив простреливает слева от себя       // TODO test me
    result[LL("ENEMY_HERO_CRACK_RIGHT")] = LL('⟦');   // Вражеский детектив простреливает справа от себя      // TODO test me
    result[LL("ENEMY_HERO_LADDER")] = LL('Ǔ');        // Вражеский детектив находится на лестнице       // TODO test me
    result[LL("ENEMY_HERO_LEFT")] = LL('❫');          // Вражеский детектив бежит влево       // TODO test me
    result[LL("ENEMY_HERO_RIGHT")] = LL('❪');         // Вражеский детектив бежит вправо       // TODO test me
    result[LL("ENEMY_HERO_FALL")] = LL('⋥');          // Вражеский детектив падает        // TODO test me
    result[LL("ENEMY_HERO_PIPE_LEFT")] = LL('Ǯ');     // Вражеский детектив ползёт по трубе влево       // TODO test me
    result[LL("ENEMY_HERO_PIPE_RIGHT")] = LL('Ě');    // Вражеский детектив ползёт по трубе вправо       // TODO test me
    result[LL("ENEMY_HERO_PIT")] = LL('⇇');           // Вражеский детектив в яме

    // А если вражеские детективы других игроков под маскировкой, то так
    result[LL("ENEMY_HERO_MASK_DIE")] = LL('⧓');          // Вражеский детектив-маскировка переживает процесс умирания       // TODO test me
    result[LL("ENEMY_HERO_MASK_CRACK_LEFT")] = LL('⇢');   // Вражеский детектив-маскировка простреливает слева от себя       // TODO test me
    result[LL("ENEMY_HERO_MASK_CRACK_RIGHT")] = LL('⇠');  // Вражеский детектив-маскировка простреливает справа от себя      // TODO test me
    result[LL("ENEMY_HERO_MASK_LEFT")] = LL('⧒');         // Вражеский детектив-маскировка находится на лестнице       // TODO test me
    result[LL("ENEMY_HERO_MASK_RIGHT")] = LL('⧑');        // Вражеский детектив-маскировка бежит влево       // TODO test me
    result[LL("ENEMY_HERO_MASK_LADDER")] = LL('≠');       // Вражеский детектив-маскировка бежит вправо       // TODO test me
    result[LL("ENEMY_HERO_MASK_FALL")] = LL('⌫');        // Вражеский детектив-маскировка падает        // TODO test me
    result[LL("ENEMY_HERO_MASK_PIPE_LEFT")] = LL('❵');    // Вражеский детектив-маскировка ползёт по трубе влево       // TODO test me
    result[LL("ENEMY_HERO_MASK_PIPE_RIGHT")] = LL('❴');   // Вражеский детектив-маскировка ползёт по трубе вправо       // TODO test me
    result[LL("ENEMY_HERO_MASK_PIT")] = LL('⬱');         // Вражеский детектив-маскировка в яме

    // Боты-воры
    result[LL("ROBBER_LADDER")] = LL('Q');
    result[LL("ROBBER_LEFT")] = LL('«');
    result[LL("ROBBER_RIGHT")] = LL('»');
    result[LL("ROBBER_FALL")] = LL('‹');
    result[LL("ROBBER_PIPE_LEFT")] = LL('<');
    result[LL("ROBBER_PIPE_RIGHT")] = LL('>');
    result[LL("ROBBER_PIT")] = LL('⍇');

    result[LL("LADDER")] = LL('H');               // Лестница - по ней можно перемещаться по уровню
    result[LL("PIPE")] = LL('~');                 // Труба - по ней так же можно перемещаться по уровню, но только горизонтально

    result[LL("BACKWAY")] = LL('⊛');               // Черный ход - позволяет скрыто перемещаться в иное место на карте

    result[LL("MASK_POTION")] = LL('S');         // Маскировочное зелье - наделяют детектива дополнительными способностями

    result[LL("OPENED_DOOR_GOLD")] = LL('⍙');
    result[LL("OPENED_DOOR_SILVER")] = LL('⍚');
    result[LL("OPENED_DOOR_BRONZE")] = LL('⍜');

    result[LL("CLOSED_DOOR_GOLD")] = LL('⍍');
    result[LL("CLOSED_DOOR_SILVER")] = LL('⌺');
    result[LL("CLOSED_DOOR_BRONZE")] = LL('⌼');

    result[LL("KEY_GOLD")] = LL('✦');
    result[LL("KEY_SILVER")] = LL('✼');
    result[LL("KEY_BRONZE")] = LL('⍟');

    result[LL("BULLET")] = LL('•');

    return result;
};

const ElementMap Element::Elements = Element::initialiseElements();
