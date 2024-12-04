#pragma once
#include <Day.hxx>

class Day4 : public Day {
public:
  explicit Day4();
  virtual ~Day4();

protected:
  std::string solve(Part) const override;
};
