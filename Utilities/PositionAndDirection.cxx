#include <PositionAndDirection.hxx>

bool PositionAndDirection::operator==(const PositionAndDirection& other) const {
  return position == other.position && direction == other.direction;
}
