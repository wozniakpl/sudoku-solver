#include "algorithm/Utils.hpp"
#include <functional>

namespace {
Sudoku::SetOfCoordinates
getFilteredCoordinates(const Sudoku::Grid &grid,
                       std::function<bool(Sudoku::Cell)> condition) {
  Sudoku::SetOfCoordinates emptyCells;
  const auto &rows = grid.getRows();
  for (std::uint8_t i = 0; i < rows.size(); i++) {
    const auto &row = rows[i];
    const auto &cells = row.getCells();
    for (std::uint8_t j = 0; j < row.size(); j++) {
      if (condition(cells[j])) {
        emptyCells.insert(Sudoku::Coordinates{i, j});
      }
    }
  }
  return emptyCells;
}
} // namespace

namespace Algorithm::Utils {
Sudoku::SetOfCoordinates getEmptyCoordinates(const Sudoku::Grid &grid) {
  return getFilteredCoordinates(
      grid, [](const Sudoku::Cell &cell) { return !cell.isSet(); });
}

Sudoku::SetOfCoordinates getNotEmptyCoordinates(const Sudoku::Grid &grid) {
  return getFilteredCoordinates(
      grid, [](const Sudoku::Cell &cell) { return cell.isSet(); });
}

Sudoku::SetOfNumbers getPossibleValues(const Sudoku::Grid &grid,
                                       Sudoku::Coordinates coords) {
  Sudoku::SetOfNumbers possibleValues;
  for (std::uint8_t i = 1; i <= 9; i++) {
    auto newGrid = grid;
    if (newGrid.set(coords, Sudoku::Number(i)).isValid()) {
      possibleValues.insert(Sudoku::Number(i));
    }
  }
  return possibleValues;
}
} // namespace Algorithm::Utils