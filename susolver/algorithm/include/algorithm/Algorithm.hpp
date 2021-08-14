#pragma once

#include "algorithm/Solution.hpp"
#include "sudoku/Grid.hpp"

namespace Sudoku {
class Algorithm {
public:
  virtual ~Algorithm() = default;
  virtual Solution solve(const Grid &) = 0;
};
} // namespace Sudoku