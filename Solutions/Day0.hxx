#pragma once
#include <Day.hxx>

class Day0 : public Day {
public:
  explicit Day0();
  virtual ~Day0();

protected:
  std::string solve(Part) const override;
};
