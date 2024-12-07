#include <Day7.hxx>
#include <parse.hxx>

#include <cmath>

Day7::Day7() : Day(7) {
}

Day7::~Day7() {
}

void Day7::initialize() {
  parse(name(), m_input);
}

std::string Day7::solve(Part part) const {
  size_t calibration = 0;
  for (const auto& equation : m_input) {
    if (validEquation(equation, 2, equation.at(1), part)) {
      calibration += equation.at(0);
    }
  }

  return std::to_string(calibration);
}

bool Day7::validEquation(const std::vector<size_t>& equation, int index, size_t total, Part part) const {
  if (index == equation.size()) {
    // Base case, we have reached the end of the equation.
    return total == equation.at(0);
  }

  size_t addition = total + equation.at(index);
  if (addition <= equation.at(0)) {
    if (validEquation(equation, index + 1, addition, part)) {
      return true;
    }
  }

  size_t multiply = total * equation.at(index);
  if (multiply <= equation.at(0)) {
    if (validEquation(equation, index + 1, multiply, part)) {
      return true;
    }
  }

  if (part == PART_2) {
    // We need to account for 100 giving us 2 instead of 3, so we add 1.
    int exponent = std::ceil(std::log10(equation.at(index) + 1));
    size_t concat = total * std::pow(10, exponent) + equation.at(index);
    if (concat <= equation.at(0)) {
      if (validEquation(equation, index + 1, concat, part)) {
        return true;
      }
    }
  }

  return false;
}
