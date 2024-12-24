#include "precompiled.hxx"

int main(int, char**) {
  auto mutex = std::make_shared<std::mutex>();

  std::vector<std::unique_ptr<Day>> days;
  days.push_back(std::make_unique<Day0>());
  days.push_back(std::make_unique<Day1>());
  days.push_back(std::make_unique<Day2>());
  days.push_back(std::make_unique<Day3>());
  days.push_back(std::make_unique<Day4>());
  days.push_back(std::make_unique<Day5>());
  days.push_back(std::make_unique<Day6>());
  days.push_back(std::make_unique<Day7>());
  days.push_back(std::make_unique<Day8>());
  days.push_back(std::make_unique<Day9>());
  days.push_back(std::make_unique<Day10>());
  days.push_back(std::make_unique<Day11>());
  days.push_back(std::make_unique<Day12>());
  days.push_back(std::make_unique<Day13>());
  days.push_back(std::make_unique<Day14>());
  days.push_back(std::make_unique<Day15>());
  days.push_back(std::make_unique<Day16>());
  days.push_back(std::make_unique<Day17>());
  days.push_back(std::make_unique<Day18>());
  days.push_back(std::make_unique<Day19>());
  days.push_back(std::make_unique<Day20>());
  days.push_back(std::make_unique<Day21>());
  days.push_back(std::make_unique<Day22>());
  days.push_back(std::make_unique<Day23>());
  days.push_back(std::make_unique<Day24>());

  for (const auto& day : days) {
    day->solve(mutex);
  }

  for (const auto& day : days) {
    day->wait();
  }

  return 0;
}
