#pragma once

class Day24 : public Day {
public:
  explicit Day24();
  virtual ~Day24();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  enum Operation {
    AND,
    OR,
    XOR,
    TRUE,
    FALSE,
  };

  struct Gate {
    std::string inputOne;
    std::string inputTwo;
    Operation operation;
    std::string output;
  };

  bool run(const Gate& gate, std::map<std::string, bool>& outputs) const;

  std::vector<std::string> m_input;
  std::map<std::string, Gate> m_gates;
};
