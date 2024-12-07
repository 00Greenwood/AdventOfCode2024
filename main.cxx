#include <Days.hxx>

#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char** argv) {
  std::vector<std::unique_ptr<Day>> days;
  days.push_back(std::make_unique<Day0>());
  days.push_back(std::make_unique<Day1>());
  days.push_back(std::make_unique<Day2>());
  days.push_back(std::make_unique<Day3>());
  days.push_back(std::make_unique<Day4>());
  days.push_back(std::make_unique<Day5>());
  days.push_back(std::make_unique<Day6>());

  for (const auto& day : days) {
    day->solve();
  }

  for (const auto& day : days) {
    try {
      std::cout << day->solution() << std::endl;
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return 0;
}
