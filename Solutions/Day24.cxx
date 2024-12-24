#include "precompiled.hxx"
#include <Day24.hxx>

Day24::Day24() : Day(24) {
}

Day24::~Day24() {
}

void Day24::initialize() {
  parse(name(), m_input);

  bool afterBreak = false;
  for (const auto& line : m_input) {
    if (line.empty()) {
      afterBreak = true;
      continue;
    }
    if (afterBreak) {
      size_t firstSpace = line.find(' ');
      std::string inputOne = line.substr(0, firstSpace);
      size_t secondSpace = line.find(' ', firstSpace + 1);
      std::string operationStr = line.substr(firstSpace + 1, secondSpace - firstSpace - 1);
      Operation operation = operationStr == "AND" ? AND : operationStr == "OR" ? OR : XOR;
      size_t arrow = line.find(" -> ");
      std::string inputTwo = line.substr(arrow - 3, 3);
      std::string output = line.substr(arrow + 4);
      Gate gate{inputOne, inputTwo, operation, output};
      m_gates[output] = gate;
    } else {
      std::string wire = line.substr(0, line.find(':'));
      Operation op = line.substr(line.find(' ') + 1) == "1" ? TRUE : FALSE;
      Gate gate{.operation = op, .output = wire};
      m_gates[wire] = gate;
    }
  }
}

std::string Day24::solve(Part part) const {
  if (part == PART_1) {
    std::map<std::string, bool> outputs;
    for (const auto& [output, gate] : m_gates) {
      if (!outputs.contains(gate.output)) {
        outputs[gate.output] = run(gate, outputs);
      }
    }

    size_t total = 0;
    for (const auto& [wire, output] : outputs) {
      if (wire.starts_with('z') && output) {
        size_t power = std::stoi(wire.substr(1));
        total += static_cast<size_t>(pow(2, power));
      }
    }
    return std::to_string(total);
  }

  std::map<std::string, Gate> gates = m_gates;
  std::set<std::pair<std::string, std::string>> swaps;
  swaps.insert({"z35", "hqk"});
  swaps.insert({"z06", "fhc"});
  swaps.insert({"z11", "qhj"});
  swaps.insert({"ggt", "mwh"});

  for (const auto& [first, second] : swaps) {
    std::string swap = first;
    gates[second].output = first;
    gates[swap].output = second;
  }

  std::ofstream out("Day24.gv");
  out << "digraph Day24 {\n";

  for (const auto& [_, gate] : gates) {
    out << "\t" << gate.output << " [label=" << gate.output << "]\n";
    switch (gate.operation) {
    case AND:
      out << "\t" << gate.inputOne << " -> " << gate.output << " [label=AND]\n";
      out << "\t" << gate.inputTwo << " -> " << gate.output << " [label=AND]\n";
      break;
    case OR:
      out << "\t" << gate.inputOne << " -> " << gate.output << " [label=OR]\n";
      out << "\t" << gate.inputTwo << " -> " << gate.output << " [label=OR]\n";
      break;
    case XOR:
      out << "\t" << gate.inputOne << " -> " << gate.output << " [label=XOR]\n";
      out << "\t" << gate.inputTwo << " -> " << gate.output << " [label=XOR]\n";
      break;
    }
  }
  out << "}\n";

  std::set<std::string> swapped;
  for (const auto& [first, second] : swaps) {
    swapped.insert(first);
    swapped.insert(second);
  }

  std::stringstream ss;
  for (const auto& swap : swapped) {
    ss << swap << ",";
  }

  return ss.str();
}

bool Day24::run(const Gate& gate, std::map<std::string, bool>& outputs) const {
  if (!gate.inputOne.empty() && !outputs.contains(gate.inputOne)) {
    outputs[gate.inputOne] = run(m_gates.at(gate.inputOne), outputs);
  }
  if (!gate.inputTwo.empty() && !outputs.contains(gate.inputTwo)) {
    outputs[gate.inputTwo] = run(m_gates.at(gate.inputTwo), outputs);
  }

  switch (gate.operation) {
  case TRUE:
    return true;
  case FALSE:
    return false;
  case AND:
    return outputs.at(gate.inputOne) && outputs.at(gate.inputTwo);
  case OR:
    return outputs.at(gate.inputOne) || outputs.at(gate.inputTwo);
  case XOR:
    return outputs.at(gate.inputOne) != outputs.at(gate.inputTwo);
  }
  throw std::runtime_error("Invalid operation!");
}
