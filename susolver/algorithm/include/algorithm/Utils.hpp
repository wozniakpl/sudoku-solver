#pragma once

#include "sudoku/Coordinates.hpp"
#include "sudoku/Grid.hpp"
#include <random>

namespace Algorithm::Utils {
Sudoku::SetOfCoordinates getEmptyCoordinates(const Sudoku::Grid &);
Sudoku::SetOfCoordinates getNotEmptyCoordinates(const Sudoku::Grid &);

Sudoku::SetOfNumbers getPossibleValues(const Sudoku::Grid &,
                                       Sudoku::Coordinates);

template <typename Iter, typename RandomGenerator>
Iter selectRandom(Iter start, Iter end, RandomGenerator &g) {
  std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
  std::advance(start, dis(g));
  return start;
}

template <typename T, typename G>
typename T::iterator selectRandom(T container, G &generator) {
  return selectRandom(container.begin(), container.end(), generator);
}

} // namespace Algorithm::Utils