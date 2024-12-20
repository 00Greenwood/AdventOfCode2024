#pragma once

#include <Position.hxx>
#include <map>

class Direction {
public:
  enum Type { UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };

  static const Position DIRECTIONS[4];
  static const std::map<Position, Type> REVERSE_DIRECTIONS;

  static Type turn90(Type direction);

  static Type turn270(Type direction);

  static Type turn180(Type direction);

private:
  Direction() = delete;
  ~Direction() = delete;
};
