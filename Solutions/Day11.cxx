#include <Day11.hxx>
#include <parse.hxx>

Day11::Day11() : Day(11) {
}

Day11::~Day11() {
}

void Day11::initialize() {
  parse(name(), m_input);
}

std::string Day11::solve(Part part) const {
  std::list<size_t> stones = m_input;
  int blinks = part == PART_1 ? 25 : 75;
  for (int i = 0; i < blinks; ++i) {
    auto it = stones.begin();
    while (it != stones.end()) {
      if (*it == 0) {
        *it = 1;
        it++;
        continue;
      }
      std::string str = std::to_string(*it);
      if (str.size() % 2 == 0) {
        size_t first = std::stoul(str.substr(0, str.size() / 2));
        size_t second = std::stoul(str.substr(str.size() / 2));
        *it = first;
        it++;
        it = stones.insert(it, second);
        it++;
        continue;
      }
      *it = *it * 2024;
      it++;
    }
  }
  return std::to_string(stones.size());
}
