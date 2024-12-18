#include "precompiled.hxx"

Day1::Day1() : Day(1) {
}

Day1::~Day1() {
}

void Day1::initialize() {
  parse(name(), m_input);
  std::sort(m_input.first.begin(), m_input.first.end());
  std::sort(m_input.second.begin(), m_input.second.end());
}

std::string Day1::solve(Part part) const {
  if (part == Day::PART_1) {
    int difference = 0;
    for (int i = 0; i < m_input.first.size(); ++i) {
      difference += std::abs(m_input.first.at(i) - m_input.second.at(i));
    }
    return std::to_string(difference);
  } else {
    std::map<int, int> occurrences;
    for (const auto& number : m_input.first) {
      if (occurrences.count(number) > 0) {
        occurrences.at(number)++;
      } else {
        occurrences.insert({number, 1});
      }
    }
    int score = 0;
    for (const auto& number : m_input.second) {
      if (occurrences.count(number) > 0) {
        score += occurrences.at(number) * number;
      }
    }
    return std::to_string(score);
  }
}
