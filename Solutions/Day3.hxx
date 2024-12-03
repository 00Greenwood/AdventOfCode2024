#pragma once
#include <Day.hxx>

class Day3 : public Day {
public:
  explicit Day3();
  virtual ~Day3();

protected:
  std::string solve(Part) const override;
};
