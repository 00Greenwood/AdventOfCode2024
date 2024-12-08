#include <Day8.hxx>
#include <parse.hxx>

Day8::Day8() : Day(8) {
}

Day8::~Day8() {
}

void Day8::initialize() {
  parse(name(), m_input);
}

std::string Day8::solve(Part part) const {
  return std::to_string(0);
}
