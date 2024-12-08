#pragma once
#include <Day.hxx>

#include <vector>

class Day8 : public Day {
public:
  explicit Day8();
  virtual ~Day8();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::vector<size_t>> m_input;
};
