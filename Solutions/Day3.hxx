#pragma once
#include <Day.hxx>

class Day3 : public Day {
public:
  explicit Day3();
  virtual ~Day3();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::string m_input;
};
