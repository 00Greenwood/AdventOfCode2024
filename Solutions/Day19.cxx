#include "precompiled.hxx"
#include <Day19.hxx>

Day19::Day19() : Day(19) {
}

Day19::~Day19() {
}

void Day19::initialize() {
  parse(name(), m_input);
  bool afterBreak = false;
  for (const auto& line : m_input) {
    if (line.empty()) {
      afterBreak = true;
    } else if (afterBreak) {
      m_patterns.push_back(line);
    } else {
      const std::regex towelRegex("[a-z]+");
      auto it = std::sregex_iterator(line.begin(), line.end(), towelRegex);
      while (it != std::sregex_iterator()) {
        m_towels.push_back(it++->str());
      }
    }
  }
}

std::string Day19::solve(Part part) const {
  std::map<std::string, size_t> cache;
  size_t total = 0;
  for (const auto& pattern : m_patterns) {
    total += validPatterns(pattern, cache, part);
  }

  return std::to_string(total);
}

size_t Day19::validPatterns(const std::string& pattern, std::map<std::string, size_t>& cache, Part part) const {
  if (pattern.empty()) {
    return 1;
  }
  if (cache.contains(pattern)) {
    return cache.at(pattern);
  }
  size_t valid = 0;
  for (const auto& towel : m_towels) {
    if (pattern.starts_with(towel)) {
      valid += validPatterns(pattern.substr(towel.size()), cache, part);
      if (part == PART_1 && valid > 0) {
        break;
      }
    }
  }
  cache.insert_or_assign(pattern, valid);
  return valid;
}
