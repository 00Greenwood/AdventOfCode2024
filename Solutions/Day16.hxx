#pragma once
#include <Day.hxx>
#include <Position.hxx>
#include <Direction.hxx>

#include <vector>
#include <map>

class Day16 : public Day {
public:
  explicit Day16();
  virtual ~Day16();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::vector<char>> m_input;

  enum Tile { WALL, EMPTY, START, END };

  std::map<Position, Tile> m_maze;
  Position m_start;
  Position m_end;
};
