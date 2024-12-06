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
  const std::vector<Position> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  auto inBounds = [this](const Position& position) -> bool {
    return position.x >= 0 && position.y >= 0 && position.x < m_input.size() &&
           position.y < m_input.size();
  };
  std::unordered_set<Position, PositionHash> positions;
  std::unordered_set<PositionAndDirection, PositionAndDirectionHash> walk;

  {
    int direction = 0;
    Position current = m_start;
    while (inBounds(current)) {
      if (m_walls.contains(current)) {
        // Hit a wall, move back one space, rotate and continue.
        current -= directions.at(direction);
        direction = (direction + 1) % 4;
      } else {
        positions.insert(current);
        walk.insert({current, direction});
      }
      current += directions.at(direction);
    }
  }

  if (part == PART_1) {
    return std::to_string(positions.size());
  }

  std::unordered_set<Position, PositionHash> obstructions;
  for (const auto& [position, direction] : walk) {
    if (position == m_start) {
      continue;
    }
    std::unordered_set<PositionAndDirection, PositionAndDirectionHash> loop;
    // Save time by starting just before the new obstruction.
    Position current = m_start;
    int direction = 0;

    while (inBounds(current)) {
      if (loop.contains({current, direction})) {
        obstructions.insert(position);
        break;
      }

      if (m_walls.contains(current) || current == position) {
        // Hit a wall, move back one space, rotate and continue.
        current -= directions.at(direction);
        direction = (direction + 1) % 4;
      } else {
        loop.insert({current, direction});
      }
      current += directions.at(direction);
    }
  }

  return std::to_string(obstructions.size());
}
