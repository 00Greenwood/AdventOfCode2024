#pragma once

class Day5 : public Day {
public:
  explicit Day5();
  virtual ~Day5();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::pair<int, int>> m_orderings;
  std::vector<std::vector<int>> m_manuals;
};
