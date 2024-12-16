#include <PositionAndDirection.hxx>

bool PositionAndDirection::operator==(const PositionAndDirection& other) const {
  return position == other.position && direction == other.direction;
}

bool PositionAndDirection::operator<(const PositionAndDirection& other) const {
  if (position == other.position) {
    return direction < other.direction;
  }
  return position < other.position;
}
