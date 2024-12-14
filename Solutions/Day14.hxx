#pragma once
#include <Day.hxx>

#include <Position.hxx>

class Day14 : public Day {
public:
  explicit Day14();
  virtual ~Day14();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::vector<int>> m_input;

  struct Robot {
    Position position;
    Position velocity;
  };
  std::vector<Robot> m_robots;
};
