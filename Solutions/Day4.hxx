#pragma once
#include <Day.hxx>

#include <vector>

class Day4 : public Day {
public:
  explicit Day4();
  virtual ~Day4();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::vector<char>> m_input;
};
