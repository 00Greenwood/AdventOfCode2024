#include "Day20.hxx"
#include "precompiled.hxx"

Day20::Day20() : Day(20) {
}

Day20::~Day20() {
}

void Day20::initialize() {
  parse(name(), m_input);
  for (int y = 0; y < m_input.size(); ++y) {
    for (int x = 0; x < m_input.at(y).size(); ++x) {
      switch (m_input.at(y).at(x)) {
      case '.':
        m_maze.insert_or_assign(Position(x, y), SPACE);
        break;
      case '#':
        m_maze.insert_or_assign(Position(x, y), WALL);
        break;
      case 'S':
        m_maze.insert_or_assign(Position(x, y), SPACE);
        m_start = Position(x, y);
        break;
      case 'E':
        m_maze.insert_or_assign(Position(x, y), SPACE);
        m_end = Position(x, y);
        break;
      }
    }
  }
}

std::string Day20::solve(Part part) const {
  Path path = solveMaze();

  size_t max = part == PART_1 ? 2 : 20;
  size_t total = 0;

  for (size_t i = 0; i < path.size(); ++i) {
    Position start = path.at(i);
    for (size_t j = i + 3; j < path.size(); ++j) {
      Position end = path.at(j);
      size_t length = abs(start.x - end.x) + abs(start.y - end.y);
      if (length >= 2 && length <= max) {
        size_t cheat = j - i - length;
        if (cheat >= 100) {
          total++;
        }
      }
    }
  }

  return std::to_string(total);
}

Day20::Path Day20::solveMaze() const {
  Path path;
  std::set<Position> visited;
  path.push_back(m_start);
  visited.insert(m_start);

  // A* search algorithm
  std::queue<Position> check;
  check.push(m_start);

  while (!check.empty()) {
    Position current = check.front();
    check.pop();

    if (current == m_end) {
      break;
    }

    for (const auto& direction : Direction::DIRECTIONS) {
      Position next = current + direction;
      if (m_maze.contains(next)) {
        if (m_maze.at(next) == WALL) {
          // Wall!
        } else {
          if (!visited.contains(next)) {
            path.push_back(next);
            check.push(next);
            visited.insert(next);
          }
        }
      }
    }
  }

  return path;
}
