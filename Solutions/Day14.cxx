#include "precompiled.hxx"

Day14::Day14() : Day(14) {
}

Day14::~Day14() {
}

void Day14::initialize() {
  parse(name(), m_input);
  for (const auto& line : m_input) {
    m_robots.push_back(Robot(Position(line[0], line[1]), Position(line[2], line[3])));
  }
}

std::string Day14::solve(Part part) const {
  const Position grid(101, 103);
  const int midX = (grid.x - 1) / 2;

  if (part == PART_1) {

    const int midY = (grid.y - 1) / 2;
    const Position time(100, 100);

    std::vector<std::vector<Position>> quadrants{{}, {}, {}, {}};
    for (const auto& robot : m_robots) {
      Position location = robot.position;
      location += time * robot.velocity;
      location = location % grid;
      location += grid;
      location = location % grid;
      if (location.x < midX) {
        if (location.y < midY) {
          quadrants[0].push_back(location);
        } else if (location.y > midY) {
          quadrants[1].push_back(location);
        }
      } else if (location.x > midX) {
        if (location.y < midY) {
          quadrants[2].push_back(location);
        } else if (location.y > midY) {
          quadrants[3].push_back(location);
        }
      }
    }
    size_t total = 1;
    for (const auto& quadrant : quadrants) {
      total *= quadrant.size();
    }
    return std::to_string(total);
  }

  // Solution depends heavily on where the christmas tree appears on the canvas.
  std::vector<Robot> robots = m_robots;
  std::set<Position> locations;
  for (int time = 1; time <= (grid.x * grid.y); time++) {
    std::set<Position> locations;
    for (auto& robot : robots) {
      robot.position += robot.velocity;
      robot.position = robot.position % grid;
      robot.position += grid;
      robot.position = robot.position % grid;
      if (robot.position.x > 25 && robot.position.x < 60) {
        if (robot.position.y > 50 && robot.position.y < 85) {
          locations.insert(robot.position);
        }
      }
    }
    if (locations.size() > 350) {
      return std::to_string(time);
    }
  }

  return std::to_string(0);
}
