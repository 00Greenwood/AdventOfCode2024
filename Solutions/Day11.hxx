#pragma once
#include <Day.hxx>
#include <list>

class Day11 : public Day {
public:
  explicit Day11();
  virtual ~Day11();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::list<size_t> m_input;
};
