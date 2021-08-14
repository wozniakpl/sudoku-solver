#pragma once

#include "sudoku/Subgrid.hpp"

namespace Sudoku::Constraints {
bool isRowTheRightSize(const Sudoku::Cells &);
bool isMatrixTheRightSize(const Sudoku::Subgrids &);

} // namespace Sudoku::Constraints