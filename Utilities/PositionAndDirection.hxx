#pragma once

#include <Direction.hxx>
#include <Position.hxx>

struct PositionAndDirection {
  Position position;
  Direction direction;

  bool operator==(const PositionAndDirection&) const;
};