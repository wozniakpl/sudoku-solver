#pragma once

#include "sudoku/Grid.hpp"

namespace Sudoku {
struct Solution {
  Grid solution;
  bool success;
};
} // namespace Sudoku