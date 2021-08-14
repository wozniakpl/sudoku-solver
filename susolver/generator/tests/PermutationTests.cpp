#include "generator/Generation.hpp"
#include "generator/Permutations.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

Permutations::ListOfCells getInitialMatrix() {
  const auto expected1 = Sudoku::Cells{1, 2, 3, 4, 5, 6, 7, 8, 9};
  const auto expected2 = Sudoku::Cells{4, 5, 6, 7, 8, 9, 1, 2, 3};
  const auto expected3 = Sudoku::Cells{7, 8, 9, 1, 2, 3, 4, 5, 6};
  const auto expected4 = Sudoku::Cells{2, 3, 4, 5, 6, 7, 8, 9, 1};
  const auto expected5 = Sudoku::Cells{5, 6, 7, 8, 9, 1, 2, 3, 4};
  const auto expected6 = Sudoku::Cells{8, 9, 1, 2, 3, 4, 5, 6, 7};

  const auto matrix = Sudoku::getInitialMatrix();

  EXPECT_EQ(matrix.size(), 9);
  EXPECT_EQ(matrix[0], expected1);
  EXPECT_EQ(matrix[1], expected2);
  EXPECT_EQ(matrix[2], expected3);
  EXPECT_EQ(matrix[3], expected4);
  EXPECT_EQ(matrix[4], expected5);
  EXPECT_EQ(matrix[5], expected6);
  return matrix;
}

class GeneratorTests : public Test {
public:
  GeneratorTests() {}
};

TEST_F(GeneratorTests, CreatesInitialMatrix) {
  const auto _ = getInitialMatrix();
}

TEST_F(GeneratorTests, ApplyingEmptyVerticalPermutation) {
  Permutations::ListOfCells listOfCells;
  auto matrix = getInitialMatrix();
  const auto before = matrix;
  const auto permutation = std::vector<size_t>{0, 1, 2};
  const auto row = 0;
  Permutations::applyVerticalPermutation(permutation, matrix, row);
  EXPECT_EQ(matrix, before);
}

TEST_F(GeneratorTests, ApplyingVerticalPermutation) {
  Permutations::ListOfCells listOfCells;
  auto matrix = getInitialMatrix();
  const auto before = matrix;

  const auto permutation = std::vector<size_t>{0, 2, 1};
  const auto first_row = 0;
  EXPECT_EQ(matrix[0], before[0]);
  EXPECT_EQ(matrix[1], before[1]);
  EXPECT_EQ(matrix[2], before[2]);
  Permutations::applyVerticalPermutation(permutation, matrix, first_row);
  EXPECT_EQ(matrix[0], before[0]);
  EXPECT_EQ(matrix[1], before[2]);
  EXPECT_EQ(matrix[2], before[1]);

  const auto second_permutation = std::vector<size_t>{2, 1, 0};
  const auto second_row = 1;
  EXPECT_EQ(matrix[3], before[3]);
  EXPECT_EQ(matrix[4], before[4]);
  EXPECT_EQ(matrix[5], before[5]);
  Permutations::applyVerticalPermutation(second_permutation, matrix,
                                         second_row);
  EXPECT_EQ(matrix[3], before[5]);
  EXPECT_EQ(matrix[4], before[4]);
  EXPECT_EQ(matrix[5], before[3]);
}

TEST_F(GeneratorTests, ApplyingHorizontalPermutation) {
  Permutations::ListOfCells listOfCells;
  auto matrix = getInitialMatrix();
  const auto before = matrix;

  const auto permutation = std::vector<size_t>{0, 2, 1};
  const auto first_row = 0;
  EXPECT_EQ(matrix[0][0], before[0][0]);
  EXPECT_EQ(matrix[0][1], before[0][1]);
  EXPECT_EQ(matrix[0][2], before[0][2]);
  Permutations::applyHorizontalPermutation(permutation, matrix, first_row);
  EXPECT_EQ(matrix[0][0], before[0][0]);
  EXPECT_EQ(matrix[0][1], before[0][2]);
  EXPECT_EQ(matrix[0][2], before[0][1]);

  const auto second_permutation = std::vector<size_t>{2, 1, 0};
  const auto second_row = 1;
  EXPECT_EQ(matrix[0][3], before[0][3]);
  EXPECT_EQ(matrix[0][4], before[0][4]);
  EXPECT_EQ(matrix[0][5], before[0][5]);
  Permutations::applyHorizontalPermutation(second_permutation, matrix,
                                           second_row);
  EXPECT_EQ(matrix[0][3], before[0][5]);
  EXPECT_EQ(matrix[0][4], before[0][4]);
  EXPECT_EQ(matrix[0][5], before[0][3]);
}