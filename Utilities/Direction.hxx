#pragma once

#include <Position.hxx>
#include <map>

enum Direction { UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };

static Position DIRECTIONS[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

static std::map<Position, Direction> REVERSE_DIRECTIONS = {
    {{0, -1}, UP}, {{1, 0}, RIGHT}, {{0, 1}, DOWN}, {{-1, 0}, LEFT}};
