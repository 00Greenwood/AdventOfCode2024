#include "precompiled.hxx"

Day17::Day17() : Day(17) {
}

Day17::~Day17() {
}

void Day17::initialize() {
  parse(name(), m_input);

  auto it = m_input.begin();
  m_computer.a = *it++;
  m_computer.b = *it++;
  m_computer.c = *it++;
  while (it != m_input.end()) {
    m_computer.instructions.push_back(*it++);
  }
}

std::string Day17::solve(Part part) const {
  if (part == PART_1) {
    Computer computer = m_computer;

    while (true) {
      if (computer.pointer >= computer.instructions.size()) {
        break;
      }
      size_t opcode = computer.instructions.at(computer.pointer++);
      size_t operand = computer.instructions.at(computer.pointer++);
      run(opcode, operand, computer);
    }

    std::stringstream ss;
    for (const auto& output : computer.output) {
      ss << output << ',';
    }
    return ss.str();
  }

  std::set<size_t> inputs = {0};
  for (const auto& instruction : std::views::reverse(m_computer.instructions)) {
    std::set<size_t> outputs;
    for (const auto& input : inputs) {
      for (size_t start = 0; start < 8; start++) {
        Computer computer = m_computer;
        computer.a = (input * 8) + start;
        while (true) {
          if (computer.pointer >= computer.instructions.size()) {
            break;
          }
          size_t opcode = computer.instructions.at(computer.pointer++);
          size_t operand = computer.instructions.at(computer.pointer++);
          if (opcode == 0) {
            break;
          }
          run(opcode, operand, computer);
        }

        if (computer.b % 8 == instruction) {
          outputs.insert(computer.a);
        }
      }
    }
    inputs = outputs;
  }
  return std::to_string(*inputs.begin());
}

void Day17::run(size_t opcode, size_t operand, Computer& computer) const {
  switch (opcode) {
  case 0:
    computer.a = computer.a / pow(2, convert(operand, computer));
    break;
  case 1:
    computer.b = computer.b ^ operand;
    break;
  case 2:
    computer.b = convert(operand, computer) % 8;
    break;
  case 3:
    if (computer.a != 0) {
      computer.pointer = operand;
    }
    break;
  case 4:
    computer.b = computer.b ^ computer.c;
    break;
  case 5:
    computer.output.push_back(convert(operand, computer) % 8);
    break;
  case 6:
    computer.b = computer.a / pow(2, convert(operand, computer));
    break;
  case 7:
    computer.c = computer.a / pow(2, convert(operand, computer));
    break;
  default:
    throw std::runtime_error("Invalid opcode: " + std::to_string(opcode));
  }
}

size_t Day17::convert(size_t operand, const Computer& computer) const {
  switch (operand) {
  case 0:
  case 1:
  case 2:
  case 3:
    return operand;
  case 4:
    return computer.a;
  case 5:
    return computer.b;
  case 6:
    return computer.c;
  default:
    throw std::runtime_error("Invalid operand: " + std::to_string(operand));
  }
}
