#include <Day4.hxx>
#include <parse.hxx>

#include <regex>

Day4::Day4() : Day(4) {
}

Day4::~Day4() {
}

std::string Day4::solve(Part part) const {
  std::vector<std::vector<char>> input;
  parse(name(), input);

  // Check the index is with the input.
  auto checkIndex = [&input](int i, int j) -> bool {
    return i >= 0 && j >= 0 && i < input.size() && j < input.at(0).size();
  };

  auto check = [&input, &checkIndex](int i, int j, char ch) -> bool {
    return checkIndex(i, j) && input.at(i).at(j) == ch;
  };

  std::vector<std::pair<int, int>> adjacent{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
  std::vector<std::pair<int, int>> diagonals{{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

  // Check surrounding letters for M then A & S.
  auto checkMAS = [&input, &check, &adjacent](int i, int j) -> int {
    int total = 0;
    for (const auto& [x, y] : adjacent) {
      // Check for M is all directions.
      if (check(i + x, j + y, 'M')) {
        // Check for A the same direction.
        if (check(i + 2 * x, j + 2 * y, 'A')) {
          // Check for S the same direction.
          if (check(i + 3 * x, j + 3 * y, 'S')) {
            total++;
          }
        }
      }
    }
    return total;
  };

  // Check surrounding letters for A & S and M & S in a cross.
  auto checkASMS = [&input, &check, &diagonals](int i, int j) -> int {
    int total = 0;
    for (const auto& [x, y] : diagonals) {
      // Check for A in the corners.
      if (check(i + x, j + y, 'A')) {
        // Check for S the same direction.
        if (check(i + 2 * x, j + 2 * y, 'S')) {
          // Check for M in the first perpendicular direction.
          if (check(i, j + 2 * y, 'M')) {
            // Check for S in the second perpendicular direction.
            if (check(i + 2 * x, j, 'S')) {
              total++;
            }
          }
          // Check for S in the first perpendicular direction.
          else if (check(i, j + 2 * y, 'S')) {
            // Check for M in the second perpendicular direction.
            if (check(i + 2 * x, j, 'M')) {
              total++;
            }
          }
        }
      }
    }
    return total;
  };

  int total = 0;
  for (int i = 0; i < input.size(); ++i) {
    for (int j = 0; j < input.at(i).size(); ++j) {
      if (part == PART_1 && input.at(i).at(j) == 'X') {
        total += checkMAS(i, j);
      } else if (part == PART_2 && input.at(i).at(j) == 'M') {
        total += checkASMS(i, j);
      }
    }
  }
  if (part == PART_2) {
    // For part 2, we have counted every X-MAS twice.
    total /= 2;
  }

  return std::to_string(total);
}
