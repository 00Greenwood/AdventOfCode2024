#pragma once

class Day18 : public Day {
public:
  explicit Day18();
  virtual ~Day18();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::vector<int>> m_input;
  std::vector<Position> m_bytes;
};
