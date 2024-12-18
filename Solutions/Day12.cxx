#include "precompiled.hxx"

namespace {

struct Group {
  std::set<Position> positions;
};

struct Plot {
  char id;
  std::shared_ptr<Group> group;
  std::map<Direction, Position> adjacent;
};
} // namespace

Day12::Day12() : Day(12) {
}

Day12::~Day12() {
}

void Day12::initialize() {
  parse(name(), m_input);
}

std::string Day12::solve(Part part) const {
  std::map<Position, Plot> plots;
  for (int y = 0; y < m_input.size(); ++y) {
    for (int x = 0; x < m_input.at(y).size(); ++x) {
      plots[Position(x, y)] = Plot(m_input[y][x]);
    }
  }

  std::vector<std::shared_ptr<Group>> groups;

  for (const auto& [position, plot] : plots) {
    if (plot.group != nullptr) {
      continue;
    }

    std::queue<Position> positions;
    positions.push(position);

    while (positions.size() > 0) {
      Position position = positions.front();
      positions.pop();
      if (plots.at(position).group != nullptr) {
        continue;
      }

      for (const auto& direction : DIRECTIONS) {
        Position adjacent = position + direction;
        if (plots.count(adjacent) > 0 && plots.at(adjacent).id == plots.at(position).id) {
          positions.push(adjacent);
          if (plots.at(adjacent).group != nullptr && plots.at(position).group == nullptr) {
            plots.at(position).group = plots.at(adjacent).group;
            plots.at(adjacent).group->positions.insert(position);
          }
          plots.at(position).adjacent[REVERSE_DIRECTIONS[direction]] = adjacent;
        }
      }

      if (plots.at(position).group == nullptr) {
        std::set<Position> positions;
        positions.insert(position);
        groups.push_back(std::make_shared<Group>(positions));
        plots.at(position).group = groups.back();
      }
    }
  }

  const std::vector<std::pair<Direction, Direction>> L = {{UP, RIGHT}, {RIGHT, DOWN}, {DOWN, LEFT}, {LEFT, UP}};
  auto isInternalCorner = [&plots](const Position& position, const std::map<Direction, Position>& adjacent,
                                   Direction first, Direction second) -> bool {
    if (adjacent.contains(first) && adjacent.contains(second)) {
      Position corner = position;
      corner += adjacent.at(first) - position;
      corner += adjacent.at(second) - position;
      if (corner == position) {
        return false;
      }
      if (plots.at(corner).id != plots.at(position).id) {
        return true;
      }
    }
    return false;
  };

  size_t total = 0;
  for (const auto& group : groups) {
    size_t perimeter = 0;
    for (const auto& position : group->positions) {
      if (part == PART_1) {
        perimeter += 4 - plots.at(position).adjacent.size();

      } else {
        const auto& adjacent = plots.at(position).adjacent;
        switch (adjacent.size()) {
        case 0:
          perimeter += 4;
          break;
        case 1:
          perimeter += 2;
          break;
        case 2:
          if ((adjacent.contains(UP) && adjacent.contains(DOWN)) ||
              (adjacent.contains(LEFT) && adjacent.contains(RIGHT))) {
            // No corners!
          } else {
            perimeter += 1;
          }
        case 3:
        case 4:
          for (const auto& [first, second] : L) {
            if (isInternalCorner(position, adjacent, first, second)) {
              perimeter += 1;
            }
          }
          break;
        }
      }
    }
    total += group->positions.size() * perimeter;
  }

  return std::to_string(total);
}
