#include "sudoku/Coordinates.hpp"

namespace Sudoku {

bool Coordinates::operator<(const Coordinates &other) const {
  if (row < other.row) {
    return true;
  } else if (row == other.row) {
    if (column < other.column) {
      return true;
    }
  }
  return false;
}

bool Coordinates::operator==(const Coordinates &other) const {
  return (row == other.row) && (column == other.column);
}

} // namespace Sudoku