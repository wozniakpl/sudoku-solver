#pragma once

#include <algorithm>

namespace Sudoku::Rules {
auto isEveryCellSet(const Sudoku::Grid &grid) {
  const auto &rows = grid.getRows();
  return !std::any_of(rows.begin(), rows.end(), [](const auto &row) {
    return std::any_of(row.begin(), row.end(),
                       [](const auto &cell) { return cell.getValue() == 0; });
  });
}

auto isSolved(const Sudoku::Grid &grid) {
  return isEveryCellSet(grid) && grid.isValid();
}
} // namespace Sudoku::Rules