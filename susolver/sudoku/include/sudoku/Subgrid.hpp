#pragma once

#include "sudoku/Cell.hpp"
#include <vector>

namespace Sudoku {

class Subgrid {
public:
  using IteratorType = Cells::const_iterator;
  Subgrid();
  Subgrid(const Cells &);

  Cells getCells() const;

  IteratorType begin() const;
  IteratorType end() const;
  std::size_t size() const;
  Cell &operator[](std::size_t);

private:
  Cells cells;
};

using Subgrids = std::vector<Subgrid>;
} // namespace Sudoku