#pragma once
#include <Day.hxx>

#include <vector>

class Day9 : public Day {
public:
  explicit Day9();
  virtual ~Day9();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<int> m_input;
};
