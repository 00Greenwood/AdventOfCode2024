#pragma once
#include <Day.hxx>

#include <vector>

class Day2 : public Day {
public:
  explicit Day2();
  virtual ~Day2();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  bool isReportSafe(const std::vector<int>& report) const;

  std::vector<std::vector<int>> m_input;
};
