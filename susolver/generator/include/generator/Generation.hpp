#pragma once
#include "generator/Permutations.hpp"
#include "sudoku/Grid.hpp"

namespace Sudoku {
struct Generated {
  Grid problem;
  Grid solution;
};
Permutations::ListOfCells getInitialMatrix();
Sudoku::Generated generateRandomGrid(unsigned seed, unsigned size);
} // namespace Sudoku