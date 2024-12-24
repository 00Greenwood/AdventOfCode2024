#pragma once

class Day21 : public Day {
public:
  explicit Day21();
  virtual ~Day21();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  using Cache = std::map<size_t, std::map<std::string, std::string>>;

  std::string move(size_t depth, const std::string& input, Cache& cache) const;
  std::set<std::string> move(char start, char end) const;

  std::vector<std::string> m_input;

  std::map<char, Position> m_numberKeypad;
  std::map<char, Position> m_directionKeypad;
};
