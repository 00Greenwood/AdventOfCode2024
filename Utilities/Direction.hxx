#pragma once

#include <Position.hxx>

enum Direction { UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };

static Position DIRECTIONS[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};