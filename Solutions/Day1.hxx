#pragma once

class Day1 : public Day {
public:
  explicit Day1();
  virtual ~Day1();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::pair<std::vector<int>, std::vector<int>> m_input;
};
