#include "pch.h"
#include "engine/utils.h"
#include "engine/LengthToXY.h"
#include "engine/Point.h"

TEST(getLengthTest, LengthToXYTest) {
    StringStream ss;
    ss << "...";
    ss << "...";
    ss << "...";

    LengthToXY convertor(3);

    EXPECT_EQ(1, convertor.getLength(1, 2));
    EXPECT_EQ(3, convertor.getLength(0, 1));
    EXPECT_EQ(8, convertor.getLength(2, 0));
}

TEST(getXYTest, LengthToXYTest) {
    StringStream ss;
    ss << "...";
    ss << "...";
    ss << "...";

    LengthToXY convertor(3);

    EXPECT_EQ(Point(1, 2), convertor.getXY(1));
    EXPECT_EQ(Point(0, 1), convertor.getXY(3));
    EXPECT_EQ(Point(2, 0), convertor.getXY(8));
}