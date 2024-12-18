#pragma once

class Day17 : public Day {
public:
  explicit Day17();
  virtual ~Day17();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  struct Computer {
    size_t a;
    size_t b;
    size_t c;
    size_t pointer = 0;
    std::vector<size_t> instructions;
    std::vector<size_t> output;
  };

  void run(size_t opcode, size_t operand, Computer& computer) const;

  size_t convert(size_t operand, const Computer& computer) const;

  std::list<size_t> m_input;
  Computer m_computer;
};
