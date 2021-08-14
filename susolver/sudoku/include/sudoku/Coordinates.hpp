#pragma once

#include <cstdint>
#include <set>

namespace Sudoku {
struct Coordinates {
  std::uint8_t row;
  std::uint8_t column;

  bool operator<(const Coordinates &other) const;

  bool operator==(const Coordinates &other) const;
};

using SetOfCoordinates = std::set<Coordinates>;
} // namespace Sudoku