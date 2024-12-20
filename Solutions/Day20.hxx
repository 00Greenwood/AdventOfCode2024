#pragma once

class Day20 : public Day {
public:
  explicit Day20();
  virtual ~Day20();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  using Path = std::vector<Position>;

  Path solveMaze() const;

  std::vector<std::vector<char>> m_input;

  enum Tile { WALL = '#', SPACE = '.', START = 'S', END = 'E' };

  std::map<Position, Tile> m_maze;
  Position m_start;
  Position m_end;
};
