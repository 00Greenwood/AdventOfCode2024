#include <Day1.hxx>
#include <parse.hxx>

#include <algorithm>
#include <map>

Day1::Day1() : Day(1) {
}

Day1::~Day1() {
}

std::string Day1::solve(Part part) const {
  auto [first, second] = parse<std::pair<std::vector<int>, std::vector<int>>>(name());
  if (part == Day::PART_1) {
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
    int difference = 0;
    for (int i = 0; i < first.size(); ++i) {
      difference += std::abs(first.at(i) - second.at(i));
    }
    return std::to_string(difference);
  } else {
    std::map<int, int> occurences;
    for (const auto& number : first) {
      if (occurences.count(number) > 0) {
        occurences.at(number)++;
      } else {
        occurences.insert({number, 1});
      }
    }
    int score = 0;
    for (const auto& number : second) {
      if (occurences.count(number) > 0) {
        score += occurences.at(number) * number;
      }
    }
    return std::to_string(score);
  }
}
