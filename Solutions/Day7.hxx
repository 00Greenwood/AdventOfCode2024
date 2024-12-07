#pragma once
#include <Day.hxx>
#include <Position.hxx>

#include <set>
#include <vector>

class Day7 : public Day {
public:
  explicit Day7();
  virtual ~Day7();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  bool validEquation(const std::vector<size_t>& equation, int index, size_t total) const;

  std::vector<std::vector<size_t>> m_input;
};
