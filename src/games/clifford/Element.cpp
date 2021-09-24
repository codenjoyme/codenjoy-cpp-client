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
    throw std::invalid_argument("Element::valueOf(Char ch): No such Elment for " + ch);
}

bool Element::operator==(const Element& el) const {
    return elem == el.elem;
}

ElementMap Element::initialiseElements() {
    ElementMap mapOfElements;
    mapOfElements[LL("NONE")] = LL(' ');                     // Пустое место – по которому может двигаться детектив

    mapOfElements[LL("BRICK")] = LL('#');                    // Cтена в которой можно прострелить дырочку слева или справа от детектива
                                                             // (в зависимости от того, куда он сейчас смотрит)

    mapOfElements[LL("PIT_FILL_1")] = LL('1');               // Стена со временем зарастает. Когда процес начинается - мы видим таймер
    mapOfElements[LL("PIT_FILL_2")] = LL('2');
    mapOfElements[LL("PIT_FILL_3")] = LL('3');
    mapOfElements[LL("PIT_FILL_4")] = LL('4');

    mapOfElements[LL("STONE")] = LL('☼');                    // Неразрушаемая стена - в ней ничего прострелить не получится

    mapOfElements[LL("CRACK_PIT")] = LL('*');                // В момент выстрела мы видим процесс так

    mapOfElements[LL("CLUE_KNIFE")] = LL('$');               // Улика нож
    mapOfElements[LL("CLUE_GLOVE")] = LL('&');               // Улика перчатка
    mapOfElements[LL("CLUE_RING")] = LL('@');                // Улика кольцо

    // Твой детектив в зависимости от того, чем он сейчас занят отображается следующими символами
    mapOfElements[LL("HERO_DIE")] = LL('Ѡ');                 // Детектив переживает процесс умирания
    mapOfElements[LL("HERO_CRACK_LEFT")] = LL('Я');          // Детектив простреливает слева от себя
    mapOfElements[LL("HERO_CRACK_RIGHT")] = LL('R');         // Детектив простреливает справа от себя
    mapOfElements[LL("HERO_LADDER")] = LL('Y');              // Детектив находится на лестнице
    mapOfElements[LL("HERO_LEFT")] = LL('◄');                // Детектив бежит влево
    mapOfElements[LL("HERO_RIGHT")] = LL('►');               // Детектив бежит вправо
    mapOfElements[LL("HERO_FALL_LEFT")] = LL(']');           // Детектив падает, смотря влево
    mapOfElements[LL("HERO_FALL_RIGHT")] = LL('[');          // Детектив падает, смотря вправо
    mapOfElements[LL("HERO_PIPE_LEFT")] = LL('{');           // Детектив ползёт по трубе влево
    mapOfElements[LL("HERO_PIPE_RIGHT")] = LL('}');          // Детектив ползёт по трубе вправо
    mapOfElements[LL("HERO_PIT_LEFT")] = LL('⍃');            // Детектив в яме смотрит влево
    mapOfElements[LL("HERO_PIT_RIGHT")] = LL('⍄');           // Детектив в яме смотрит вправо

    // Тоже твой детектив, но под маскировкой:
    mapOfElements[LL("HERO_MASK_DIE")] = LL('x');          // Детектив-маскировка переживает процесс умирания // TODO test me
    mapOfElements[LL("HERO_MASK_CRACK_LEFT")] = LL('⊰');   // Детектив-маскировка простреливает слева от себя
    mapOfElements[LL("HERO_MASK_CRACK_RIGHT")] = LL('⊱');  // Детектив-маскировка простреливает справа от себя
    mapOfElements[LL("HERO_MASK_LADDER")] = LL('⍬');       // Детектив-маскировка находится на лестнице
    mapOfElements[LL("HERO_MASK_LEFT")] = LL('⊲');         // Детектив-маскировка бежит влево
    mapOfElements[LL("HERO_MASK_RIGHT")] = LL('⊳');        // Детектив-маскировка бежит вправо
    mapOfElements[LL("HERO_MASK_FALL_LEFT")] = LL('⊅');    // Детектив-маскировка падает, смотря влево
    mapOfElements[LL("HERO_MASK_FALL_RIGHT")] = LL('⊄');   // Детектив-маскировка падает, смотря вправо
    mapOfElements[LL("HERO_MASK_PIPE_LEFT")] = LL('⋜');    // Детектив-маскировка ползёт по трубе влево
    mapOfElements[LL("HERO_MASK_PIPE_RIGHT")] = LL('⋝');   // Детектив-маскировка ползёт по трубе вправо
    mapOfElements[LL("HERO_MASK_PIT_LEFT")] = LL('ᐊ');     // Детектив-маскировка в яме смотрит влево
    mapOfElements[LL("HERO_MASK_PIT_RIGHT")] = LL('ᐅ');    // Детектив-маскировка в яме смотрит вправо

    // Детективы других игроков отображаются так
    mapOfElements[LL("OTHER_HERO_DIE")] = LL('Z');           // Другой детектив переживает процесс умирания
    mapOfElements[LL("OTHER_HERO_CRACK_LEFT")] = LL('⌋');    // Другой детектив простреливает слева от себя       // TODO test me
    mapOfElements[LL("OTHER_HERO_CRACK_RIGHT")] = LL('⌊');   // Другой детектив простреливает справа от себя      // TODO test me
    mapOfElements[LL("OTHER_HERO_LADDER")] = LL('U');        // Другой детектив находится на лестнице
    mapOfElements[LL("OTHER_HERO_LEFT")] = LL(')');          // Другой детектив бежит влево
    mapOfElements[LL("OTHER_HERO_RIGHT")] = LL('(');         // Другой детектив бежит вправо
    mapOfElements[LL("OTHER_HERO_FALL_LEFT")] = LL('⊐');     // Другой детектив падает, смотря влево        // TODO test me
    mapOfElements[LL("OTHER_HERO_FALL_RIGHT")] = LL('⊏');    // Другой детектив падает, смотря вправо       // TODO test me
    mapOfElements[LL("OTHER_HERO_PIPE_LEFT")] = LL('Э');     // Другой детектив ползёт по трубе влево
    mapOfElements[LL("OTHER_HERO_PIPE_RIGHT")] = LL('Є');    // Другой детектив ползёт по трубе вправо
    mapOfElements[LL("OTHER_HERO_PIT_LEFT")] = LL('ᗉ');      // Другой детектив в яме смотрит влево
    mapOfElements[LL("OTHER_HERO_PIT_RIGHT")] = LL('ᗆ');     // Другой детектив в яме смотрит вправо

    // А если детективы других игроков под маскировкой, то так
    mapOfElements[LL("OTHER_HERO_MASK_DIE")] = LL('⋈');          // Другой детектив-маскировка переживает процесс умирания
    mapOfElements[LL("OTHER_HERO_MASK_CRACK_LEFT")] = LL('⋰');   // Другой детектив-маскировка простреливает слева от себя       // TODO test me
    mapOfElements[LL("OTHER_HERO_MASK_CRACK_RIGHT")] = LL('⋱');  // Другой детектив-маскировка простреливает справа от себя      // TODO test me
    mapOfElements[LL("OTHER_HERO_MASK_LEFT")] = LL('⋊');         // Другой детектив-маскировка находится на лестнице
    mapOfElements[LL("OTHER_HERO_MASK_RIGHT")] = LL('⋉');        // Другой детектив-маскировка бежит влево
    mapOfElements[LL("OTHER_HERO_MASK_LADDER")] = LL('⋕');       // Другой детектив-маскировка бежит вправо
    mapOfElements[LL("OTHER_HERO_MASK_FALL_LEFT")] = LL('⋣');    // Другой детектив-маскировка падает, смотря влево        // TODO test me
    mapOfElements[LL("OTHER_HERO_MASK_FALL_RIGHT")] = LL('⋢');   // Другой детектив-маскировка падает, смотря вправо       // TODO test me
    mapOfElements[LL("OTHER_HERO_MASK_PIPE_LEFT")] = LL('⊣');    // Другой детектив-маскировка ползёт по трубе влево
    mapOfElements[LL("OTHER_HERO_MASK_PIPE_RIGHT")] = LL('⊢');   // Другой детектив-маскировка ползёт по трубе вправо
    mapOfElements[LL("OTHER_HERO_MASK_PIT_LEFT")] = LL('ᗏ');      // Другой детектив-маскировка в яме смотрит влево
    mapOfElements[LL("OTHER_HERO_MASK_PIT_RIGHT")] = LL('ᗌ');     // Другой детектив-маскировка в яме смотрит вправо

    // Вражеские детективы других игроков отображаются так
    mapOfElements[LL("ENEMY_HERO_DIE")] = LL('Ž');           // Вражеский детектив переживает процесс умирания       // TODO test me
    mapOfElements[LL("ENEMY_HERO_CRACK_LEFT")] = LL('⟧');    // Вражеский детектив простреливает слева от себя       // TODO test me
    mapOfElements[LL("ENEMY_HERO_CRACK_RIGHT")] = LL('⟦');   // Вражеский детектив простреливает справа от себя      // TODO test me
    mapOfElements[LL("ENEMY_HERO_LADDER")] = LL('Ǔ');        // Вражеский детектив находится на лестнице       // TODO test me
    mapOfElements[LL("ENEMY_HERO_LEFT")] = LL('❫');          // Вражеский детектив бежит влево       // TODO test me
    mapOfElements[LL("ENEMY_HERO_RIGHT")] = LL('❪');         // Вражеский детектив бежит вправо       // TODO test me
    mapOfElements[LL("ENEMY_HERO_FALL_LEFT")] = LL('⋥');     // Вражеский детектив падает, смотря влево        // TODO test me
    mapOfElements[LL("ENEMY_HERO_FALL_RIGHT")] = LL('⋤');    // Вражеский детектив падает, смотря вправо       // TODO test me
    mapOfElements[LL("ENEMY_HERO_PIPE_LEFT")] = LL('Ǯ');     // Вражеский детектив ползёт по трубе влево       // TODO test me
    mapOfElements[LL("ENEMY_HERO_PIPE_RIGHT")] = LL('Ě');    // Вражеский детектив ползёт по трубе вправо       // TODO test me
    mapOfElements[LL("ENEMY_HERO_PIT_LEFT")] = LL('⇇');      // Вражеский детектив в яме смотрит влево
    mapOfElements[LL("ENEMY_HERO_PIT_RIGHT")] = LL('⇉');     // Вражеский детектив в яме смотрит вправо

    // А если вражеские детективы других игроков под маскировкой, то так
    mapOfElements[LL("ENEMY_HERO_MASK_DIE")] = LL('⧓');          // Вражеский детектив-маскировка переживает процесс умирания       // TODO test me
    mapOfElements[LL("ENEMY_HERO_MASK_CRACK_LEFT")] = LL('⇢');   // Вражеский детектив-маскировка простреливает слева от себя       // TODO test me
    mapOfElements[LL("ENEMY_HERO_MASK_CRACK_RIGHT")] = LL('⇠');  // Вражеский детектив-маскировка простреливает справа от себя      // TODO test me
    mapOfElements[LL("ENEMY_HERO_MASK_LEFT")] = LL('⧒');         // Вражеский детектив-маскировка находится на лестнице       // TODO test me
    mapOfElements[LL("ENEMY_HERO_MASK_RIGHT")] = LL('⧑');        // Вражеский детектив-маскировка бежит влево       // TODO test me
    mapOfElements[LL("ENEMY_HERO_MASK_LADDER")] = LL('≠');       // Вражеский детектив-маскировка бежит вправо       // TODO test me
    mapOfElements[LL("ENEMY_HERO_MASK_FALL_LEFT")] = LL('⌫');    // Вражеский детектив-маскировка падает, смотря влево        // TODO test me
    mapOfElements[LL("ENEMY_HERO_MASK_FALL_RIGHT")] = LL('⌦');   // Вражеский детектив-маскировка падает, смотря вправо       // TODO test me
    mapOfElements[LL("ENEMY_HERO_MASK_PIPE_LEFT")] = LL('❵');    // Вражеский детектив-маскировка ползёт по трубе влево       // TODO test me
    mapOfElements[LL("ENEMY_HERO_MASK_PIPE_RIGHT")] = LL('❴');   // Вражеский детектив-маскировка ползёт по трубе вправо       // TODO test me
    mapOfElements[LL("ENEMY_HERO_MASK_PIT_LEFT")] = LL('⬱');     // Вражеский детектив-маскировка в яме смотрит влево
    mapOfElements[LL("ENEMY_HERO_MASK_PIT_RIGHT")] = LL('⇶');    // Вражеский детектив-маскировка в яме смотрит вправо

    // Боты-воры
    mapOfElements[LL("ROBBER_LADDER")] = LL('Q');
    mapOfElements[LL("ROBBER_LEFT")] = LL('«');
    mapOfElements[LL("ROBBER_RIGHT")] = LL('»');
    mapOfElements[LL("ROBBER_FALL_LEFT")] = LL('‹');
    mapOfElements[LL("ROBBER_FALL_RIGHT")] = LL('›');
    mapOfElements[LL("ROBBER_PIPE_LEFT")] = LL('<');
    mapOfElements[LL("ROBBER_PIPE_RIGHT")] = LL('>');
    mapOfElements[LL("ROBBER_PIT_LEFT")] = LL('⍇');
    mapOfElements[LL("ROBBER_PIT_RIGHT")] = LL('⍈');

    mapOfElements[LL("LADDER")] = LL('H');               // Лестница - по ней можно перемещаться по уровню
    mapOfElements[LL("PIPE")] = LL('~');                 // Труба - по ней так же можно перемещаться по уровню, но только горизонтально

    mapOfElements[LL("BACKWAY")] = LL('⊛');               // Черный ход - позволяет скрыто перемещаться в иное место на карте

    mapOfElements[LL("MASK_POTION")] = LL('S');         // Маскировочное зелье - наделяют детектива дополнительными способностями

    mapOfElements[LL("OPENED_DOOR_GOLD")] = LL('⍙');
    mapOfElements[LL("OPENED_DOOR_SILVER")] = LL('⍚');
    mapOfElements[LL("OPENED_DOOR_BRONZE")] = LL('⍜');

    mapOfElements[LL("CLOSED_DOOR_GOLD")] = LL('⍍');
    mapOfElements[LL("CLOSED_DOOR_SILVER")] = LL('⌺');
    mapOfElements[LL("CLOSED_DOOR_BRONZE")] = LL('⌼');

    mapOfElements[LL("KEY_GOLD")] = LL('✦');
    mapOfElements[LL("KEY_SILVER")] = LL('✼');
    mapOfElements[LL("KEY_BRONZE")] = LL('⍟');

    return mapOfElements;
};

const ElementMap Element::Elements = Element::initialiseElements();
