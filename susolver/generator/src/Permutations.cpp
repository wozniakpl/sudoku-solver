#include "generator/Permutations.hpp"
#include "algorithm/Utils.hpp"
#include <functional>
#include <vector>

namespace Permutations {
const auto possiblePermutations = std::vector<Permutation>{
    {0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0},
};

void applyVerticalPermutation(const Permutation &permutation,
                              ListOfCells &listOfCells, const size_t row) {
  ListOfCells newMatrix;
  newMatrix.reserve(9);
  for (size_t i = 0; i < 9; i++) {
    const auto index = // TODO
        (i >= 3 * row && i < 3 * row + 3) ? permutation[i % 3] + 3 * row : i;
    newMatrix.push_back(listOfCells[index]);
  }
  listOfCells = newMatrix;
}

void applyHorizontalPermutation(const Permutation &permutation,
                                ListOfCells &listOfCells, const size_t row) {
  ListOfCells newMatrix;
  for (size_t i = 0; i < 9; i++) {
    Sudoku::Cells cells;
    cells.reserve(9);
    for (size_t j = 0; j < 9; j++) {
      const auto index = // TODO
          (j >= 3 * row && j < 3 * row + 3) ? permutation[j % 3] + 3 * row : j;
      cells.push_back(listOfCells[i][index]);
    }
    newMatrix.push_back(cells);
  }
  listOfCells = newMatrix;
}

void shuffle(ListOfCells &matrix, std::mt19937 &generator) {
  for (size_t i = 0; i < 3; i++) {
    const auto &permutation = [&]() {
      return *Algorithm::Utils::selectRandom(
          possiblePermutations.begin(), possiblePermutations.end(), generator);
    };
    applyVerticalPermutation(permutation(), matrix, i);
    applyHorizontalPermutation(permutation(), matrix, i);
    // TODO: by groups
  }
}
} // namespace Permutations