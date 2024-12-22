#pragma once

#include <cmath>

struct Position {
  int x;
  int y;

  bool operator==(const Position&) const;

  Position& operator+=(const Position&);
  Position& operator-=(const Position&);

  Position operator+(const Position& other) const;
  Position operator-(const Position& other) const;

  Position operator*(const Position& other) const;
  Position operator%(const Position& other) const;

  bool operator<(const Position& other) const;
};
