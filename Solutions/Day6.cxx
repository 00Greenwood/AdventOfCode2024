#include "precompiled.hxx"
#include <Day6.hxx>

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
  auto inBounds = [this](const Position& position) -> bool {
    return position.x >= 0 && position.y >= 0 && position.x < m_input.size() && position.y < m_input.size();
  };
  std::set<Position> positions;

  {
    Direction::Type direction = Direction::UP;
    Position current = m_start;
    while (inBounds(current)) {
      if (m_walls.contains(current)) {
        // Hit a wall, move back one space, rotate and continue.
        current -= Direction::DIRECTIONS[direction];
        direction = static_cast<Direction::Type>((direction + 1) % 4);
      } else {
        positions.insert(current);
      }
      current += Direction::DIRECTIONS[direction];
    }
  }

  if (part == PART_1) {
    return std::to_string(positions.size());
  }

  std::set<Position> obstructions;
  for (const auto& position : positions) {
    if (position == m_start) {
      continue;
    }
    // Save time by starting just before the new obstruction.
    Position current = m_start;
    int direction = 0;

    int walkLength = 0;
    while (inBounds(current)) {
      if (walkLength > 2 * positions.size()) {
        // If the walk length is greater than twice the number of positions in the previous loop, chances are we must be
        // in a loop.
        obstructions.insert(position);
        break;
      }

      if (m_walls.contains(current) || current == position) {
        // Hit a wall, move back one space, rotate and continue.
        current -= Direction::DIRECTIONS[direction];
        direction = static_cast<Direction::Type>((direction + 1) % 4);
      } else {
        walkLength++;
      }
      current += Direction::DIRECTIONS[direction];
    }
  }

  return std::to_string(obstructions.size());
}
