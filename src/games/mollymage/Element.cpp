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
	throw std::invalid_argument("Element::valueOf(Char ch): No such Elment for " + ch);
}

bool Element::operator==(const Element& el) const {
	return elem == el.elem;
}

ElementMap Element::initialiseElements() {
	ElementMap mapOfElements;

	/// your Molly
	mapOfElements[LL("HERO")] = LL('☺');					  // This is what she usually looks like
	mapOfElements[LL("POTION_HERO")] = LL('☻');		      // This is if she is sitting on own potion
	mapOfElements[LL("DEAD_HERO")] = LL('Ѡ');                 // Oops, your Molly is dead (don't worry, she will appear somewhere in next move).
															  // You're getting penalty points for each death.

    /// other players heroes
    mapOfElements[LL("OTHER_HERO")] = LL('♥');                // This is what other heroes looks like.
    mapOfElements[LL("OTHER_POTION_HERO")] = LL('♠');         // This is if other hero is sitting on own potion.
    mapOfElements[LL("OTHER_DEAD_HERO")] = LL('♣');           // Other hero corpse (it will disappear shortly,
                                                              // right on the next move).
                                                              // If you've done it you'll get score points.

    /// enemy players heroes

    mapOfElements[LL("ENEMY_HERO")] = LL('♡');                // This is what enemy heroes looks like.
    mapOfElements[LL("ENEMY_POTION_HERO")] = LL('♤');         // This is if enemy hero is sitting on own potion.
    mapOfElements[LL("ENEMY_DEAD_HERO")] = LL('♧');           // Enemy hero corpse (it will disappear shortly,
                                                              // right on the next move).
                                                              // If you've done it you'll get score points.

	/// the potions
	mapOfElements[LL("POTION_TIMER_5")] = LL('5');            // After Molly set the potion, the timer starts (5 ticks).
	mapOfElements[LL("POTION_TIMER_4")] = LL('4');            // This will blow up after 4 ticks.
	mapOfElements[LL("POTION_TIMER_3")] = LL('3');            // This after 3...
	mapOfElements[LL("POTION_TIMER_2")] = LL('2');            // Two..
	mapOfElements[LL("POTION_TIMER_1")] = LL('1');            // One.
	mapOfElements[LL("BOOM")] = LL('҉');                      // Boom! this is what is potion does everything that is destroyable got destroyed

	/// walls
	mapOfElements[LL("WALL")] = LL('☼');                      // Indestructible wall - it will not fall from potion.
	mapOfElements[LL("TREASURE_BOX")] = LL('#');              // This is a treasure box, it opens with an explosion.
	mapOfElements[LL("OPENING_TREASURE_BOX")] = LL('H');      // this is like a treasure box opens looks like, it will disappear on next move.
															  // if it's you did it - you'll get score points. Perhaps a prize will appear.

	/// soulless creatures
	mapOfElements[LL("GHOST")] = LL('&');					  // This guys runs over the board randomly and gets in the way all the time.
															  // If it will touch Molly - she will die. You'd better kill this piece of ... soul,
															  // you'll get score points for it.
	mapOfElements[LL("DEAD_GHOST")] = LL('x');				  // this is ghost corpse

	/// perks
	mapOfElements[LL("POTION_BLAST_RADIUS_INCREASE")] = LL('+'); // Potion blast radius increase. Applicable only to new potions. The perk is temporary.
	mapOfElements[LL("POTION_COUNT_INCREASE")] = LL('c');		 // Increase available potions count. Number of extra potions can be set in settings. Temporary.
	mapOfElements[LL("POTION_REMOTE_CONTROL")] = LL('r');		 // Potion blast not by timer but by second act. Number of RC triggers is limited and can be set in settings.
	mapOfElements[LL("POTION_IMMUNE")] = LL('i');			     // Do not die after potion blast (own potion and others as well). Temporary.
	mapOfElements[LL("POISON_THROWER")] = LL('T');			     // Hero can shoot by poison cloud. Temporary.

	/// a void
	mapOfElements[LL("NONE")] = LL(' ');						 // This is the only place where you can move your Molly.
	return mapOfElements;
};

const ElementMap Element::Elements = Element::initialiseElements();
