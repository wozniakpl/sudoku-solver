#pragma once

#include "Algorithm.hpp"

namespace Sudoku {
class BruteForce : public Algorithm {
public:
  BruteForce() = default;
  ~BruteForce() = default;
  Solution solve(const Grid &) override;
};
} // namespace Sudoku