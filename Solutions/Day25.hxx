#pragma once

class Day25 : public Day {
public:
  explicit Day25();
  virtual ~Day25();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::string> m_input;

  std::vector<std::vector<int>> m_keys;
  std::vector<std::vector<int>> m_locks;
};
