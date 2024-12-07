#pragma once

struct Position {
  int x;
  int y;

  bool operator==(const Position&) const;

  Position& operator+=(const Position&);
  Position& operator-=(const Position&);

  bool operator<(const Position& other) const;
};
