#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sudoku/Cell.hpp"

using namespace ::testing;

class CellTest : public Test {
public:
  CellTest() {}
};

TEST_F(CellTest, CanBeInitializedEmpty) {
  const auto cell = Sudoku::Cell();
  ASSERT_EQ(cell.getValue(), 0);
}

TEST_F(CellTest, CannotBeInitializedWithWrongValue) {
  ASSERT_NO_THROW(Sudoku::Cell(1));
  ASSERT_NO_THROW(Sudoku::Cell(9));
  ASSERT_ANY_THROW(Sudoku::Cell(-1));
  ASSERT_ANY_THROW(Sudoku::Cell(10));
}