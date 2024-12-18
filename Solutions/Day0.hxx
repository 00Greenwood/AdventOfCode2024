#pragma once

class Day0 : public Day {
public:
  explicit Day0();
  virtual ~Day0();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  int m_input;
};
