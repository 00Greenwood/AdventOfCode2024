#pragma once

class Day4 : public Day {
public:
  explicit Day4();
  virtual ~Day4();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::vector<char>> m_input;
};
