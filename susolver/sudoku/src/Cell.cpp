#include "sudoku/Cell.hpp"
namespace Sudoku {
Cell::Cell(Number number) {
  if (!(number >= 0 && number <= 9)) {
    throw std::invalid_argument("Cell's value must be between 0 and 9");
  }
  this->value = number;
}

Number Cell::getValue() const { return value; }
} // namespace Sudoku