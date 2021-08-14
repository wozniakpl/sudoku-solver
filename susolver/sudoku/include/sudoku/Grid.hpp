#pragma once

#include "sudoku/Coordinates.hpp"
#include "sudoku/Subgrid.hpp"
#include <cstdint>

namespace Sudoku {
class Grid {
public:
  using IteratorType = Subgrids::const_iterator;
  Grid();
  Grid(const Subgrids &);
  Grid(const std::string &);

  Subgrids getRows() const;

  Subgrid getRow(std::uint8_t) const;
  Subgrid getColumn(std::uint8_t) const;
  Subgrid getBox(std::uint8_t) const;

  bool isValid() const;

  Grid &set(Coordinates, Number);

private:
  Subgrids matrix;
};
} // namespace Sudoku