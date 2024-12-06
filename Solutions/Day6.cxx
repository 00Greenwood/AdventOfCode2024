#include <Day6.hxx>
#include <parse.hxx>

Day6::Day6() : Day(6) {
}

Day6::~Day6() {
}

void Day6::initialize() {
  parse(name(), m_input);
  for (int i = 0; i < m_input.size(); ++i) {
    for (int j = 0; j < m_input.at(i).size(); ++j) {
      if (m_input.at(i).at(j) == '#') {
        m_walls.insert({i, j});
      } else if (m_input.at(i).at(j) == '^') {
        m_start = {i, j};
      }
    }
  }
}

std::string Day6::solve(Part part) const {
  std::vector<std::pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  auto inBounds = [this](const std::pair<int, int>& position) -> bool {
    return position.first >= 0 && position.second >= 0 && position.first < m_input.size() &&
           position.second < m_input.size();
  };
  std::set<std::pair<int, int>> positions;
  std::set<std::pair<std::pair<int, int>, int>> walk;

  {
    int directionIndex = 0;
    std::pair<int, int> current = m_start;
    while (inBounds(current)) {
      if (m_walls.contains(current)) {
        // Hit a wall, move back one space, rotate and continue.
        current.first -= directions.at(directionIndex).first;
        current.second -= directions.at(directionIndex).second;
        directionIndex = (directionIndex + 1) % 4;
      } else {
        positions.insert(current);
        walk.insert({current, directionIndex});
      }
      current.first += directions.at(directionIndex).first;
      current.second += directions.at(directionIndex).second;
    }
  }

  if (part == PART_1) {
    return std::to_string(positions.size());
  }

  std::set<std::pair<int, int>> obstructions;
  for (const auto& [position, direction] : walk) {
    if (position == m_start) {
      continue;
    }
    std::set<std::pair<std::pair<int, int>, int>> loop;
    // Save time by starting just before the new obstruction.
    std::pair<int, int> current = m_start;
    int directionIndex = 0;

    while (inBounds(current)) {
      if (loop.contains({current, directionIndex})) {
        obstructions.insert(position);
        break;
      }

      if (m_walls.contains(current) || current == position) {
        // Hit a wall, move back one space, rotate and continue.
        current.first -= directions.at(directionIndex).first;
        current.second -= directions.at(directionIndex).second;
        directionIndex = (directionIndex + 1) % 4;
      } else {
        loop.insert({current, directionIndex});
      }
      current.first += directions.at(directionIndex).first;
      current.second += directions.at(directionIndex).second;
    }
  }

  return std::to_string(obstructions.size());
}
