#include "algorithm/BruteForce.hpp"
#include "algorithm/Rules.hpp"
#include "algorithm/Utils.hpp"

namespace {
bool _solve(Sudoku::Grid &input, Sudoku::Grid currentGrid,
            Sudoku::SetOfCoordinates remainding) {
  if (Sudoku::Rules::isSolved(currentGrid)) {
    input = currentGrid;
    return true;
  }

  for (const auto &coords : remainding) {
    auto newRemainding = remainding;
    newRemainding.erase(coords);
    const auto possibleValues =
        Algorithm::Utils::getPossibleValues(currentGrid, coords);
    for (const auto &possibility : possibleValues) {
      if (_solve(input, currentGrid.set(coords, possibility), newRemainding)) {
        return true;
      }
    }
  }

  return false;
}

bool solve(Sudoku::Grid &grid) {
  return _solve(grid, grid, Algorithm::Utils::getEmptyCoordinates(grid));
}
} // namespace

namespace Sudoku {
Solution BruteForce::solve(const Grid &grid) {
  auto solution = grid;
  auto success = ::solve(solution);
  return Solution{
      solution,
      success,
  };
}
} // namespace Sudoku