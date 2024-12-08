#include <Day8.hxx>
#include <Position.hxx>
#include <parse.hxx>

#include <set>

Day8::Day8() : Day(8) {
}

Day8::~Day8() {
}

void Day8::initialize() {
  parse(name(), m_input);
  m_height = m_input.size();
  m_width = m_input.at(0).size();
  for (int i = 0; i < m_input.size(); ++i) {
    for (int j = 0; j < m_input.at(i).size(); ++j) {
      char ch = m_input.at(i).at(j);
      if (ch == '.') {
        continue;
      }
      if (!m_antenna.contains(ch)) {
        m_antenna.emplace(ch, std::vector<Position>());
      }
      m_antenna.at(ch).emplace_back(j, i);
    }
  }
}

std::string Day8::solve(Part part) const {
  std::set<Position> nodes;

  auto inBounds = [this](const Position& position) -> bool {
    return position.x >= 0 && position.y >= 0 && position.x < m_width && position.y < m_height;
  };

  for (const auto& [ch, positions] : m_antenna) {
    for (int i = 0; i < positions.size(); ++i) {
      if (part == PART_2 && positions.size() > 1) {
        nodes.insert(positions.at(i));
      }
      for (int j = i + 1; j < positions.size(); ++j) {
        Position difference = positions.at(i) - positions.at(j);
        Position nodeOne = positions.at(i) + difference;
        while (inBounds(nodeOne)) {
          nodes.insert(nodeOne);
          if (part == PART_1) {
            break;
          }
          nodeOne += difference;
        }
        Position nodeTwo = positions.at(j) - difference;
        while (inBounds(nodeTwo)) {
          nodes.insert(nodeTwo);
          if (part == PART_1) {
            break;
          }
          nodeTwo -= difference;
        }
      }
    }
  }
  return std::to_string(nodes.size());
}
