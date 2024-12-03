#include <Day3.hxx>
#include <parse.hxx>

#include <regex>

Day3::Day3() : Day(3) {
}

Day3::~Day3() {
}

std::string Day3::solve(Part part) const {
  std::string input;
  parse(name(), input);
  std::regex numbersRegex("\\d+");
  std::regex equationRegex("mul\\(\\d+,\\d+\\)|don't\\(\\)|do\\(\\)");
  auto it = std::sregex_iterator(input.begin(), input.end(), equationRegex);
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
