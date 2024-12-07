#include <Position.hxx>

bool Position::operator==(const Position& other) const {
  return x == other.x && y == other.y;
}

Position& Position::operator+=(const Position& other) {
  x += other.x;
  y += other.y;
  return *this;
}

Position& Position::operator-=(const Position& other) {
  x -= other.x;
  y -= other.y;
  return *this;
}

bool Position::operator<(const Position& other) const {
  if (x == other.x) {
    return y < other.y;
  }
  return x < other.x;
}