#pragma once

class Day13 : public Day {
public:
  explicit Day13();
  virtual ~Day13();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  struct ClawMachine {
    std::pair<int64_t, int64_t> a;
    std::pair<int64_t, int64_t> b;
    std::pair<int64_t, int64_t> p;
  };

  std::vector<int64_t> m_input;
  std::vector<ClawMachine> m_machines;
};
