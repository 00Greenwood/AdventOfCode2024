#include <Direction.hxx>

const Position Direction::DIRECTIONS[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

const std::map<Position, Direction::Type> Direction::REVERSE_DIRECTIONS = {
    {{0, -1}, UP}, {{1, 0}, RIGHT}, {{0, 1}, DOWN}, {{-1, 0}, LEFT}};

Direction::Type Direction::turn90(Type direction) {
  return static_cast<Type>((direction + 1) % 4);
}

Direction::Type Direction::turn270(Type direction) {
  return static_cast<Type>((direction + 3) % 4);
}

Direction::Type Direction::turn180(Type direction) {
  return static_cast<Type>((direction + 2) % 4);
}