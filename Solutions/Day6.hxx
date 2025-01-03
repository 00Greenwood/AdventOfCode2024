#pragma once

class Day6 : public Day {
public:
  explicit Day6();
  virtual ~Day6();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::vector<char>> m_input;
  Position m_start;

  std::set<Position> m_walls;
};
