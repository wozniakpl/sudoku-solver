#include "sudoku/Grid.hpp"
#include "sudoku/Constraints.hpp"
#include "sudoku/Coordinates.hpp"
#include "sudoku/Number.hpp"
#include <map>
#include <stdexcept>

namespace {
auto isValid(const Sudoku::Subgrid &subgrid) {
  auto valuesMap = std::map<Sudoku::Number, std::uint8_t>{};
  for (const auto &number : subgrid.getCells()) {
    const auto &value = number.getValue();
    if (value == 0) {
      continue;
    }
    if (valuesMap.count(value)) {
      return false;
    } else {
      valuesMap.insert(std::make_pair(value, 1));
    }
  }
  return true;
}
} // namespace

namespace {
Sudoku::Number toValue(char c) {
  if (c == '.' || c == '0') {
    return 0;
  }
  if (c < '0' || c > '9') {
    throw std::invalid_argument("Invalid character in grid");
  }
  return int(c) - '0';
}
} // namespace
namespace Sudoku {
Grid::Grid() {
  this->matrix = Subgrids{};
  for (int i = 0; i < 9; ++i) {
    this->matrix.push_back(Subgrid{});
  }
}

Grid::Grid(const Subgrids &matrix) {
  if (!Constraints::isMatrixTheRightSize(matrix)) {
    throw std::invalid_argument("Matrix is not 9x9");
  }
  this->matrix = matrix;
}

Subgrids Grid::getRows() const { return matrix; }

Grid::Grid(const std::string &text) {
  if (text.size() != 81) {
    throw std::invalid_argument("String is not 81 characters long");
  }

  for (int i = 0; i < 9; i++) {
    this->matrix.push_back(Subgrid());
    for (int j = 0; j < 9; j++) {
      const auto index = i * 9 + j;
      matrix[i][j] = Cell(toValue(text[index]));
    }
  }
}

Grid &Grid::set(Coordinates coords, Number number) {
  this->matrix[coords.row][coords.column] = number;
  return *this;
}

bool Grid::isValid() const {
  for (std::uint8_t i = 0; i < 9; i++) {
    if (!::isValid(getRow(i)) || !::isValid(getColumn(i)) ||
        !::isValid(getBox(i))) {
      return false;
    }
  }
  return true;
}

Subgrid Grid::getRow(std::uint8_t index) const { return matrix[index]; }
Subgrid Grid::getColumn(std::uint8_t index) const {
  Subgrid output;
  for (std::uint8_t i = 0; i < 9; i++) {
    output[i] = matrix[i].getCells()[index];
  }
  return output;
}
Subgrid Grid::getBox(std::uint8_t index) const {
  Subgrid output;
  const auto xrange = std::make_pair(3 * (index % 3), 3 * (index % 3) + 2);
  const auto yrange = std::make_pair(3 * (index / 3), 3 * (index / 3) + 2);
  std::uint8_t i = 0;
  for (std::uint8_t y = yrange.first; y <= yrange.second; y++) {
    for (std::uint8_t x = xrange.first; x <= xrange.second; x++) {
      output[i++] = matrix[x].getCells()[y];
    }
  }
  return output;
}
} // namespace Sudoku