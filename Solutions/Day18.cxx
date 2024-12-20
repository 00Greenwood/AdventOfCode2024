#include "precompiled.hxx"

Day18::Day18() : Day(18) {
}

Day18::~Day18() {
}

void Day18::initialize() {
  parse(name(), m_input);
  for (const auto& line : m_input) {
    m_bytes.push_back(Position(line.at(0), line.at(1)));
  }
}

std::string Day18::solve(Part part) const {
  size_t time = 1024;
  Position end = Position(70, 70);
  size_t lower = 0;
  size_t upper = m_bytes.size();

  while (true) {
    std::set<Position> corrupted;
    for (int i = 0; i < time; i++) {
      corrupted.insert(m_bytes.at(i));
    }

    // A* search algorithm
    std::queue<Position> check;
    check.push(Position(0, 0));

    std::map<Position, int> path;
    path[Position(0, 0)] = 0;

    while (!check.empty()) {
      Position current = check.front();
      check.pop();

      if (current == end) {
        continue;
      }

      for (const auto& direction : Direction::DIRECTIONS) {
        Position next = current + direction;
        if (next.x < 0 || next.x > end.x || next.y < 0 || next.y > end.y) {
          continue;
        }
        if (corrupted.contains(next)) {
          continue;
        }
        if (path.contains(next)) {
          if (path[next] > path[current] + 1) {
            path[next] = path[current] + 1;
            check.push(next);
          }
        } else {
          path[next] = path[current] + 1;
          check.push(next);
        }
      }
    }
    if (part == PART_1) {
      return std::to_string(path[end]);
    }
    if (!path.contains(end)) {
      // Too high!
      upper = time;
    }
    if (path.contains(end)) {
      if (lower == time) {
        // We have found the minimum number of time that the path is OK!
        std::stringstream ss;
        Position blockByte = m_bytes.at(time);
        ss << blockByte.x << ',' << blockByte.y;
        return ss.str();
      }
      // Too low!
      lower = time;
    }
    time = static_cast<size_t>((upper + lower) / 2);
  }

  throw std::runtime_error("No solution found!");
}
