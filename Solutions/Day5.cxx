#include <Day5.hxx>
#include <parse.hxx>

#include <regex>
#include <sstream>

Day5::Day5() : Day(5) {
}

Day5::~Day5() {
}

void Day5::initialize() {
  std::string input;
  parse(name(), input);

  int index = input.find("\n\n");
  std::string orderingsInput = input.substr(0, index);
  std::string manualsInput = input.substr(index + 2);

  std::regex numbersRegex("\\d+");

  // Parse orderings.
  {
    std::stringstream ss(orderingsInput);
    std::string line;
    while (std::getline(ss, line, '\n')) {
      auto it = std::sregex_iterator(line.begin(), line.end(), numbersRegex);
      while (it != std::sregex_iterator()) {
        int left = std::stoi(it++->str());
        int right = std::stoi(it++->str());
        m_orderings.emplace_back(left, right);
      }
    }
  }

  // Parse manuals
  {
    std::stringstream ss(manualsInput);
    std::string line;
    while (std::getline(ss, line, '\n')) {
      auto it = std::sregex_iterator(line.begin(), line.end(), numbersRegex);
      std::vector<int> manual;
      while (it != std::sregex_iterator()) {
        manual.push_back(std::stoi(it++->str()));
      }
      m_manuals.push_back(manual);
    }
  }
}

std::string Day5::solve(Part part) const {
  std::vector<std::vector<int>> incorrectManuals;

  int middlePages = 0;
  for (const auto& manual : m_manuals) {
    bool correct = true;
    for (const auto& [first, second] : m_orderings) {
      auto firstIndex = std::find(manual.begin(), manual.end(), first) - manual.begin();
      auto secondIndex = std::find(manual.begin(), manual.end(), second) - manual.begin();
      if (firstIndex != manual.size() && secondIndex != manual.size()) {
        if (firstIndex > secondIndex) {
          correct = false;
          incorrectManuals.push_back(manual);
          break;
        }
      }
    }
    if (part == PART_1 && correct) {
      middlePages += manual.at((manual.size() - 1) / 2);
    }
  }

  if (part == PART_2) {
    auto sorter = [this](int a, int b) -> bool {
      for (const auto& [first, second] : m_orderings) {
        if (first == a && second == b) {
          return true;
        }
      }
      return false;
    };

    for (auto& manual : incorrectManuals) {
      std::sort(manual.begin(), manual.end(), sorter);
      middlePages += manual.at((manual.size() - 1) / 2);
    }
  }

  return std::to_string(middlePages);
}
