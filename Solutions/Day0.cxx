#include <Day0.hxx>
#include <parse.hxx>

Day0::Day0() : Day(0) {
}

Day0::~Day0() {
}

std::string Day0::solve(Part part) const {
  int input;
  parse(name(), input);
  return std::to_string(input);
}
