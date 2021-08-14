#include "sudoku/Subgrid.hpp"
#include "sudoku/Constraints.hpp"

namespace Sudoku {
Subgrid::Subgrid() {
  this->cells = Cells{};
  for (unsigned i = 0; i < 9; ++i) {
    this->cells.push_back(Cell{});
  }
}

Subgrid::Subgrid(const Cells &cells) {
  if (!Constraints::isRowTheRightSize(cells)) {
    throw std::invalid_argument("Subgrid does not have 9 elements");
  }
  this->cells = cells;
}

Cells Subgrid::getCells() const { return cells; }

Subgrid::IteratorType Subgrid::begin() const { return cells.begin(); }
Subgrid::IteratorType Subgrid::end() const { return cells.end(); }
std::size_t Subgrid::size() const { return cells.size(); }
Cell &Subgrid::operator[](std::size_t index) { return cells[index]; }
} // namespace Sudoku