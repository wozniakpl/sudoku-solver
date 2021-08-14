#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sudoku/Subgrid.hpp"

using namespace ::testing;

class SubgridTest : public Test {
public:
  SubgridTest() {}
};

TEST_F(SubgridTest, CanBeInitializedEmpty) {
  const auto subgrid = Sudoku::Subgrid();

  const auto &cells = subgrid.getCells();
  ASSERT_EQ(cells.size(), 9);
  for (const auto &cell : cells) {
    ASSERT_EQ(cell.getValue(), 0);
  }
}

TEST_F(SubgridTest, CannotBeInitializedFromMatrixOfWrongSize) {
  Sudoku::Cells cells = {1, 2, 3};
  try {
    const auto subgrid = Sudoku::Subgrid(cells);
    FAIL() << "an exception should be thrown"; // EXPECT_THROW could not catch
                                               // it...
  } catch (const std::invalid_argument &) {
  } catch (...) {
    FAIL();
  }
}
