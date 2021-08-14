#pragma once
#include "generator/Permutations.hpp"
#include "sudoku/Grid.hpp"

namespace Sudoku {
Permutations::ListOfCells getInitialMatrix();
Sudoku::Grid generateRandomGrid(unsigned seed, unsigned size);
} // namespace Sudoku