#include "generator/Generation.hpp"
#include "algorithm/Utils.hpp"
#include "sudoku/Cell.hpp"
#include "sudoku/Subgrid.hpp"
#include <algorithm>

namespace {
Permutations::ListOfCells getRandomMatrix(std::mt19937 &generator) {
  auto matrix = Sudoku::getInitialMatrix();
  Permutations::shuffle(matrix, generator);
  return matrix;
}

void setRandomFieldsBlank(Sudoku::Grid &grid, unsigned size,
                          std::mt19937 &generator) {
  auto cellsToBeBlank = Algorithm::Utils::getNotEmptyCoordinates(grid);
  for (unsigned i = 0; i < size; i++) {
    const auto &choice =
        *Algorithm::Utils::selectRandom(cellsToBeBlank, generator);
    cellsToBeBlank.erase(
        std::find(cellsToBeBlank.begin(), cellsToBeBlank.end(), choice));
    grid.set(choice, 0);
  }
}

auto convertToSubgrids(const Permutations::ListOfCells &listOfCells) {
  Sudoku::Subgrids out;
  for (const auto &cell : listOfCells) {
    out.push_back(Sudoku::Subgrid{cell});
  }
  return out;
}
} // namespace

namespace Sudoku {
Permutations::ListOfCells getInitialMatrix() {
  Permutations::ListOfCells rows;
  rows.reserve(9);
  Sudoku::Cells row{7, 8, 9, 1, 2, 3, 4, 5, 6};
  const auto shift = [](auto &subgrid, unsigned by) {
    std::rotate(subgrid.begin(), subgrid.begin() + by, subgrid.end());
  };
  for (int i = 0; i < 9; i++) {
    shift(row, 3 + (i % 3 == 0 ? (i == 0 ? 0 : 1) : 0)); // TODO
    rows.emplace_back(row);
  }
  return rows;
}

Sudoku::Generated generateRandomGrid(unsigned seed, unsigned size) {
  std::mt19937 generator(seed);
  if (size > 81) {
    throw std::invalid_argument("Size must be between 0 and 81");
  }
  const Permutations::ListOfCells matrix = getRandomMatrix(generator);
  const auto subgrids = convertToSubgrids(matrix);
  auto problem = Sudoku::Grid(subgrids);
  const auto solution = problem;
  setRandomFieldsBlank(problem, size, generator);
  return Sudoku::Generated{problem, solution};
}
} // namespace Sudoku