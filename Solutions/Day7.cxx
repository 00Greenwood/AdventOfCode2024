#include <Day7.hxx>
#include <parse.hxx>

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
    if (validEquation(equation, 2, equation.at(1))) {
      calibration += equation.at(0);
    }
  }

  return std::to_string(calibration);
}

bool Day7::validEquation(const std::vector<size_t>& equation, int index, size_t total) const {
  if (index == equation.size()) {
    // Base case, we have reached the end of the equation.
    return false;
  }

  size_t answer = equation.at(0);

  size_t addition = total + equation.at(index);
  if (addition == answer) {
    return true;
  } else if (addition < answer) {
    if (validEquation(equation, index + 1, addition)) {
      return true;
    }
  }

  size_t multiply = total * equation.at(index);
  if (multiply == answer) {
    return true;
  } else if (multiply < answer) {
    if (validEquation(equation, index + 1, multiply)) {
      return true;
    }
  }

  return false;
}
