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

#ifndef BOARD_H
#define BOARD_H

#include "utils.h"

#include "Point.h"
#include "LengthToXY.h"
#include "CharElement.h"

class AbstractBoard {
public:
    AbstractBoard(String boardString = LL(""));

    CharElement* getAt(int x, int y) const;
    bool isAt(int x, int y, CharElement* el) const;
    bool isAt(int x, int y, std::list<CharElement*> els) const;

    int boardSize() const;

    bool isNear(int x, int y, CharElement* el) const;
    int countNear(int x, int y, CharElement* el) const;

protected:
    PointList findAll(CharElement* el) const;
    int inversionX(int x) const;
    int inversionY(int y) const;
    String boardAsString() const;
    virtual CharElement* valueOf(Char ch) const = 0;

    String board;
    int size;
    LengthToXY xyl;
};

#endif
