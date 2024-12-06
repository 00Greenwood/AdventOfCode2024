#pragma once

#include <cstddef>

struct Position {
  int x;
  int y;

  bool operator==(const Position&) const;

  Position& operator+=(const Position&);
  Position& operator-=(const Position&);
};

struct PositionHash {
  size_t operator()(const Position&) const;
};

struct PositionAndDirection {
  Position position;
  int direction;

  bool operator==(const PositionAndDirection&) const;
};

struct PositionAndDirectionHash {
  size_t operator()(const PositionAndDirection&) const;
};