#include "sudoku/Constraints.hpp"
#include "utils/String.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;
using namespace Utils;

class ConstraintsTest : public Test {
public:
  ConstraintsTest() {}
};

TEST_F(ConstraintsTest, KnowsTheRightSizeOfMatrix) {
  const auto empty = Sudoku::Subgrid({0, 0, 0, 0, 0, 0, 0, 0, 0});
  const auto matrix = Sudoku::Subgrids{
      empty, empty, empty, empty, empty, empty, empty, empty, empty,
  };
  ASSERT_TRUE(Sudoku::Constraints::isMatrixTheRightSize(matrix));
}
