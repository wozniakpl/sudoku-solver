#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "algorithm/BruteForce.hpp"

using namespace ::testing;

class BruteForceTests : public Test {
public:
  BruteForceTests() {}
};

TEST_F(BruteForceTests, CanSolveEasyProblem) { EXPECT_EQ(0, 0); }
