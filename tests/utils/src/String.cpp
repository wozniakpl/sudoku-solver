#include "utils/String.hpp"
#include <sstream>

namespace Utils {
std::string operator*(std::string a, unsigned int b) {
  std::stringstream output;
  while (b--) {
    output << a;
  }
  return output.str();
}
} // namespace Utils