#pragma once

#include "sudoku/Cell.hpp"
#include "sudoku/Subgrid.hpp"
#include <random>
#include <vector>

namespace Permutations {
using ListOfCells = std::vector<Sudoku::Cells>;
using Permutation = std::vector<size_t>;

void applyVerticalPermutation(const Permutation &, ListOfCells &, const size_t);
void applyHorizontalPermutation(const Permutation &, ListOfCells &,
                                const size_t);

void shuffle(ListOfCells &, std::mt19937 &);
} // namespace Permutations
