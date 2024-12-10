#include <Day10.hxx>
#include <Direction.hxx>
#include <parse.hxx>

Day10::Day10() : Day(10) {
}

Day10::~Day10() {
}

void Day10::initialize() {
  parse(name(), m_input);
  for (int y = 0; y < m_input.size(); ++y) {
    for (int x = 0; x < m_input[y].size(); ++x) {
      m_map[Position(x, y)] = m_input[y][x] - '0';
      if (m_input[y][x] == '0') {
        m_trailheads.push_back(Position(x, y));
      }
    }
  }
}

std::string Day10::solve(Part part) const {
  int total = 0;
  for (const auto& trailhead : m_trailheads) {
    std::set<Position> peaks;
    if (part == PART_1) {
      checkTrail(trailhead, peaks);
      total += peaks.size();
    } else {
      total += checkTrail(trailhead, peaks);
    }
  }
  return std::to_string(total);
}

int Day10::checkTrail(const Position& position, std::set<Position>& peaks) const {
  int total = 0;
  int currentElevation = m_map.at(position);
  if (currentElevation == 9) {
    peaks.insert(position);
    return 1;
  }
  for (const auto& direction : DIRECTIONS) {
    Position next = position + direction;
    if (m_map.contains(next)) {
      int nextElevation = m_map.at(next);
      if (nextElevation == currentElevation + 1) {
        total += checkTrail(next, peaks);
      }
    }
  }
  return total;
}
