#pragma once

#include <Direction.hxx>
#include <Position.hxx>

struct PositionAndDirection {
  Position position;
  Direction::Type direction;

  bool operator==(const PositionAndDirection&) const;

  bool operator<(const PositionAndDirection& other) const;
};