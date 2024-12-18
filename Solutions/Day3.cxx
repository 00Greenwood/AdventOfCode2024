#include "precompiled.hxx"

Day3::Day3() : Day(3) {
}

Day3::~Day3() {
}

void Day3::initialize() {
  parse(name(), m_input);
}

std::string Day3::solve(Part part) const {
  std::regex numbersRegex("\\d+");
  std::regex equationRegex("mul\\(\\d+,\\d+\\)|don't\\(\\)|do\\(\\)");
  auto it = std::sregex_iterator(m_input.begin(), m_input.end(), equationRegex);
  int total = 0;
  bool enabled = true;
  while (it != std::sregex_iterator()) {
    std::string equation = it++->str();
    if (equation == "don't()") {
      enabled = false;
      continue;
    } else if (equation == "do()") {
      enabled = true;
      continue;
    } else if (part == PART_2 && !enabled) {
      continue;
    }
    auto numbersIt = std::sregex_iterator(equation.begin(), equation.end(), numbersRegex);
    int mul = 1;
    while (numbersIt != std::sregex_iterator()) {
      mul *= std::stoi(numbersIt++->str());
    }
    total += mul;
  }
  return std::to_string(total);
}
