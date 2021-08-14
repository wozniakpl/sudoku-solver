#pragma once

#include "sudoku/Number.hpp"
#include <ostream>
#include <vector>

namespace Sudoku {
class Cell {
public:
  Cell() = default;
  Cell(Number);
  Number getValue() const;

  bool operator==(const Cell &other) const { return other.value == value; }
  bool operator==(const Number &other) const { return other == value; }
  bool isSet() const { return value != 0; }

  friend std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    return os << std::to_string(cell.value);
  }

private:
  Number value;
};
using Cells = std::vector<Cell>;
} // namespace Sudoku