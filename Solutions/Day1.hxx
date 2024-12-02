#pragma once
#include <Day.hxx>

class Day1 : public Day {
public:
  explicit Day1();
  virtual ~Day1();

  std::string solve(Part) const override;
};
