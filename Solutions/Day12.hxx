#pragma once
#include <Day.hxx>
#include <Position.hxx>

#include <vector>

class Day12 : public Day {
public:
  explicit Day12();
  virtual ~Day12();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::vector<char>> m_input;
};
