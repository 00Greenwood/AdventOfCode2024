#include <Day0.hxx>
#include <parse.hxx>

Day0::Day0() : Day(0) {
}

std::string Day0::solve(Part part) const {
  return std::to_string(parse<int>(name()));
}
