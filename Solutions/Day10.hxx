#pragma once
#include <Day.hxx>
#include <Position.hxx>

#include <map>
#include <set>
#include <vector>

class Day10 : public Day {
public:
  explicit Day10();
  virtual ~Day10();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  int checkTrail(const Position& position, std::set<Position>& peaks) const;

  std::vector<std::vector<char>> m_input;

  std::map<Position, int> m_map;
  std::vector<Position> m_trailheads;
};
