#include "pch.h"
#include "engine/utils.h"
#include "engine/RandomDice.h"
#include "engine/DirectionSolver.h"
#include "games/mollymage/YourSolver.h"

TEST(shouldWhen, YourSolverTest) {
    StringStream ss;
    ss << "☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼";
    ss << "☼☺        # # ☼";
    ss << "☼ ☼ ☼ ☼#☼ ☼ ☼ ☼";
    ss << "☼##           ☼";
    ss << "☼ ☼ ☼#☼ ☼ ☼ ☼ ☼";
    ss << "☼   #    # #  ☼";
    ss << "☼ ☼ ☼ ☼#☼ ☼ ☼ ☼";
    ss << "☼             ☼";
    ss << "☼#☼ ☼ ☼#☼ ☼ ☼#☼";
    ss << "☼  #  #       ☼";
    ss << "☼ ☼ ☼ ☼ ☼ ☼ ☼#☼";
    ss << "☼ ##      #   ☼";
    ss << "☼ ☼ ☼ ☼ ☼ ☼ ☼#☼";
    ss << "☼ #   #  &    ☼";
    ss << "☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼"

    RandomDice* rd = new RandomDice();
    DirectionSolver* dds = new YourSolver(rd);

    EXPECT_EQ(L"ACT", dds->get(ss.str()));
}
