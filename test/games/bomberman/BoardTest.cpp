#include "pch.h"
#include "engine/utils.h"
#include "games/bomberman/Board.h"
#include "games/bomberman/Element.h"

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