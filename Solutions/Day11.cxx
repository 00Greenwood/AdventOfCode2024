#include <Day11.hxx>
#include <parse.hxx>

#include <map>

Day11::Day11() : Day(11) {
}

Day11::~Day11() {
}

void Day11::initialize() {
  parse(name(), m_input);
}

#include <iostream>
#include <sstream>

std::string Day11::solve(Part part) const {
  std::map<std::pair<int, size_t>, size_t> cache;
  int blinks = part == PART_1 ? 25 : 75;
  size_t total = 0;
  for (const auto& stone : m_input) {
    total += blink(stone, blinks, cache);
  }
  return std::to_string(total);
}

size_t Day11::blink(size_t stone, int index, std::map<std::pair<int, size_t>, size_t>& cache) const {
  if (index == 0) {
    return 1;
  }

  // Already calculated.
  if (cache.count({index, stone}) > 0) {
    return cache[{index, stone}];
  }

  if (stone == 0) {
    size_t stones = blink(1, index - 1, cache);
    cache[{index, stone}] = stones;
    return stones;
  }

  std::string str = std::to_string(stone);
  if (str.size() % 2 == 0) {
    size_t first = std::stoul(str.substr(0, str.size() / 2));
    size_t stones = blink(first, index - 1, cache);
    size_t second = std::stoul(str.substr(str.size() / 2));
    stones += blink(second, index - 1, cache);
    cache[{index, stone}] = stones;
    return stones;
  }

  size_t stones = blink(stone * 2024, index - 1, cache);
  cache[{index, stone}] = stones;
  return stones;
}