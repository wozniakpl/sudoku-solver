#include "sudoku/Constraints.hpp"

namespace Sudoku::Constraints {
bool isRowTheRightSize(const Sudoku::Cells &row) { return row.size() == 9; }

bool isMatrixTheRightSize(const Sudoku::Subgrids &matrix) {
  if (matrix.size() != 9) {
    return false;
  }
  for (auto &row : matrix) {
    if (!isRowTheRightSize(row.getCells())) {
      return false;
    }
  }
  return true;
}
} // namespace Sudoku::Constraints