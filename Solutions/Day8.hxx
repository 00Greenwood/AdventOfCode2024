#pragma once
#include <Day.hxx>
#include <Position.hxx>

#include <map>
#include <vector>

class Day8 : public Day {
public:
  explicit Day8();
  virtual ~Day8();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::vector<char>> m_input;
  std::map<char, std::vector<Position>> m_antenna;
  int m_width;
  int m_height;
};
