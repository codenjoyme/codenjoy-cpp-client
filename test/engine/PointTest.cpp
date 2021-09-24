#include "pch.h"
#include "engine/Point.h"

TEST(equalsTest, PointTest) {
    EXPECT_EQ(true, Point(1, 2).equals(Point(1, 2)));
    EXPECT_EQ(true, Point(1, 2) == Point(1, 2));
}

TEST(setNullTest, PointTest) {
    Point p = Point(1, 2);

    EXPECT_EQ(false, p.isNull());

    p.setNull(true);
    EXPECT_EQ(true, p.isNull());
}

TEST(isBadTest, PointTest) {
    EXPECT_EQ(true, Point(-1, 10).isBad(10));
    EXPECT_EQ(true, Point(10, -1).isBad(10));
    EXPECT_EQ(true, Point(15, 10).isBad(10));
    EXPECT_EQ(true, Point(10, 15).isBad(10));
    EXPECT_EQ(false, Point(10, 10).isBad(10));
}

TEST(getSurroundsTest, PointTest) {
    StringStream ss;
    ss << "...";
    ss << ".X.";
    ss << "...";

    Point p = Point(1, 1);

    String expected = L"[0,1], [1,0], [1,2], [2,1]";
    StringStream actual;
    for (Point i : p.getSurrounds(3)) {
        ss << i.toString() << " ";
    }
    EXPECT_EQ(expected, actual.str());
}