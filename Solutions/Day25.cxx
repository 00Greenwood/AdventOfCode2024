#include "precompiled.hxx"
#include <Day25.hxx>

Day25::Day25() : Day(25) {
}

Day25::~Day25() {
}

void Day25::initialize() {
  parse(name(), m_input);
  std::vector<std::vector<std::string>> blocks;
  {
    std::vector<std::string> block;
    for (const auto& line : m_input) {
      if (line.empty()) {
        blocks.push_back(block);
        block.clear();
      } else {
        block.push_back(line);
      }
    }
    blocks.push_back(block);
  }

  for (const auto& block : blocks) {
    std::vector<int> heights{0, 0, 0, 0, 0};
    for (int i = 1; i < block.size() - 1; ++i) {
      for (int j = 0; j < block[i].size(); ++j) {
        if (block[i][j] == '#') {
          heights[j] += 1;
        }
      }
    }

    if (block[0][0] == '.') {
      m_keys.push_back(heights);
    } else {
      m_locks.push_back(heights);
    }
  }
}

std::string Day25::solve(Part) const {
  size_t total = 0;
  for (const auto& key : m_keys) {
    for (const auto& lock : m_locks) {
      bool overlap = false;
      for (int i = 0; i < key.size(); ++i) {
        if (key[i] + lock[i] > 5) {
          overlap = true;
        }
      }
      if (!overlap) {
        total++;
      }
    }
  }

  return std::to_string(total);
}
