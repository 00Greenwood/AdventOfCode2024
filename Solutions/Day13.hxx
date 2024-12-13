#pragma once
#include <Day.hxx>

class Day13 : public Day {
public:
  explicit Day13();
  virtual ~Day13();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  int m_input;
};
