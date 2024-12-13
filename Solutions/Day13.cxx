#include <Day13.hxx>
#include <parse.hxx>

Day13::Day13() : Day(13) {
}

Day13::~Day13() {
}

void Day13::initialize() {
  parse(name(), m_input);
}

std::string Day13::solve(Part part) const {
  return std::to_string(m_input);
}
