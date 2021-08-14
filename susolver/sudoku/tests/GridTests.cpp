#include "sudoku/Grid.hpp"
#include "utils/String.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

using namespace ::testing;
using namespace Utils;

namespace {

const auto emptyRow = Sudoku::Cells{0, 0, 0, 0, 0, 0, 0, 0, 0};

} // namespace

class GridTest : public Test {
public:
  GridTest() {}
};

TEST_F(GridTest, CanBeInitializedEmpty) {
  const auto grid = Sudoku::Grid();

  const auto &rows = grid.getRows();
  ASSERT_EQ(rows.size(), 9);
  for (const auto &row : rows) {
    ASSERT_EQ(row.size(), 9);
    for (const auto &cell : row) {
      ASSERT_EQ(cell.getValue(), 0);
    }
  }
}

TEST_F(GridTest, CanBeInitializedWithMatrix) {
  const auto grid = Sudoku::Grid(Sudoku::Subgrids{
      emptyRow,
      emptyRow,
      emptyRow,
      emptyRow,
      emptyRow,
      emptyRow,
      emptyRow,
      emptyRow,
      emptyRow,
  });
  ASSERT_EQ(grid.getRows().size(), 9);
}

TEST_F(GridTest, CannotBeInitializedFromMatrixOfWrongSize) {
  const auto matrix = Sudoku::Subgrids{
      Sudoku::Subgrid(Sudoku::Cells{1, 2, 3, 4, 5, 6, 7, 8, 9}),
      Sudoku::Subgrid(Sudoku::Cells{7, 8, 9, 1, 2, 3, 4, 5, 6}),
  };

  try {
    const auto grid = Sudoku::Grid(matrix);
    FAIL() << "an exception should be thrown";
  } catch (const std::invalid_argument &) {
  }
}

TEST_F(GridTest, CanBeInitializedFromStringWithZeros) {
  const auto zeros = std::string{"000000000"};
  const auto input = "123456789" + zeros * 8;
  ASSERT_EQ(input.size(), 81);
  const auto grid = Sudoku::Grid(input);
  EXPECT_EQ(grid.getRows()[1].getCells(), emptyRow);
}

TEST_F(GridTest, CanBeInitializedFromStringWithDots) {
  const auto zeros = std::string{"........."};
  const auto input = "123456789" + zeros * 8;
  ASSERT_EQ(input.size(), 81);
  const auto grid = Sudoku::Grid(input);
  EXPECT_EQ(grid.getRows()[1].getCells(), emptyRow);
}

TEST_F(GridTest, CannotBeInitializedFromStringOFWrongSize) {
  const auto input = std::string{"123456789"};
  ASSERT_NE(input.size(), 81);
  try {
    const auto grid = Sudoku::Grid(input);
    FAIL() << "an exception should be thrown";
  } catch (const std::invalid_argument &) {
  }
}

TEST_F(GridTest, CannotBeInitializedFromStringWithWrongCharacters) {
  const auto input = std::string{"qwertyuio"} * 9;
  ASSERT_EQ(input.size(), 81);
  try {
    const auto grid = Sudoku::Grid(input);
    FAIL() << "an exception should be thrown";
  } catch (const std::invalid_argument &) {
  }
}