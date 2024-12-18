#pragma once

class Day15 : public Day {
public:
  explicit Day15();
  virtual ~Day15();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  enum Tile {
    SPACE,
    ROBOT,
    BOX,
    WALL,
    LEFT_BOX,
    RIGHT_BOX,
  };

  void move(const Position& position, const Position& direction, std::map<Position, Tile>& warehouse) const;

  bool canMove(const Position& position, const Position& direction, std::map<Position, Tile>& warehouse) const;

  std::vector<std::vector<char>> m_input;
};
