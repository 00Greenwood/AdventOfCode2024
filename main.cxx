#include <Day0.hxx>
#include <Day1.hxx>

#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char** argv) {
  std::vector<std::unique_ptr<Day>> days;
  days.push_back(std::make_unique<Day0>());
  days.push_back(std::make_unique<Day1>());

  for (const auto& day : days) {
    std::cout << day->solution() << std::endl;
  }

  return 0;
}
