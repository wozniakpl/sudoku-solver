#include "algorithm/Utils.hpp"
#include "sudoku/Coordinates.hpp"
#include "sudoku/Grid.hpp"
#include "utils/String.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;
using namespace Utils;

namespace {
auto expectPossibilities(const Sudoku::Grid &grid, Sudoku::Coordinates coords,
                         Sudoku::Number size) {
  EXPECT_EQ(Algorithm::Utils::getPossibleValues(grid, coords).size(), size);
}
} // namespace

class UtilsTests : public Test {
public:
  UtilsTests() {}
};

TEST_F(UtilsTests, GettingPossibleValues) {
  const auto zeros = std::string{"000000000"};
  const auto grid = Sudoku::Grid(zeros * 8 + "123456789");

  expectPossibilities(grid, Sudoku::Coordinates{7, 0}, 6);
  expectPossibilities(grid, Sudoku::Coordinates{7, 1}, 6);
  expectPossibilities(grid, Sudoku::Coordinates{7, 2}, 6);
  expectPossibilities(grid, Sudoku::Coordinates{0, 0}, 8);
  expectPossibilities(grid, Sudoku::Coordinates{0, 1}, 8);
  expectPossibilities(grid, Sudoku::Coordinates{0, 2}, 8);
}
