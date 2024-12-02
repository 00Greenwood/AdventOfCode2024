#pragma once
#include <Day.hxx>

#include <vector>

class Day2 : public Day {
public:
  explicit Day2();
  virtual ~Day2();

  std::string solve(Part) const override;

private:
  bool isReportSafe(const std::vector<int>& report) const;
};
