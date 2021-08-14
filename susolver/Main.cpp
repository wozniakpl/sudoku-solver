#include "algorithm/BruteForce.hpp"
#include "generator/Generation.hpp"
#include "sudoku/Grid.hpp"
#include <boost/program_options.hpp>
#include <iostream>
#include <random>
#include <string>

namespace po = boost::program_options;

auto getProgramOptions(int argc, char **argv, po::options_description desc) {
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);
  return vm;
}

auto createOptionsDescription() {
  po::options_description desc("Allowed options");
  desc.add_options()("help,h", "Produce help message")(
      "inline,i", po::value<std::string>(),
      "Grid written line by line, e.g. 123000456789... with total of 81 "
      "numbers from 0 to 9")("generate,g", po::value<unsigned>(),
                             "Return random board with given empty cells")(
      "seed,s", po::value<unsigned>(), "Seed for random number generator");
  return desc;
}

auto toString(const Sudoku::Grid &grid) {
  std::stringstream ss;
  for (const auto &row : grid.getRows()) {
    for (const auto &cell : row.getCells()) {
      ss << std::to_string(cell.getValue());
    }
  }
  return ss.str();
}

auto solveSudoku(const Sudoku::Grid &grid) {
  std::unique_ptr<Sudoku::Algorithm> algorithm =
      std::make_unique<Sudoku::BruteForce>();
  const auto result = algorithm->solve(grid);
  std::cout << toString(result.solution) << std::endl;
  return result.success ? 0 : 1;
}

auto generateSudoku(const po::variables_map &vm) {
  unsigned amountOfEmptyCells = vm["generate"].as<unsigned>();
  const auto seed = [&]() {
    if (vm.count("seed")) {
      return vm["seed"].as<unsigned>();
    }
    std::random_device os_seed;
    return os_seed();
  }();
  const auto grid = Sudoku::generateRandomGrid(seed, amountOfEmptyCells);
  std::cout << toString(grid) << std::endl;
  return 0;
}

int main(int argc, char **argv) {
  const auto desc = createOptionsDescription();
  po::variables_map vm = getProgramOptions(argc, argv, desc);
  if (vm.count("help")) {
    std::cout << desc << "\n";
    return 0;
  }

  if (vm.count("generate")) {
    return generateSudoku(vm);
  }

  if (vm.count("inline")) {
    return solveSudoku(Sudoku::Grid(vm["inline"].as<std::string>()));
  }

  std::cout << desc << "\n";
  return 0;
}