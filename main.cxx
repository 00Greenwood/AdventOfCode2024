#include <Days.hxx>

#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

int main(int argc, char** argv) {
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

  for (const auto& day : days) {
    day->solve(mutex);
  }

  for (const auto& day : days) {
    day->wait();
  }

  return 0;
}
