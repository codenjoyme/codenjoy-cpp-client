/*-
 * #%L
 * Codenjoy - it's a dojo-like platform from developers to developers.
 * %%
 * Copyright (C) 2012 - 2022 Codenjoy
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

#include "pch.h"
#include "engine/utils.h"
#include "games/mollymage/Board.h"
#include "games/mollymage/Element.h"

TEST(getAtTest, BoardTest) {
    StringStream ss;
    ss << "xxx";
    ss << "&&&";
    ss << "###";

    Board board(ss.str());

    EXPECT_EQ(board.getAt(0, 0)->ch(), Element('#').ch());
    EXPECT_EQ(board.getAt(1, 1)->ch(), Element('&').ch());
    EXPECT_EQ(board.getAt(2, 2)->ch(), Element('x').ch());
}

TEST(isAtTest, BoardTest) {
    StringStream ss;
    ss << "xxx";
    ss << "&&&";
    ss << "###";

    Board board(ss.str());

    EXPECT_EQ(true, board.isAt(0, 2, new Element('x')));
    EXPECT_EQ(true, board.isAt(1, 1, new Element('&')));
    EXPECT_EQ(true, board.isAt(2, 0, new Element('#')));
    EXPECT_EQ(false, board.isAt(0, 1, new Element('#')));
    EXPECT_EQ(false, board.isAt(2, 1, new Element('#')));
}

TEST(isAtListTest, BoardTest) {
    StringStream ss;
    ss << "xxx";
    ss << "&&&";
    ss << "###";

    Board board(ss.str());

    std::list<CharElement*> elements1 = {new Element('x'), new Element('&')};
    EXPECT_EQ(false, board.isAt(1, 0, elements1));

    std::list<CharElement*> elements2 = {new Element('#'), new Element('&')};
    EXPECT_EQ(true, board.isAt(1, 0, elements2));
}

TEST(boardSizeTest, BoardTest) {
    StringStream ss;
    ss << "xxx";
    ss << "&&&";
    ss << "###";

    Board board(ss.str());

    EXPECT_EQ(3, board.boardSize());
}

TEST(isNearTest1, BoardTest) {
    StringStream ss;
    ss << "   ";
    ss << "  #";
    ss << "   ";

    Board board(ss.str());

    EXPECT_EQ(true, board.isNear(1, 1, new Element('#')));
}

TEST(isNearTest2, BoardTest) {
    StringStream ss;
    ss << " # ";
    ss << "   ";
    ss << "   ";

    Board board(ss.str());

    EXPECT_EQ(true, board.isNear(1, 1, new Element('#')));
}

TEST(isNearTest3, BoardTest) {
    StringStream ss;
    ss << "   ";
    ss << "#  ";
    ss << "   ";

    Board board(ss.str());

    EXPECT_EQ(true, board.isNear(1, 1, new Element('#')));
}

TEST(isNearTest4, BoardTest) {
    StringStream ss;
    ss << "   ";
    ss << "   ";
    ss << " # ";

    Board board(ss.str());

    EXPECT_EQ(true, board.isNear(1, 1, new Element('#')));
}

TEST(isNearTest5, BoardTest) {
    StringStream ss;
    ss << "   ";
    ss << " # ";
    ss << "   ";

    Board board(ss.str());

    EXPECT_EQ(true, board.isNear(1, 1, new Element('#')));
}

TEST(isNearTest6, BoardTest) {
    StringStream ss;
    ss << "#  ";
    ss << "   ";
    ss << "   ";

    Board board(ss.str());

    EXPECT_EQ(false, board.isNear(1, 1, new Element('#')));
}

TEST(countNearTest1, BoardTest) {
    StringStream ss;
    ss << "  #";
    ss << "# #";
    ss << "  #";

    Board board(ss.str());

    EXPECT_EQ(2, board.countNear(1, 1, new Element('#')));
}

TEST(countNearTest2, BoardTest) {
    StringStream ss;
    ss << "# #";
    ss << "   ";
    ss << "# #";

    Board board(ss.str());

    EXPECT_EQ(0, board.countNear(1, 1, new Element('#')));
}

TEST(getFutureBlasts, BoardTest) {
    StringStream ss;
    ss << ".☼☼..";
    ss << ".3☼..";
    ss << ".☼...";
    ss << "..&2&";
    ss << "1♥...";

    Board board(ss.str());

    String expected = L"[0,1], [3,4], [0,3], [3,0], [0,2], [3,3], [3,2]";
    StringStream actual;
    for (Point i : board.getFutureBlasts()) {
        ss << i.toString() << " ";
    }
    EXPECT_EQ(expected, actual.str());
}