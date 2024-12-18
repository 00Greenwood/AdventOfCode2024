#include "precompiled.hxx"

Day13::Day13() : Day(13) {
}

Day13::~Day13() {
}

void Day13::initialize() {
  parse(name(), m_input);
  auto it = m_input.begin();
  while (it != m_input.end()) {
    ClawMachine machine({*it++, *it++}, {*it++, *it++}, {*it++, *it++});
    m_machines.push_back(machine);
  }
}

std::string Day13::solve(Part part) const {
  size_t tokens = 0;
  for (auto& machine : m_machines) {
    int64_t firstPrize = machine.p.first;
    int64_t secondPrize = machine.p.second;

    if (part == PART_2) {
      firstPrize += 10000000000000;
      secondPrize += 10000000000000;
    }

    // Cramer's rule!
    int64_t d = (machine.a.first * machine.b.second) - (machine.b.first * machine.a.second);
    int64_t dx = (firstPrize * machine.b.second) - (machine.b.first * secondPrize);
    int64_t dy = (machine.a.first * secondPrize) - (firstPrize * machine.a.second);
    if (dx % d == 0 && dy % d == 0) {
      int64_t x = dx / d;
      int64_t y = dy / d;
      tokens += 3 * x + y;
    }
  }

  return std::to_string(tokens);
}
