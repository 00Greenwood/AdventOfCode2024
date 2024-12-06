#include "Position.hxx"

#include <functional>

  bool Position::operator == (const Position& other) const {
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

size_t PositionHash::operator()(const Position& position) const {
  auto hash1 = std::hash<int>{}(position.x);
  auto hash2 = std::hash<int>{}(position.y);
  return hash1 ^ (hash2 << 1);
}

bool PositionAndDirection::operator==(const PositionAndDirection& other) const {
  return position == other.position && direction == other.direction;
}

size_t PositionAndDirectionHash::operator()(const PositionAndDirection& positionAndDirection) const {
  auto hash1 = std::hash<int>{}(positionAndDirection.position.x);
  auto hash2 = std::hash<int>{}(positionAndDirection.position.y);
  auto hash3 = std::hash<int>{}(positionAndDirection.direction);
  return hash1 ^ (hash2 << 1) ^ (hash3 << 2);
}
