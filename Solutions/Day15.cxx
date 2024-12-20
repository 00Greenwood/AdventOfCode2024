#include "precompiled.hxx"

Day15::Day15() : Day(15) {
}

Day15::~Day15() {
}

void Day15::initialize() {
  parse(name(), m_input);
}

std::string Day15::solve(Part part) const {
  std::map<Position, Tile> warehouse;
  std::vector<Direction::Type> instructions;

  bool afterBreak = false;
  int y = -1;
  for (const auto& line : m_input) {
    y++;
    if (line.empty()) {
      afterBreak = true;
    }
    int x = -1;
    for (const auto& ch : line) {
      x++;
      if (afterBreak) {
        switch (ch) {
        case '>':
          instructions.push_back(Direction::RIGHT);
          break;
        case '^':
          instructions.push_back(Direction::UP);
          break;
        case '<':
          instructions.push_back(Direction::LEFT);
          break;
        case 'v':
          instructions.push_back(Direction::DOWN);
          break;
        }
      } else {
        switch (ch) {
        case '.':
          if (part == PART_2) {
            warehouse.emplace(Position(x++, y), SPACE);
            warehouse.emplace(Position(x, y), SPACE);
          } else {
            warehouse.emplace(Position(x, y), SPACE);
          }
          break;
        case '#':
          if (part == PART_2) {
            warehouse.emplace(Position(x++, y), WALL);
            warehouse.emplace(Position(x, y), WALL);
          } else {
            warehouse.emplace(Position(x, y), WALL);
          }
          break;
        case '@':
          if (part == PART_2) {
            warehouse.emplace(Position(x++, y), ROBOT);
            warehouse.emplace(Position(x, y), SPACE);
          } else {
            warehouse.emplace(Position(x, y), ROBOT);
          }
          break;
        case 'O':
          if (part == PART_2) {
            warehouse.emplace(Position(x++, y), LEFT_BOX);
            warehouse.emplace(Position(x, y), RIGHT_BOX);
          } else {
            warehouse.emplace(Position(x, y), BOX);
          }
          break;
        }
      }
    }
  }

  for (const auto instruction : instructions) {
    auto it = std::find_if(warehouse.begin(), warehouse.end(), [](const auto& pair) { return pair.second == ROBOT; });
    move(it->first, Direction::DIRECTIONS[instruction], warehouse);
  }

  int total = 0;
  for (const auto& [position, tile] : warehouse) {
    if (tile == BOX || tile == LEFT_BOX) {
      total += 100 * position.y + position.x;
    }
  }

  return std::to_string(total);
}

void Day15::move(const Position& position, const Position& direction, std::map<Position, Tile>& warehouse) const {
  if (canMove(position, direction, warehouse)) {
    Position nextPosition = position + direction;
    if (warehouse[nextPosition] == WALL) {
      return;
    }
    if (warehouse[nextPosition] == BOX) {
      move(nextPosition, direction, warehouse);
    }
    if (warehouse[nextPosition] == LEFT_BOX || warehouse[nextPosition] == RIGHT_BOX) {
      if (direction == Direction::DIRECTIONS[Direction::UP] || direction == Direction::DIRECTIONS[Direction::DOWN]) {
        Position adjacentPosition =
            nextPosition + (warehouse[nextPosition] == LEFT_BOX ? Direction::DIRECTIONS[Direction::RIGHT]
                                                                : Direction::DIRECTIONS[Direction::LEFT]);
        move(adjacentPosition, direction, warehouse);
        if (warehouse[adjacentPosition] != SPACE) {
          return;
        }
        move(nextPosition, direction, warehouse);
      } else {
        // Boxes are twice as wide!
        Position nextNextPosition = nextPosition + direction;
        move(nextNextPosition, direction, warehouse);
        if (warehouse[nextNextPosition] == SPACE) {
          warehouse[nextNextPosition] = warehouse[nextPosition];
          warehouse[nextPosition] = SPACE;
        }
      }
    }
    if (warehouse[nextPosition] == SPACE) {
      warehouse[nextPosition] = warehouse[position];
      warehouse[position] = SPACE;
    }
  }
}

bool Day15::canMove(const Position& position, const Position& direction, std::map<Position, Tile>& warehouse) const {
  Position nextPosition = position + direction;
  if (warehouse[nextPosition] == WALL) {
    return false;
  }
  if (warehouse[nextPosition] == BOX) {
    return canMove(nextPosition, direction, warehouse);
  }
  if (warehouse[nextPosition] == LEFT_BOX || warehouse[nextPosition] == RIGHT_BOX) {
    if (direction == Direction::DIRECTIONS[Direction::UP] || direction == Direction::DIRECTIONS[Direction::DOWN]) {
      Position adjacentPosition =
          nextPosition + (warehouse[nextPosition] == LEFT_BOX ? Direction::DIRECTIONS[Direction::RIGHT]
                                                              : Direction::DIRECTIONS[Direction::LEFT]);
      return canMove(adjacentPosition, direction, warehouse) && canMove(nextPosition, direction, warehouse);
    } else {
      // Boxes are twice as wide!
      Position nextNextPosition = nextPosition + direction;
      return canMove(nextNextPosition, direction, warehouse);
    }
  }
  if (warehouse[nextPosition] == SPACE) {
    return true;
  }
  throw std::runtime_error("Invalid flow!");
}
