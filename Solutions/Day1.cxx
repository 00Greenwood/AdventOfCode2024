#include <Day1.hxx>
#include <parse.hxx>

Day1::Day1() : Day(1) {
}

std::string Day1::solve(Part part) const {
  return std::to_string(parse<int>(name()));
}
